#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep3(i,N) for(int i = N - 1; i >= 0; i--)
#define rep4(i,N) for(int i = N; i > 0; i--)
#define replr(i,l,r) for(int i = l; i < r; i++)
#define reprl(i,l,r) for(int i = l; i >= r; i--)
#define all(x) x.begin(),x.end() 
#define allr(x) x.rbegin(),x.rend() 
using ll = long long;
using P = pair<int,int>;
using TP = tuple<int,int,int>;
void chmin(int &x, int y){ x = min(x,y); }
void chmax(int &x, int y){ x = max(x,y); }
int main(){
  //n:じゃがいもの重さの配列wの1周期の長さ
  //q:クエリ数,x:箱に蓋をする重さの条件
  int n, q, x;
  cin >> n >> q >> x;
  //s:一周期のジャガイモの重さの合計(0初期化)
  ll all = 0;
  //w[i]:1周期のi番目のじゃがいもの重さ(尺取法を簡潔にするためにw(n)+w(n)をする)
  vector<int> w(2*n);
  rep(i,n){
    cin >> w[i];
    //合計を計算
    all += w[i];
    //w(n)+w(n)の処理(同じものを後ろにつなげる)
    w[i+n] = w[i];
  }
  //cnt[i]:i番目のじゃがいもから箱に詰めた時にその箱に何個じゃがいもを詰められるか
  //初期化は別解のna=(rd=x/s)*nで行う
  vector<int> cnt(n,(x/all)*n);
  //xを別解のremにする
  x %= all;
  //尺取法O(N)
  //i:何番目のじゃがいもから箱に詰めるか
  //j:尺取法で見ているじゃがいもの位置のカーソル
  //s:箱に詰めるじゃがいもの総重量
  for(int i = 0, j = 0, s = 0; i < n; i++){
    //バグってカーソルの位置関係が逆転した時の応急処置(今回はそのパターンがない)
    /*if(j < i){
      j = i;
      s = 0;
    }*/
    //箱に入れられる残りの重量が許す限り処理
    while(s < x){
      //重量にj番目のじゃがいもの重さを加算
      s += w[j];
      //尺取法で見ているカーソルを移動
      //(while文を抜ける頃に今の箱でない次の箱に一番最初に入れるじゃがいものindexを指すようになる)
      j++;
    }
    //i番目のじゃがいもから箱に入れた場合の箱の中のじゃがいもの数がna+[i,j)の区間の数となったので
    //区間の数j-iをnaに加算し、それをi番目のじゃがいもから箱に入れた場合の箱の中のじゃがいもの数とする
    cnt[i] += j - i;
    //i+1番目(次)のじゃがいもから考えるので範囲外となったi番目のじゃがいもの重さを
    //箱に入れる重量からひく
    s -= w[i];
  }
  //order[i]:頂点iに1回も訪れていないなら-1,訪れたなら何回の遷移で訪れられるかを格納
  //path:最初のサイクルになっていない頂点数個(0の場合あり)とサイクルの頂点を辿る順番に格納する配列
  vector<int> order(n,-1), path;
  //loop:サイクルの頂点数(まだ見つかっていないので適当な値で初期化)
  int loop = -1;
  //グラフの探索
  //u:見ている頂点,k:遷移数
  for(int u = 0, k = 0; ; k++){
    //すでにuに訪れている場合(サイクル発見時)に処理
    if(order[u] != -1){
      //2回目の到着がk回の遷移、1回目の到着がorder[u]回の遷移なので
      //引いたものがサイクルの頂点数になる
      loop = k - order[u];
      //サイクルが見つかり、何回目の遷移でどこの頂点にいるかが確定したので終了
      break;
    }
    //初めてuにk回の遷移で訪れたのでorderの更新
    order[u] = k;
    //訪れた頂点をpathに格納
    path.push_back(u);
    //次の箱の最初のじゃがいものindex(グラフの有向辺の向かう先)を計算
    u = (u + cnt[u]) % n;
  }
  //non_loop:最初の方のサイクルの範囲外の頂点の個数
  int non_loop = path.size() - loop;
  //クエリ処理
  rep(_,q){
    //箱の番号
    ll k;
    cin >> k;
    //求めたいのはk番目の箱の先頭の頂点なのでk-1回の遷移でk番目の箱の先頭の頂点を得るために-1する必要がある
    k--;
    //遷移回数kで頂点がサイクルに突入しない場合に処理
    if(k < non_loop){
      //k-1回で行ける遷移先のindexのじゃがいもから箱に詰めた時のその箱の個数を出力
      printf("%d\n",cnt[path[k]]);
    }else {
      //遷移回数kで頂点がサイクルに突入する場合に処理
      //kから最初の方のサイクルの範囲外の頂点の個数を引くと
      //kがサイクルの開始点からサイクル内を何回遷移するかに変わる
      //kがサイクルを完全に一周するのを全て無視した時何回サイクルを遷移するかを求めkに格納する
      k = (k - non_loop) % loop;
      //path[non_loop+k]で最終的にk-1回の遷移で向かうじゃがいものindexを得る
      //そのindexのじゃがいもから箱に詰めた時の何個箱に入れられるかがcnt配列に格納されているのでそれを出力
      printf("%d\n",cnt[path[non_loop + k]]);
    }
  }
  return 0;
}
//O(N+Q)解法
