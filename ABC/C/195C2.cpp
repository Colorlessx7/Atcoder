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
  ll ans = 0;
  ll cnt = 0;
  ll x = 999;
  ll y = 1;
  while(1){
    if(x > n){
      ans += (n-y+1)*cnt;
      break;
    }else {
      ans += (x-y+1)*cnt;
    }
    x = x*1000+999;
    y *= 1000;
    cnt++;
  }
  cout << ans << endl;
  return 0;
}
