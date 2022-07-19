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
  int n, x, y;
  cin >> n >> x >> y;
  //レベルがlevelで、宝石の種類がie_redな宝石1個が
  //最終的にレベル1の青い宝石何個になるかを計算する関数
  //(オーバーフローのためアロー演算子->で戻り値をllにする必要がある(デフォがint?))
  //引数,f:再帰のための指定,level:宝石のレベル,is_red:
  auto calc = [&](auto f, int level, bool is_red) -> ll {
    //再帰のベースケース
    //赤い宝石レベル1なら青い宝石レベル1に変換できないので0を返す
    //青い宝石レベル1なら変換せずとも1こあるので1を返す
    if(level == 1){
      //赤い宝石なら0を青い宝石なら1を再帰元に返す
      return is_red ? 0 : 1;
    }
    //赤い宝石について見ているなら処理
    if(is_red){
      //レベルlevelの赤い宝石1つは
      //レベルlevel−1の赤い宝石1個と、レベルlevelの青い宝石X個に変換できる
      return f(f,level-1,true) + f(f,level,false)*x;
    }else {
      //青い宝石について見ているなら処理
      //レベルlevelの青い宝石1つは
      //レベルlevel−1の赤い宝石1個と、レベルlevel−1の青い宝石Y個に変換できる
      return f(f,level-1,true) + f(f,level-1,false)*y;
    }
  };
  //レベルnの赤い宝石1つが何個のレベル1の青い宝石になるかを関数で計算して出力
  cout << calc(calc,n,true) << endl;
  return 0;
}
//再帰関数ver
