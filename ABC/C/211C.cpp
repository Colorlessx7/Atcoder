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
using mint = modint1000000007;
void chmin(ll &x, ll y){ x = min(x,y); }
void chmax(ll &x, ll y){ x = max(x,y); }
int main(){
  string s;
  cin >> s;
  ll n = s.size();
  vector<vector<mint>> dp(9,vector<mint>(n+1));
  rep(i,n+1){
    dp[0][i] = 1;
  }
  string t = "chokudai";
  rep(i,8){
    rep(j,n){
      if(s[j] == t[i]){
        dp[i+1][j+1] += dp[i][j] + dp[i+1][j];
      }else {
        dp[i+1][j+1] += dp[i+1][j];
      }
    }
  }
  cout << dp[8][n].val() << endl;
  return 0;
}

