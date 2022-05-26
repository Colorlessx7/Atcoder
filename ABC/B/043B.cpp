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
  string ans;
  ll n = s.size();
  rep(i,n){
    if(s[i] == '0'){
      ans += '0';
    }
    if(s[i] == '1'){
      ans += '1';
    }
    if(s[i] == 'B'){
      if(ans.size() != 0){
        ans.pop_back();
      }
    }
  }
  cout << ans << endl;
  return 0;
}
