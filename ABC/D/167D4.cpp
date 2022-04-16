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
  ll n, k;
  cin >> n >> k;
  vector<vector<ll>> g(n);
  rep(i,n){
    ll a;
    cin >> a;
    a--;
    g[i].push_back(a); 
  }
  queue<ll> q;
  vector<bool> visited(n);
  vector<ll> place;
  q.push(0);
  ll cnt = 0;
  ll x;
  while(q.size()){
    ll v = q.front();
    q.pop();
    if(visited[v]){
      x = v;
      break;
    }
    cnt++;
    place.push_back(v);
    visited[v] = true;
    for(ll u : g[v]){
      q.push(u);
    }
  }
  ll st,loop;
  ll f = place.size();
  rep(i,f){
    if(place[i] == x){
      loop = f - i;
      st = f - loop;
      break;
    }
  }
  if(k <= st){
    cout << place[k] + 1 << endl;
  }else {
    k -= st;
    k %= loop;
    cout << place[st + k] + 1 << endl;
  }
  return 0;
}
//自力bfs解
