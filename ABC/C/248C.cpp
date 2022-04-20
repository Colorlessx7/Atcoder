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
using mint = modint998244353;
void chmin(ll &x, ll y){ x = min(x,y); }
void chmax(ll &x, ll y){ x = max(x,y); }
int main(){
  ll n, m, k;
  cin >> n >> m >> k;
  vector<vector<mint>> dp(n+1,vector<mint>(k+1));
  dp[0][0] = 1;
  rep(i,n){
    rep(j,k+1){
      if(dp[i][j] != 0){
        rep2(l,m){
          if(j + l <= k){
            dp[i+1][j+l] += dp[i][j];
          }
        }
      }
    }
  }
  mint ans = 0;
  rep(i,k+1){
    ans += dp[n][i];
  }
  cout << ans.val() << endl;
  return 0;
}
