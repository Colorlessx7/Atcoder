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
  vector<vector<ll>> c(3,vector<ll>(3));
  rep(i,3){
    rep(j,3){
      cin >> c[i][j];
    }
  }
  vector<ll> h(2);
  vector<ll> w(2);
  rep(i,3){
    rep(j,2){
      if(i == 0){
        h[j] = c[i][j] - c[i][j+1];
      }else {
        if(h[j] != c[i][j] - c[i][j+1]){
          cout << "No" << endl;
          return 0;
        }
      }
    }
  }
  rep(j,3){
    rep(i,2){
      if(j == 0){
        w[i] = c[i][j] - c[i+1][j];
      }else {
        if(w[i] != c[i][j] - c[i+1][j]){
          cout << "No" << endl;
          return 0;
        }
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}
