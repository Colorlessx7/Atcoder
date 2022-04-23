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
  cin >> s;
  vector<ll> v(4);
  rep(i,4){
    v[i] = s[i] - '0';
  }
  rep(i,8){
    ll num = v[0];
    rep(j,3){
      if(i&(1<<j)){
        num += v[j+1];
      }else {
        num -= v[j+1];
      }
    }
    if(num == 7){
      cout << v[0];
      rep(j,3){
        if(i&(1<<j)){
          cout << "+" << v[j+1];
        }else {
          cout << "-" << v[j+1];
        }
      }
      cout << "=7" << endl;
      return 0;
    }
  }
  return 0;
}
