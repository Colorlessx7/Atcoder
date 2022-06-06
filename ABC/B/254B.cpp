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
using TP = tuple<ll,ll,ll>;
void chmin(ll &x, ll y){ x = min(x,y); }
void chmax(ll &x, ll y){ x = max(x,y); }
int main(){
  ll n;
  cin >> n;
  vector<vector<ll>> ans(30);
  ans[0].push_back(1);
  rep(i,2){
    ans[1].push_back(1);
  }
  replr(i,2,30){
    rep(j,i+1){
      if(j == 0 || j == i){
        ans[i].push_back(1);
      }else {
        ll x = ans[i-1][j] + ans[i-1][j-1];
        ans[i].push_back(x);
      }
    }
  }
  rep(i,n){
    rep(j,i+1){
      printf("%lld ",ans[i][j]);
    }
    cout << endl;
  }
  return 0;
}
