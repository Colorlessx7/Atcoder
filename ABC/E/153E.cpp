#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(ll i = 0; i < N; i++)
#define rep2(i,N) for(ll i = 1; i <= N; i++)
#define rep3(i,N) for(ll i = N - 1; i >= 0; i--)
#define rep4(i,N) for(ll i = N; i > 0; i--)
#define replr(i,l,r) for(ll i = l; i < r; i++)
#define reprl(i,l,r) for(ll i = l; i >= r; i--)
#define all(x) x.begin(),x.end() 
#define allr(x) x.rbegin(),x.rend() 
using ll = long long;
using P = pair<ll,ll>;
void chmin(ll &x, ll y){ x = min(x,y); }
void chmax(ll &x, ll y){ x = max(x,y); }
int main(){
  //h:モンスターの体力,n:魔法の種類数
  ll h, n;
  cin >> h >> n;
  const ll INF = 1001001001;
  //dp[i]:体力hのモンスターから体力をi削るのに必要な魔法のコストの最小値(初期状態はi=0のみ0,他無限)
  vector<ll> dp(h+1,INF);
  dp[0] = 0;
  //魔法一つずつについてdpに適用していく
  rep(i,n){
    //a:魔法のダメージ,b:魔法のコスト
    //(以降で使わないので配列に入力せず直接使う)
    ll a, b;
    cin >> a >> b;
    //dpの遷移について処理
    rep(j,h){
      //nj:dpの遷移先の添字で、すでに何らかの魔法を使ってモンスターの体力をj削った状態から
      //i番目の魔法を1回使った時に削れるモンスターの体力量
      //(普通はj+aだが、j+aでhを削り切れる時に配列外参照を起こす可能性がある為以下の式の形になっている)
      ll nj = min(j+a,h);
      //体力をj削るコストに魔法iの一回分のコストbを足したものの方が、体力をnj削るこれまでの最小コストより
      //最小であるなら更新
      chmin(dp[nj],dp[j]+b);
    }
  }
  //モンスターの体力をh削り切れる魔法の使い方の最小コストを出力
  cout << dp[h] << endl;
  return 0;
}
//最小コストを求めるdpナップザック問題
//dpの状態は魔法n回分と体力h分よりO(NH)となりこれの時点で10^7位なので
//dpの遷移の計算量をO(1)くらいにして10^1くらいで抑えたい
//何も考えずにdpテーブルと遷移を作ると、
//テーブルは、dp[i][j]:i番目までの魔法を使ってモンスターの体力をj削るのに必要な最小コスト
//遷移は、chmin(dp[i+1][j+k*a],dp[i][j]+k*b) (k=0~h/aの切り上げ)
//となるが、kのループでa=1の最悪ケースにてO(H)かかり、全体でO(NH^2)となりTLEする
//改善として、遷移をchmin(dp[i+1][min(j+a,h)],dp[i][j]+b)というものに変えれば良い
//この改善を1次元配列として行ったのが上のプログラムになる
//
