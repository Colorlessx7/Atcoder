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
  int n, x, y;
  cin >> n >> x >> y;
  vector<vector<ll>> dp(n,vector<ll>(2));
  dp[0][0] = 1;
  rep(i,n-1){
    rep(j,2){
      if(j == 0){
        dp[i+1][j] += dp[i][j];
        dp[i][1] += dp[i][j] * x;
        dp[i][j] = 0; 
      }else {
        dp[i+1][0] += dp[i][j];
        dp[i+1][j] += dp[i][j] * y;
        dp[i][j] = 0;
      }
    }
  }
  cout << dp[n-1][1] << endl;
  return 0;
}
