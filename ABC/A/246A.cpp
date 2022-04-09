#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(ll i = 0; i < N; i++)
#define rep2(i,N) for(ll i = 1; i <= N; i++)
#define rep3(i,N) for(ll i = N - 1; i >= 0; i--)
#define rep4(i,N) for(ll i = N; i > 0; i--)
#define replr(i,l,r) for(ll i = l; i < r; i++)
#define reprl(i,l,r) for(ll i = l; i > r; i--)
#define all(x) x.begin(),x.end() 
#define allr(x) x.rbegin(),x.rend() 
using ll = long long;
using P = pair<ll,ll>;
void chmin(ll &x, ll y){ x = min(x,y); }
void chmax(ll &x, ll y){ x = max(x,y); }
int main(){
  ll x1, y1, x2, y2, x3, y3;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  map<ll,ll> mpx;
  map<ll,ll> mpy;
  mpx[x1]++;
  mpx[x2]++;
  mpx[x3]++;
  mpy[y1]++;
  mpy[y2]++;
  mpy[y3]++;
  ll ansx,ansy;
  for(auto p : mpx){
    if(p.second == 1){
      ansx = p.first;
    }
  }
  for(auto p : mpy){
    if(p.second == 1){
      ansy = p.first;
    }
  }
  cout << ansx << " " << ansy << endl;
  return 0;
}
