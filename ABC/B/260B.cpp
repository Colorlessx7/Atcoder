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
using TP = tuple<int,int,int,int>;
template<typename Tx, typename Ty>Tx dup(Tx x, Ty y){return (x+y-1)/y;}
void chmin(int &x, int y){ x = min(x,y); }
void chmax(int &x, int y){ x = max(x,y); }
void chmin(ll &x, ll y){ x = min(x,y); }
void chmax(ll &x, ll y){ x = max(x,y); }
bool compare(P a, P b) {
  if(a.first != b.first){
    return a.first > b.first;
  }
  return a.second < b.second;
}
int main(){
  int n, x, y, z;
  cin >> n >> x >> y >> z;
  vector<int> a(n);
  vector<int> b(n);
  rep(i,n){
    cin >> a[i];
  }
  rep(i,n){
    cin >> b[i];
  }
  vector<P> math(n);
  vector<P> eng(n);
  vector<P> sum(n);
  rep(i,n){
    math[i] = {a[i],i};
    eng[i] = {b[i],i};
    sum[i] = {a[i]+b[i],i};
  }
  vector<bool> ans(n);
  sort(all(math),compare);
  sort(all(eng),compare);
  sort(all(sum),compare);
  rep(i,x){
    int j = math[i].second;
    ans[j] = true;
  }
  rep(i,n){
    if(y == 0){
      break;
    }
    int j = eng[i].second;
    if(!ans[j]){
      ans[j] = true;
      y--;
    }
  }
  rep(i,n){
    if(z == 0){
      break;
    }
    int j = sum[i].second;
    if(!ans[j]){
      ans[j] = true;
      z--;
    }
  }
  rep(i,n){
    if(ans[i]){
      cout << i+1 << endl;
    }
  }
  return 0;
}
