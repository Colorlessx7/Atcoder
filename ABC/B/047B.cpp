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
  ll w, h, n;
  cin >> w >> h >> n;
  vector<vector<bool>> c(h,vector<bool>(w,true));
  rep(i,n){
    ll x, y, a;
    cin >> x >> y >> a;
    if(a == 1){
      for(ll j = 0; j < x; j++){
        rep(k,h){
          c[k][j] = false;
        }
      }
    }
    if(a == 2){
      for(ll j = w-1; j >= x; j--){
        rep(k,h){
          c[k][j] = false;
        }
      }
    }
    if(a == 3){
      for(ll j = 0; j < y; j++){
        rep(k,w){
          c[j][k] = false;
        }
      }
    }
    if(a == 4){
      for(ll j = h-1; j >= y; j--){
        rep(k,w){
          c[j][k] = false;
        }
      }
    }
  }
  ll ans = 0;
  rep(i,h){
    rep(j,w){
      if(c[i][j]){
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
