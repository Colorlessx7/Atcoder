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
  ll n, k;
  cin >> n >> k;
  double num = 0;
  rep2(i,n){
    ll x = i;
    ll cnt = 0;
    while(x < k){
      x *= 2;
      cnt++; 
    }
    double m = 1;
    rep(j,cnt){
      m *= 2;
    }
    double f = (double)1/m;
    num += f; 
  }
  num /= n;
  printf("%.12f\n",num);
  return 0;
}
