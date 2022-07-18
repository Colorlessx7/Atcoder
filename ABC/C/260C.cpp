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
#define sz(v) (int)v.size()
using ll = long long;
using P = pair<int,int>;
using TP = tuple<int,int,int>;
template<typename Tx, typename Ty>Tx dup(Tx x, Ty y){return (x+y-1)/y;}
void chmin(int &x, int y){ x = min(x,y); }
void chmax(int &x, int y){ x = max(x,y); }
void chmin(ll &x, ll y){ x = min(x,y); }
void chmax(ll &x, ll y){ x = max(x,y); }
int main(){
  //n:初期の赤い宝石のレベル(1個所持)
  //x:レベルnの赤い宝石(nは2以上)を、レベルn−1の赤い宝石1個と、レベルnの青い宝石X個を変換する
  //y:レベルnの青い宝石(nは2以上)を、レベルn−1の赤い宝石1個と、レベルn−1の青い宝石Y個に変換する
  int n, x, y;
  cin >> n >> x >> y;
  //dp[i][j]:レベルiの、j=0で赤い宝石,j=1で青い宝石の個数を示す
  //(一番最初のレベルnをi=0として、レベル1をi=n-1として扱っている)
  vector<vector<ll>> dp(n,vector<ll>(2));
  //最初にレベルnの赤い宝石を持っているのでdp[0][0]を1,それ以外を0として初期化する
  dp[0][0] = 1;
  //各レベルについて回す(遷移回数はレベルnからレベル2まで処理させるので
  //|2,n|の区間の数はn-2+1でn-1回遷移させる)
  rep(i,n-1){
    //赤,青について処理(j=0,1)
    rep(j,2){
      //赤についての処理
      if(j == 0){
        //レベルが1つ上の宝石の個数分だけ
        //レベルが一つ下の赤い宝石に変換
        dp[i+1][j] += dp[i][j];
        //レベルが1つ上の宝石の個数分だけ
        //その個数*x個分だけレベル一つ下の青い宝石に変換
        dp[i][1] += dp[i][j] * x;
        //変換元の宝石を変換し切ったので0に(いらないかも)
        dp[i][j] = 0; 
      }else {
        //青についての処理
        //レベルが1つ上の宝石の個数分だけ
        //レベルが一つ下の青い宝石に変換
        dp[i+1][0] += dp[i][j];
        //レベルが1つ上の宝石の個数分だけ
        //その個数*y個分だけレベル一つ下の青い宝石に変換
        dp[i+1][j] += dp[i][j] * y;
        //変換元の宝石を変換し切ったので0に(いらないかも)
        dp[i][j] = 0;
      }
    }
  }
  //レベル1の青の宝石がdp[n-1][1]に格納されているのでそれを出力
  cout << dp[n-1][1] << endl;
  return 0;
}
