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
  string a, b;
  cin >> a >> b;
  ll as = a.size(); ll bs = b.size();
  ll ans = 2;
  if(as > bs){
    ans = 0;
  }else if(as < bs){
    ans = 1;
  }else{
    rep(i,as){
      if(a[i] > b[i]){
        ans = 0;
        break;
      }else if(a[i] < b[i]){
        ans = 1;
        break;
      }
    }
  }
  if(ans == 0){
    cout << "GREATER" << endl;
  }else if(ans == 1){
    cout << "LESS" << endl;
  }else {
    cout << "EQUAL" << endl;
  }
  return 0;
}
