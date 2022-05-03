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
  vector<ll> h(n+2);
  rep2(i,n){
    cin >> h[i];
  }
  ll ans = 0;
  bool frag = false;
  while(1){
    ll num = LLONG_MAX;
    ll cnt = 0;
    bool lpout = true;
    rep(i,n+2){
      if(frag && h[i] == 0){
        frag = false;
        cnt++;
      }else if(!frag && h[i] != 0){
        frag = true;
      }
      if(h[i] != 0){
        chmin(num,h[i]);
        lpout = false;
      }
    }
    if(lpout){
      break;
    }
    ans += cnt * num;
    rep(i,n+2){
      if(h[i] != 0){
        h[i] -= num;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
