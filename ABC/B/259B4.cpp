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
using C = complex<double>;
void chmin(int &x, int y){ x = min(x,y); }
void chmax(int &x, int y){ x = max(x,y); }
void chmin(ll &x, ll y){ x = min(x,y); }
void chmax(ll &x, ll y){ x = max(x,y); }
int main(){
  //a,b:回転前座標(a,b),d:回転する角度(deg)
  int a, b, d;
  cin >> a >> b >> d;
  //s:回転前の座標(a,b)
  //(複素数でa+biとする)
  C s = C(a,b);
  //def:座標回転における中心点(今回は原点なので(0,0)とする)
  //複素数上で0+0i=0とする
  C def = C(0,0);
  //180度
  double PI = acos(-1);
  //回転する角度(rad)
  //d/180がintのため180.とすることでdoubleに変換させる
  double theta = d/180.*PI;
  //大きさがcos^2(theta)+sin^2(theta)=1で、角度がthetaの単位ベクトル
  C r(cos(theta), sin(theta));
  //回転先の座標を複素数で計算
  //複素数座標の回転の式(原点基準でないver(原点適応可))は
  //回転の基準点(今回は原点)をx,回転元の座標(今回は(a,b))をy,
  //回転先の座標(今回は(reak,imag))をzとすると
  //z-x=(y-x)(cos(theta)+isin(theta))で、一番右の括弧の部分が以下の式のrで、
  //zがansで、xがdefで、yがsとなる。移項すると以下の式のようになる
  C ans = def + (s - def) * r;
  //x座標を実数部、y座標を虚数部としているのでその通りに出力する
  printf("%.20f %.20f\n",ans.real(),ans.imag());
  return 0;
}
//複素数解
