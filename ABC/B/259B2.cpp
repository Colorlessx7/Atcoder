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
  int a, b, d;
  cin >> a >> b >> d;
  //三角関数のrを計算
  double r = sqrt(a*a+b*b);
  //atan2(y,x)で角度を求める
  double theta = atan2(b,a);
  //180度
  double PI = acos(-1);
  //元の角度thetaに180度を足して原点を中心として反時計回りさせる
  //d/180がintのため180.とすることでdoubleに変換させる
  theta += d/180.*PI;
  //cos(theta)=x/rより移項して以下の式でxが求まる
  double x = r*cos(theta);
  //sin(theta)=x/rより移項して以下の式でyが求まる
  double y = r*sin(theta);
  printf("%.20f %.20f\n",x,y);
  return 0;
}
