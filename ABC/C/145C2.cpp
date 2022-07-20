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
  vector<double> x(n),y(n);
  rep(i,n){
    cin >> x[i] >> y[i];
  }
  vector<int> p(n);
  iota(all(p),0);
  double all = 0;
  do{
    double dist = 0;
    rep(i,n-1){
      double dx = x[p[i+1]] - x[p[i]];
      double dy = y[p[i+1]] - y[p[i]];
      double dd = sqrt(dx*dx+dy*dy);
      dist += dd;
    }
    all += dist;
  }while(next_permutation(all(p)));
  double num = 1;
  rep2(i,n){
    num *= (double)i;
  }
  all /= num;
  printf("%.10f\n",all);
  return 0;
}
