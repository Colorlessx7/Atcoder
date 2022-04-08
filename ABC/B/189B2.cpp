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
int main(){
  ll n, x;
  cin >> n >> x;
  vector<ll> v(n),p(n);
  x *= 100;
  rep(i,n){
    cin >> v[i] >> p[i];
  }
  rep(i,n){
    if(x < v[i] * p[i]){
      cout << i+1 << endl;
      return 0;
    }
    x -= v[i] * p[i];
  }
  cout << -1 << endl;
  return 0;
}
