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
  ll n, m;
  cin >> n >> m;
  vector<vector<char>> a(n,vector<char>(n));
  vector<vector<char>> b(m,vector<char>(m));
  rep(i,n){
    rep(j,n){
      cin >> a[i][j];
    }
  }
  rep(i,m){
    rep(j,m){
      cin >> b[i][j];
    }
  }
  ll x = n - (m - 1);
  rep(h,x){
    rep(w,x){
      bool ans = false;
      rep(i,m){
        rep(j,m){
          if(a[i+h][j+w] != b[i][j]){
            ans = true;
          }  
        }
      }
      if(!ans){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
