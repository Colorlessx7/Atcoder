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
  string s = to_string(n);
  ll x = s.size();
  sort(allr(s));
  ll ans = 0;
  rep(i,1<<x){
    string l;
    string r;
    rep(j,x){
      if(i & (1<<j)){
        l += s[j];
      }else {
        r += s[j];
      }
    }
    if(l.size() == 0 || r.size() == 0 || l[0] == '0' || r[0] == '0'){
      continue;
    }
    ll le = stoll(l);
    ll ri = stoll(r);
    chmax(ans,le*ri);
  }
  cout << ans << endl;
  return 0;
}
