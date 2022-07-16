#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep3(i,N) for(int i = N - 1; i >= 0; i--)
#define rep4(i,N) for(int i = N; i > 0; i--)
#define replr(i,l,r) for(int i = l; i < r; i++)
#define reprl(i,l,r) for(int i = l; i >= r; i--)
#define all(x) x.begin(),x.end() 
#define allr(x) x.rbegin(),x.rend() 
using ll = long long;
using P = pair<int,int>;
using TP = tuple<int,int,int>;
void chmin(int &x, int y){ x = min(x,y); }
void chmax(int &x, int y){ x = max(x,y); }
void chmin(ll &x, ll y){ x = min(x,y); }
void chmax(ll &x, ll y){ x = max(x,y); }
int main(){
  int n;
  ll sx, sy, tx, ty;
  cin >> n >> sx >> sy >> tx >> ty;
  vector<ll> x(n), y(n), r(n);
  rep(i,n){
    cin >> x[i] >> y[i] >> r[i];
  } 
  dsu d(n);
  rep(i,n){
    rep(j,i){
      ll dx = x[i] - x[j];
      ll dy = y[i] - y[j];
      ll dist = dx * dx + dy * dy;
      ll rf = r[i] + r[j];
      ll rf2 = abs(r[i] - r[j]);
      if(dist > rf * rf){
        continue;
      }
      if(dist < rf2 * rf2){
        continue;
      }
      d.merge(i,j);
    }
  }
  int s = 0;
  int t = 0;
  rep(i,n){
    ll sl = sx - x[i];
    ll tl = tx - x[i];
    ll sr = sy - y[i];
    ll tr = ty - y[i];
    ll r2 = r[i]*r[i];
    if(sl*sl+sr*sr == r2){
      s = i;
    }
    if(tl*tl+tr*tr == r2){
      t = i;
    }
  }
  if(d.same(s,t)){
    cout << "Yes" << endl;
  }else {
    cout << "No" << endl;
  }
  return 0;
}
