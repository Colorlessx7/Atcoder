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
  double a, b, x;
  cin >> a >> b >> x;
  x /= a;
  double c = a * b / 2;
  double ans = 0;
  const double PI = acos(-1);
  if(x <= c){
    double ad = 2 * x / b;
    ans = atan2(ad,b);
  }else {
    double bd = 2 * (a*b-x) / a;
    ans = atan2(bd,a);
  }
  double deg = ans * (180 / PI);
  if(x <= c){
    deg = 90 - deg;
  }
  printf("%.10f\n", deg);
  return 0;
}
