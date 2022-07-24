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
bool solve(){
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i,n){
    cin >> s[i];
  }
  rep(i,n){
    rep(j,n){
      if(i == j){
        continue;
      }
      if(s[i][j] == 'W'){
        if(s[j][i] != 'L'){
          return false;
        }
      }
      if(s[i][j] == 'L'){
        if(s[j][i] != 'W'){
          return false;
        }
      }
      if(s[i][j] == 'D'){
        if(s[j][i] != 'D'){
          return false;
        }
      }
    }
  }
  return true;
}
int main(){
  if(solve()){
    cout << "correct" << endl;
  }else {
    cout << "incorrect" << endl;
  }
  return 0;
}
