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
  vector<vector<ll>> t(n,vector<ll>(n));
  rep(i,n){
    rep(j,n){
      cin >> t[i][j];
    }
  }
  vector<ll> v(n-1);
  rep(i,n-1){
    v[i] = i+1;
  }
  ll ans = 0;
  do{
    ll num = 0;
    num += t[0][v[0]];
    rep(i,n-2){
      num += t[v[i]][v[i+1]];
    }
    num += t[v[n-2]][0];
    if(num == k){
      ans++;
    }
  }while(next_permutation(all(v)));
  cout << ans << endl;
  return 0;
}
