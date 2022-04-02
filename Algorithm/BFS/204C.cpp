#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(ll i = 0; i < N; i++)
#define rep2(i,N) for(ll i = 1; i <= N; i++)
#define rep3(i,N) for(ll i = N - 1; i >= 0; i--)
#define rep4(i,N) for(ll i = N; i > 0; i--)
#define replr(i,l,r) for(ll i = l; i < r; i++)
#define reprl(i,l,r) for(ll i = l; i > r; i--)
#define all(x) x.begin(),x.end() 
#define allr(x) x.rbegin(),x.rend() 
using ll = long long;
using P = pair<ll,ll>;
int main(){
  ll n, m;
  cin >> n >> m;
  vector<vector<ll>> g(n);
  rep(i,m){
    ll a, b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
  }
  ll ans = 0;
  vector<bool> visit(n);
  queue<ll> q;
  rep(i,n){
    q.push(i);
    while(q.size()){
      ll f = q.front();
      q.pop();
      visit[f] = true;
      for(ll u : g[f]){
        if(!visit[u]){
          q.push(u);
        }
      }
    }
    rep(j,n){
      if(visit[j]){
        ans++;
      }
      visit[j] = false;
    }
  }
  cout << ans << endl;
  return 0;
}
