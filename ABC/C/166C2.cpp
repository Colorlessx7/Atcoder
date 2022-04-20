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
  ll n,m;
  cin >> n >> m;
  vector<ll> h(n);
  rep(i,n){
    cin >> h[i];
  }
  vector<vector<ll>> g(n);
  rep(i,m){
    ll a, b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  ll ans = 0;
  rep(i,n){
    bool frag = true;
    for(ll u : g[i]){
      if(h[i] <= h[u]){
        frag = false;
        break;
      }
    }
    if(frag){
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
