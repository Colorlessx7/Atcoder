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
  ll h, n;
  cin >> h >> n;
  vector<ll> a(n),b(n);
  rep(i,n){
    cin >> a[i] >> b[i];
  }
  ll f;
  const ll INF = 1001001001;
  vector<vector<ll>> dp(n+1,vector<ll>(h+1,INF));
  dp[0][0] = 0;
  rep(i,n){
    rep(j,h+1){
      if(dp[i][j] != INF){
        for(ll k = 0; j+k*a[i] <= h; k++){
          chmin(dp[i+1][j+k*a[i]],dp[i][j]+k*b[i]);
          f = k;
        }
        f++;
        chmin(dp[i+1][h],dp[i][j]+f*b[i]);
      }
    }
  }
  cout << dp[n][h] << endl;
  return 0;
}
