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
void chmin(ll &x, ll y){ x = min(x,y); }
void chmax(ll &x, ll y){ x = max(x,y); }
void dfs(ll u,vector<vector<ll>> &g,vector<ll> &ans,vector<bool> &visit){
  visit[u] = true;
  ans.push_back(u+1);
  for(ll v : g[u]){
    if(visit[v]){
      continue;
    }
    dfs(v,g,ans,visit);
    ans.push_back(u+1);
  }
  return;
}
int main(){
  ll n;
  cin >> n;
  vector<vector<ll>> g(n);
  rep(i,n-1){
    ll a, b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  rep(i,n){
    sort(all(g[i]));
  }
  vector<bool> visit(n);
  vector<ll> ans;
  dfs(0,g,ans,visit);
  ll num = ans.size();
  rep(i,num){
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}

