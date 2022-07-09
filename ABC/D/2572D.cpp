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
  //n:頂点数
  int n;
  cin >> n;
  //(xi,yi):頂点iの座標,p[i]:頂点iのジャンプ台のパワー
  vector<int> x(n),y(n),p(n);
  rep(i,n){
    cin >> x[i] >> y[i] >> p[i];
  }
  //d[i][j]:i-j間を0点以上を経由してジャンプするのに必要なSの最小値
  vector d(n,vector<ll>(n));
  //全頂点について2重ループO(N^2)
  rep(i,n){
    rep(j,n){
      //dist:頂点i,j間のマンハッタン距離
      //問題文の式のPiS>=|xi-xj|+|yi-yj|の右辺に対応
      ll dist = (ll)abs(x[i]-x[j])+abs(y[i]-y[j]);
      //P[i]*S>=distよりS>=dist/p[i]となる
      //この式のS(整数)の最小はdist/p[i]の切り上げとなる
      d[i][j] = (dist+p[i]-1)/p[i];
    }
  }
  //ワーシャルフロイド法(bit演算で高速化を図る)O(N^3)
  //k:中継点,i始点,j終点
  rep(k,n){
    rep(i,n){
      rep(j,n){
        //i-k間,k-j間のSの大きい方がkから両方に飛ぶためのSの必要量になる
        //それがi-j間のSよりも小さいならkを経由したほうがSを小さくできる
        d[i][j] = min(d[i][j],max(d[i][k],d[k][j]));
      }
    }
  }
  //Sの最小値(Sの最大パターンで初期化)
  ll ans = 4e9;
  //始点を回す    
  rep(i,n){
    //iから全点に飛ぶのに必要なSの最大をnowとする(最小初期化)
    ll now = 0;
    //終点について回す
    rep(j,n){
      //Sの最大を調べ格納
      now = max(now,d[i][j]);
    }
    //適当なiから全点に向かうのに必要なSの最小が答えになる
    //(nowがi=0~n-1で一番小さい場合、そのiを始点とすればSを最小にできて良い)
    ans = min(ans,now);
  }
  //最終的なSを出力
  cout << ans << endl;
  return 0;
}
//ワーシャルフロイド問題(二分探索を削減)
