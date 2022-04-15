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
  queue<tuple<ll,ll,ll>> q;
  tuple<ll,ll,ll> x;
  rep(i,n){
    dp[a[i]][b[i]] = 1;
    if(a[i] != 0){
      if(dp[a[i]-1][b[i]] != INF){
        x = {a[i]-1,b[i],1};
        q.push(x);
      }
    }
    if(a[i] != h-1){
      if(dp[a[i]+1][b[i]] != INF){
        x = {a[i]+1,b[i],3};
        q.push(x);
      }
    }
    if(b[i] != 0){
      if(dp[a[i]][b[i]-1] != INF){
        x = {a[i],b[i]-1,4};
        q.push(x);
      }
    }
    if(b[i] != w-1){
      if(dp[a[i]][b[i]+1] != INF){
        x = {a[i],b[i]+1,2};
        q.push(x);
      }
    }
  }
  while(q.size()){
    x = q.front();
    q.pop();
    ll i = get<0>(x);
    ll j = get<1>(x);
    ll k = get<2>(x);
    dp[i][j] = 1;
    if(k == 1){
      if(i != 0){
        if(dp[i-1][j] != INF){
          x = {i-1,j,1};
          q.push(x);
        }
      }
    }
    if(k == 3){
      if(i != h-1){
        if(dp[i+1][j] != INF){
          x = {i+1,j,3};
          q.push(x);
        }
      }
    }
    if(k == 4){
      if(j != 0){
        if(dp[i][j-1] != INF){
          x = {i,j-1,4};
          q.push(x);
        }
      }
    }
    if(k == 2){
      if(j != w-1){
        if(dp[i][j+1] != INF){
          x = {i,j+1,2};
          q.push(x);
        }
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
