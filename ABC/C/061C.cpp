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
  priority_queue<P,vector<P>,greater<P>> que;
  ll num = 0;
  rep(i,n){
    ll a, b;
    cin >> a >> b;
    P f = make_pair(a,b);
    que.push(f);
  }
  while(que.size()){
    P x = que.top();
    que.pop();
    ll p = x.second;
    k -= p;
    if(k <= 0){
      cout << x.first << endl;
      return 0;
    }
  }
  return 0;
}
