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
  string s;
  cin >> n >> s;
  map<char,ll> left,right;
  rep(i,n){
    left[s[i]]++;
  }
  ll ans = 0;
  rep(i,n){
    ll num = 0;
    rep(j,26){
      char c = j + 'a';
      if(left[c] && right[c]){
        num++;
      }
    }
    chmax(ans,num);
    left[s[i]]--;
    right[s[i]]++;
  }
  cout << ans << endl;
  return 0;
}
