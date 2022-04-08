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
  ll n;
  cin >> n;
  vector<ll> l(n);
  rep(i,n){
    cin >> l[i];
  }
  ll ans = 0;
  sort(all(l));
  rep(i,n){
    rep(j,i){
      ll x = l[i] + l[j];
      auto itr = l.begin();
      advance(itr,i+1);
      ans += lower_bound(itr,l.end(),x) - itr;
    }
  }
  cout << ans << endl;
  return 0;
}
//二分探索
//ans += r - i - 1ではなくイテレータを操作したver
//
