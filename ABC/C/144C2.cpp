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
void divisor(ll n, vector<ll>& div) {
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      div.push_back(i);
      if (i * i != n) div.push_back(n / i);
    }
  }
  sort(all(div));
  return;
}
int main(){
  ll n;
  cin >> n;
  vector<ll> num;
  divisor(n,num);
  ll x = num.size();
  ll ans = 0;
  if(x % 2 == 0){
    ans += num[x/2];
    ans += num[x/2-1];
  }else {
    ans += num[x/2];
    ans += num[x/2];
  }
  cout << ans - 2 << endl;
  return 0;
}
