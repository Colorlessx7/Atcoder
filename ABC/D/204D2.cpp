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
  //料理数
  int n;
  cin >> n;
  //dp[i][j]:料理i個から何個か作る料理を選んだ時に
  //それらを作るのに合計j分かかるならtrue,かからないならflase
  vector<vector<bool>> dp(n+1,vector<bool>(100001));
  //料理を1個も作らない場合の所要時間は0分なのでdp[0][0]をtrueとして初期化する
  //(他はflaseで初期化)
  dp[0][0] = true;
  //全てを1つのオーブンで作る場合にかかる所要時間
  int sum = 0;
  //全料理について処理
  //O(N)
  rep(i,n){
    //t:料理iの作成にかかる時間
    int t;
    cin >> t;
    //dpの遷移処理部分
    //O(NT)
    rep(j,100001){
      //trueなら丁度j分で料理が何個か作れるので処理
      if(dp[i][j]){
        //料理iを作らない場合
        //料理の個数は増えるが所要時間は増えない
        dp[i+1][j] = true;
        //料理iを作る場合
        //料理の個数が増え、所要時間がt分増える
        dp[i+1][j+t] = true;
      }
    }
    //合計所要時間に料理iの所要時間を足す
    sum += t;
  }
  //答えを最大初期化
  int ans = INT_MAX;
  //所要時間のとりうる範囲について回す
  rep(i,100001){
    //trueなら料理何個かをi分で作れるので処理
    if(dp[n][i]){
      //オーブン1で料理何個かをi分で、オーブン2でそれ以外の料理全てをsum-i分で作る場合
      //かかる時間は大きい方になる
      //全ての料理のオーブン1,2の分け方についてこれを求めて最小値を答えとする
      chmin(ans,max(i,sum-i));
    }
  }
  cout << ans << endl;
  return 0;
}
//dpの部分和問題
