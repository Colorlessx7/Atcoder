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
void chmin(double &x, double y){ x = min(x,y); }
void chmax(ll &x, ll y){ x = max(x,y); }
int main(){
  double a, b, h, m;
  cin >> a >> b >> h >> m;
  double PI = acos(-1);
  double t_m = m * PI / 30;
  double t_h = (h/6+m/360)*PI;
  double diff = max(t_m,t_h) - min(t_m,t_h);
  chmin(diff,2*PI-diff);
  double x = a*a+b*b-2*a*b*cos(diff);
  x = sqrt(x);
  printf("%.10f\n",x);
  return 0;
}
