#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep3(i,N) for(int i = N - 1; i >= 0; i--)
#define rep4(i,N) for(int i = N; i > 0; i--)
#define replr(i,l,r) for(int i = l; i < r; i++)
#define reprl(i,l,r) for(int i = l; i >= r; i--)
#define sz(v) (int)v.size()
#define all(x) x.begin(),x.end() 
#define allr(x) x.rbegin(),x.rend() 
using ll = long long;
using P = pair<int,int>;
using TP = tuple<int,int,int>;
void chmin(int &x, int y){ x = min(x,y); }
void chmax(int &x, int y){ x = max(x,y); }
void chmin(ll &x, ll y){ x = min(x,y); }
void chmax(ll &x, ll y){ x = max(x,y); }
void solve(){
  //m:整数
  int m;
  cin >> m;
  //t:mを文字列にしたもの
  string t = to_string(m);
  //s:mに最も近いround number(10^k)(1=10^0初期化)
  string s = "1";
  //sをtと同じ桁のround numberにするためmの桁数-1回sに0を追加する
  rep(i,sz(t)-1){
    s += '0';
  }
  //k:round numberであるsをintに直す
  int k = stoi(s);
  //差分を出力
  cout << m - k << '\n';
}
int main(){
  int t;
  cin >> t;
  rep(i,t) solve();
  return 0;
}
