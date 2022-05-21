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
  ll n;
  cin >> n;
  vector<double> a(n),b(n);
  rep(i,n){
    cin >> a[i] >> b[i];
  }
  double sum = 0;
  rep(i,n){
    sum += (double)(a[i]/b[i]);
  }
  sum /= 2;
  double ans = 0; 
  rep(i,n){
    double num = (double)(a[i]/b[i]);
    if(sum <= num){
      ans += sum * b[i];
      printf("%.10f\n",ans);
      break;
    }else {
      sum -= num;
      ans += a[i];
    }
  }
  return 0;
}
