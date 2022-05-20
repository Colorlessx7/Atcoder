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
  string s;
  ll q;
  cin >> s >> q;
  deque<char> deq;
  ll n = s.size();
  rep(i,n){
    deq.push_back(s[i]);
  }
  bool rev = true;
  rep(qi,q){
    ll t;
    cin >> t;
    if(t == 1){
      rev = !rev;
    }else {
      ll f;
      char c;
      cin >> f >> c;
      if(rev){
        if(f == 1){
          deq.push_front(c);
        }else {
          deq.push_back(c);
        }
      }else {
        if(f == 1){
          deq.push_back(c);
        }else {
          deq.push_front(c);
        }
      }
    }
  }
  string ans;
  ll x = deq.size();
  rep(i,x){
    ans += deq[i];
  }
  if(!rev){
    reverse(all(ans));
  }
  cout << ans << endl;
  return 0;
}
