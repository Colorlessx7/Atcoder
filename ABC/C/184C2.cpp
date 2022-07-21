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
int solve(){
  //座標(x1,y1)から座標(x2,y2)まで何手で行けるか
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  //上の座標の移動が斜め移動で分かりにくいので45度回転させる
  //(a1,b1)=(x1+y1,x1-y1)で座標(x1,y1)を45度回転したもの
  //(a2,b2)=(x2+y2,x2-y2)で座標(x2,y2)を45度回転したもの
  int a1 = x1 + y1;
  int b1 = x1 - y1;
  int a2 = x2 + y2;
  int b2 = x2 - y2;
  //始点と終点が等しいなら0回
  //45度回転後の座標(a1,b1)と(a2,b2)が一致しているなら0回の移動で良い
  if(a1 == a2 && b1 == b2){
    return 0;
  }
  //左下-右上方向の移動 斜め一直線上なので1回(問題の条件式1)
  //x1+y1=x2+y2を上のa1,a2,b1,b2で変形したもの
  //(回転後のX座標が一致しているのでY座標に並行に移動可能)
  if(a1 == a2){
    return 1;
  }
  //左上-右下方向の移動 斜め一直線上なので1回(問題の条件式2)
  //x1-y1=x2-y2を上のa1,a2,b1,b2で変形したもの
  //(回転後のY座標が一致しているのでX座標に並行に移動可能)
  if(b1 == b2){
    return 1;
  }
  //x軸,y軸方向合わせて絶対値3マス分の距離は動けるので1回(問題の条件式3)
  //回転前菱形だった絶対値3マスの移動範囲が45度回転すると正方形の形になる
  //移動元(x1,y1)=(0,0)として移動先(x2,y2)を移動限界の
  //(3,0),(0,3),(-3,0),(0,-3)とすると(x1,y1)の45度回転後の座標(a1,b1)は
  //(3,3),(3,-3),(-3,3),(-3,-3)を端とする正方形が移動3の移動限界となる
  //よって(a1,b1)と(a2,b2)の各座標ごとの絶対値の差がどちらも3以下なら移動可能となる
  if(max(abs(a1-a2),abs(b1-b2)) <= 3){
    return 1;
  }
  //始点と終点のパリティ(偶奇)が一致しているなら2回(条件式1,2の斜め2回で到着可)
  //chessのビショップがそうであるように全座標が偶奇性を持って市松模様に塗られている場合
  //斜め移動では白マスからスタートした場合白マスにしか辿れず黒マスに向かうことができない
  //45度回転後も斜めが縦横の関係になっただけで偶奇性は残っている
  //座標(x1,y1)=(0,0)から斜めに1マス動かしてそこを(x2,y2)とすると
  //その候補は(1,1),(1,-1),(-1,1),(-1,-1)の4つであり、45度回転後の座標(a2,b2)は
  //(x2+y2,x2-y2)より(2,0),(0,2),(0,-2),(-2,0)となり、
  //(a2,b2)の各座標が2単位ずつ動くことによりa1と偶奇の違うa2には移動できないし
  //b1と偶奇の違うb2にも移動できないし、偶奇が合っているなら2手の斜め移動で移動可能となる
  //a1,a2を計算すると、b1,b2はa1,a2と偶奇性が一緒なのでa1,a2のパリティ判断だけすればよい
  if(a1%2 == a2%2){
    return 2;
  }
  //マンハッタン距離が6以下なら2回(条件式3を2回行う)
  //2つ上の条件式の絶対値距離が6になったver
  if(max(abs(a1-a2),abs(b1-b2)) <= 6){
    return 2;
  }
  //条件式1,3で飛ぶ場合
  //(a1,b1)から条件式1で(a3,b3)を通り、条件式3で(a2,b2)に向かう
  //条件式1がa1=a2なので(a3,b3)はX座標は変わらず(a1=a3,b3)となり、
  //最適なY座標b3は(a2,b2)に最も近い座標(Y座標一致)にするのがよく、
  //(a3,b3)=(a1,b2)と考えるのが最適となる
  //よって(a1,b2)から(a2,b2)に向かうことができるかを考えると
  //条件式3の45度回転後の式であるmax(abs(a1-a2),abs(b1-b2))<=3から
  //max(abs(a1-a2),abs(b2-b2))<=3で、maxの右が0で左が0以上のため
  //左だけ考えればよく、abs(a1-a2)<=3となる
  if(abs(a1-a2) <= 3){
    return 2;
  }
  //条件式2,3で飛ぶ場合
  if(abs(b1-b2) <= 3){
    return 2;
  }
  //全てくぐり抜けたら3回必要
  return 3;
}
int main(){
  cout << solve() << endl;
  return 0;
}
//ひたすら場合分けする問題
