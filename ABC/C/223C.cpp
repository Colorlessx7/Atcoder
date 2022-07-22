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
#define sz(v) (int)v.size()
using ll = long long;
using P = pair<int,int>;
using TP = tuple<int,int,int>;
template<typename Tx, typename Ty>Tx dup(Tx x, Ty y){return (x+y-1)/y;}
void chmin(int &x, int y){ x = min(x,y); }
void chmax(int &x, int y){ x = max(x,y); }
void chmin(ll &x, ll y){ x = min(x,y); }
void chmax(ll &x, ll y){ x = max(x,y); }
int main(){
  int n;
  cin >> n;
  vector<double> a(n),b(n);
  rep(i,n){
    cin >> a[i] >> b[i];
  }
  double sum1 = 0;
  vector<double> sp;
  sp.push_back(0);
  rep(i,n){
    sum1 += a[i] / b[i];
    sp.push_back(sum1);
  }
  sum1 /= 2;
  double ans = 0;
  rep(i,n+1){
    if(sum1 <= sp[i]){
      ans += (sum1 - sp[i - 1]) * b[i - 1];
      break;
    }
    if(i != 0){
      ans += a[i - 1];
    }
  }
  printf("%.10f\n",ans);
  return 0;
}
