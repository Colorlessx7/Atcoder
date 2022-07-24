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
  vector<vector<char>> a(n,vector<char>(n));
  rep(i,n){
    rep(j,n){
      cin >> a[i][j];
    }
  }
  bool flag = true;
  rep(i,n){
    rep(j,n){
      if(i == j){
        continue;
      }
      if(a[i][j] == 'W'){
        if(a[j][i] != 'L'){
          flag = false;
        }
      }
      if(a[i][j] == 'L'){
        if(a[j][i] != 'W'){
          flag = false;
        }
      }
      if(a[i][j] == 'D'){
        if(a[j][i] != 'D'){
          flag = false;
        }
      }
    }
  }
  if(flag){
    cout << "correct" << endl;
  }else {
    cout << "incorrect" << endl;
  }
  return 0;
}
