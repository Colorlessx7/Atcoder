#include<bits/stdc++.h>
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
template<typename Tx, typename Ty>Tx dup(Tx x, Ty y){return (x+y-1)/y;}
void chmin(int &x, int y){ x = min(x,y); }
void chmax(int &x, int y){ x = max(x,y); }
void chmin(ll &x, ll y){ x = min(x,y); }
void chmax(ll &x, ll y){ x = max(x,y); }
//O(N^2)
void solve(){
  //n:グリッドの1辺の長さ
  int n;
  cin >> n;
  //a:元のグリッド
  vector<vector<int>> a(n,vector<int>(n));
  //グリッド全段について回す
  rep(i,n){
    //i段目のグリッドの情報
    string s;
    cin >> s;
    //i段目のグリッドの情報で回す
    rep(j,n){
      //sのj文字目をintに直したものをa[i][j]とする
      a[i][j] = s[j] - '0';
    }
  }
  //入れ替える座標の数
  int ans = 0;
  //同じ位置関係の4点を調べる
  rep(i,(n+1)/2){
    rep(j,n/2){
      //nowi,nowj:同じ位置関係の座標(nowi,nowj)を示す
      int nowi = i;
      int nowj = j;
      //回転前のj=nowjをoldnowjとする
      int oldnowj = nowj;
      //0度回転(default)のグリッドの値(0or1)をsumに加算
      int sum = a[nowi][nowj];
      //270度回転した先のjは全体(n)-1(0index処理)-回転前のi(nowi)
      nowj = n-nowi-1;
      //270度回転した先のiは0度回転の時のjとなる
      nowi = oldnowj;
      //270度回転のグリッドの値(0or1)をsumに加算
      sum+=a[nowi][nowj];
      //270度回転時点のj=nowjをoldnowjに格納
      oldnowj = nowj;
      //180度回転時点のjは全体(n)-1(0index処理)-270度回転時点のi(nowi)
      nowj = n-nowi-1;
      //180度回転した先のiは270度回転の時のjとなる
      nowi = oldnowj;
      //180度回転のグリッドの値(0or1)をsumに加算
      sum+=a[nowi][nowj];
      //180度回転時点のj=nowjをoldnowjに格納
      oldnowj = nowj;
      //90度回転時点のjは全体(n)-1(0index処理)-180度回転時点のi(nowi)
      nowj = n-nowi-1;
      //90度回転した先のiは180度回転の時のjとなる
      nowi = oldnowj;
      //90度回転のグリッドの値(0or1)をsumに加算
      sum+=a[nowi][nowj];
      //同じ位置関係の4点の0,1の少ない方を加算する
      //(少ない方を多い方に書き換えるため書き換える個数が0,1の少ない方になる)
      ans += min(sum,4-sum);
    }
  }
  //出力
  cout << ans << '\n';
}
int main(){
  int t;
  cin >> t;
  rep(i,t) solve();
  return 0;
}
//同じ位置関係なのが
//n=偶数だと 奇数だと
//abca      abcda
//cddb      defeb
//bddc      cfgfc
//acba      befed
//          adcba
//となるため調べる範囲はi,jのどちらか片方が(n+1)/2、もう片方がn/2の範囲を探索すればよい
