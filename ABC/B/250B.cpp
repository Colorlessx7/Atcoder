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
  ll n, a, b;
  cin >> n >> a >> b;
  string sa, sb;
  ll cnt = 0;
  bool frag = false;
  rep(i,n*b){
    cnt++;
    if(cnt > b){
      cnt = 1;
      frag = !frag;
    }
    if(frag){
      sa += '.';
      sb += '#';
    }else {
      sa += '#';
      sb += '.';
    }
  }
  cnt = 0;
  frag = false;
  rep(i,n*a){
    cnt++;
    if(cnt > a){
      cnt = 1;
      frag = !frag;
    }
    if(frag){
      cout << sa << endl;
    }else {
      cout << sb << endl;
    }
  }
  return 0;
}
