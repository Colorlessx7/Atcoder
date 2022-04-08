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
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n){
    cin >> a[i];
  }
  ll ans = 0;
  rep(i,n){
    rep(j,i){
      rep(k,j){
        if(a[i] != a[j] && a[j] != a[k] && a[k] != a[i]){
          if(a[i]+a[j]>a[k]&&a[j]+a[k]>a[i]&&a[k]+a[i]>a[j]){
            ans++;
          }
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
