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
  int n, m;
  cin >> n >> m;
  vector<vector<char>> a(n,vector<char>(n));
  vector<vector<char>> b(m,vector<char>(m));
  rep(i,n){
    rep(j,n){
      cin >> a[i][j];
    }
  }
  rep(i,m){
    rep(j,m){
      cin >> b[i][j];
    }
  }
  //平行移動させた時の全探索の開始点がとりうるi,jごとの個数
  int x = n - m + 1;
  //平行移動時の全探索の開始点(i,j)を決めるループ
  rep(i,x){
    rep(j,x){
      bool flag = true;
      //全探索で図形が完全に一致しているか見るループ
      rep(ni,m){
        rep(nj,m){
          //平行移動させてbの図形とaの中の(ni,nj)ずれたbと同じ大きさの
          //図形が完全に一致しているか確認
          if(a[i+ni][j+nj] != b[ni][nj]){
            flag = false;
          }
        }
      }
      //完全に一致していたらflagが立ったままなのでYesを出力して終了
      if(flag){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  //平行移動しても一致しているものが一つもない場合
  cout << "No" << endl;
  return 0;
}
//全探索問題 
