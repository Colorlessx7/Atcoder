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
using mint = modint1000000007;
void chmin(ll &x, ll y){ x = min(x,y); }
void chmax(ll &x, ll y){ x = max(x,y); }
int main(){
  ll n, m;
  cin >> n >> m;
  vector<vector<ll>> g(n);
  rep(i,m){
    ll a, b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<mint> dp(n);
  dp[0] = 1;
  queue<ll> q;
  q.push(0);
  const int INF = 1001001001;
  vector<ll> visit(n,INF);
  visit[0] = 0;
  while(q.size()){
    ll v = q.front();
    q.pop();
    for(ll u : g[v]){
      if(visit[u] != INF){
        if(visit[u] == visit[v] + 1){
          dp[u] += dp[v];
        }
        continue;
      }else {
        visit[u] = visit[v] + 1;
        dp[u] += dp[v];
        q.push(u);
      }
    }
  }
  if(visit[n-1] == INF){
    cout << 0 << endl;
    return 0;
  }
  cout << dp[n-1].val() << endl;
  return 0;
}
