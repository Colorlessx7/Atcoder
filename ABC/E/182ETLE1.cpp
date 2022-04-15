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
  ll h, w, n, m;
  cin >> h >> w >> n >> m;
  vector<ll> a(n),b(n);
  rep(i,n){
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
  }
  vector<vector<ll>> dp(h,vector<ll>(w));
  const int INF = 1001001001;
  rep(i,m){
    ll c, d;
    cin >> c >> d;
    c--; d--;
    dp[c][d] = INF;
  }
  rep(i,n){
    reprl(j,a[i],0){
      if(dp[j][b[i]] == INF){
        break;
      }else {
        dp[j][b[i]] = 1;
      }
    }
    replr(j,a[i],h){
      if(dp[j][b[i]] == INF){
        break;
      }else {
        dp[j][b[i]] = 1;
      }
    }
    reprl(j,b[i],0){
      if(dp[a[i]][j] == INF){
        break;
      }else {
        dp[a[i]][j] = 1;
      }
    }
    replr(j,b[i],w){
      if(dp[a[i]][j] == INF){
        break;
      }else {
        dp[a[i]][j] = 1;
      }
    }
  }
  ll ans = 0;
  rep(i,h){
    rep(j,w){
      if(dp[i][j] == 1){
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
