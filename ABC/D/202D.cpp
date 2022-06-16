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
using ll = long long;
using P = pair<int,int>;
using TP = tuple<int,int,int>;
void chmin(int &x, int y){ x = min(x,y); }
void chmax(int &x, int y){ x = max(x,y); }
int main(){
  int a, b;
  ll k;
  cin >> a >> b >> k;
  //集合(a+b)C(a)を高速で求めるためのテーブル
  //(パスカルの三角形のテーブルが集合の計算結果に対応)
  //例:最上段を0段目とした時の4段目は1,4,6,4,1だが、4C0,4C1,4C2,4C3,4C4に対応している
  vector<vector<ll>> c(61,vector<ll>(61));
  //パスカルの三角形の初期状態(ピラミッドの頂点に1が1個ある状態に初期化)
  c[0][0] = 1;
  //パスカルの三角形のテーブルを作るループ(60C?までが分かれば良いのでi+1=60になるところまでループ)
  rep(i,60){
    //i段目の要素数はi個なのでi回分ループ
    rep(j,i+1){
      //今見ている点の値c[i][j]を左下(c[i+1][j])と右下(c[i+1][j+1])に足していく
      c[i+1][j] += c[i][j];
      c[i+1][j+1] += c[i][j];
    }
  }
  //答えの文字列
  string ans;
  //一桁ずつaかbか確定させていくループ(全桁決めるまで)
  while(a+b > 0){
    //x:先頭をaとした場合の文字列の種類が何通りあるか
    ll x = 0;
    //aがまだ存在するか
    if(a >= 1){
      //aがまだ存在するなら先頭をaとした場合の文字列の種類は(a+b)C(a)の値になる
      x = c[a+b-1][a-1];
    }
    //kがx以下なら先頭はaになる
    if(k <= x){
      //文字列にaを追加
      ans += 'a';
      //aの個数を1減らす
      a--;
    }else {
      //kがxより大きいなら先頭はbなので文字列にbを追加
      ans += 'b';
      //bの個数を1減らす
      b--;
      //先頭がbの場合は今決めた桁以降の順番はxをkから引いたものになる
      k -= x;
    }
  }
  cout << ans << endl;
  return 0;
}
//a=2,b=2なら(a+b)C(a)=6で、aabb,abab,abba,baab,baba,bbaaの6通りになる
//先頭から3番目のabbaは1桁目をaに決めた段階で残りの3桁の種類数が3C1=3となり、まだ3番目だか、
//先頭から5番目のbabaは1桁目をbに決めた段階で残りの3桁の種類数が3C1=3となり、その中での2番目(5-3)になる
//先頭をbに決める場合はaの時の残りの桁での文字列の種類数を順番数kから引くことで同じ文字列を目標にしたままにできる
