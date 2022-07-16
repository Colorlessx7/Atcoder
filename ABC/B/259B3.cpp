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
void chmin(ll &x, ll y){ x = min(x,y); }
void chmax(ll &x, ll y){ x = max(x,y); }
int main(){
  //a,b:回転前座標(a,b),d:回転する角度(deg)
  int a, b, d;
  cin >> a >> b >> d;
  //180度
  double PI = acos(-1);
  //回転する角度(rad)
  //d/180がintのため180.とすることでdoubleに変換させる
  double theta = d/180.*PI;
  //回転行列の計算結果(x,y)を計算する
  double x = a*cos(theta)-b*sin(theta);
  double y = a*sin(theta)+b*cos(theta);
  printf("%.20f %.20f\n",x,y);
  return 0;
}
//回転行列の計算過程
//反時計回りにthetaだけ回転させる回転行列は
//(cos(theta),-sin(theta))
//(sin(theta), cos(theta))となる
//(cos(theta),-sin(theta)) * (a) = (acos(theta)-bsin(theta)) = (x)
//(sin(theta), cos(theta)) * (b) = (asin(theta)+bcos(theta)) = (y)となる
