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
  vector<double> x(n),y(n);
  rep(i,n){
    cin >> x[i] >> y[i];
  }
  //順列生成配列
  vector<int> p(n);
  //0~n-1にpを設定
  iota(all(p),0);
  //i番目とj番目の座標間のユークリッド距離を求める関数
  auto dist = [&](int i, int j){
    //dx:x座標の差分
    double dx = x[i] - x[j];
    //dy:y座標の差分
    double dy = y[i] - y[j];
    //ユークリッド距離の計算結果を返す
    return sqrt(dx*dx+dy*dy);
  };
  //平均は合計/個数で、len=合計値
  double len = 0;
  //全部の辺について試す(重複しない全てのi-j間)
  rep(i,n){
    rep(j,i){
      //距離をlenに足していく
      len += dist(i,j);
    }
  }
  //各辺が何回使われるか
  //num=2*(n-1)!(計算前に係数の2で初期化)
  int num = 2;
  //(n-1)!の計算
  for(int i = n-1; i >= 1; i--){
    num *= i;
  }
  //分母のN!の計算
  int fact = 1;
  rep4(i,n){
    fact *= i;
  }
  //平均=Σ辺の長さ*2(n-1)!/n!が答えとなる
  double ans = (len*num)/fact;
  printf("%.10f\n",ans);
  return 0;
}
//n個の都市のある2点間の辺がn!通りの全都市の移動の中で何回使われるかをXと置くと、
//平均は全部の総和を個数で割ったものなので
//それぞれの辺について何回使われるか(X)にその辺の長さをかけたものを足し合わせたら
//全部の総和になり、個数は順列全探索と同様にn!となるため計算できる
//それぞれの辺について何回使われるか(X)の合計が2(n-1)!になるのは
//Xがまずどの辺についても不変で(違いは長さくらいで対照的なので)
//合計をΣXとするとΣX=辺の本数*X=NC2*Xと、ΣX=(N-1)*N!という二つの式が立つ
//NC2*XはN頂点から2点選んで1つの辺ができるからで
//(N-1)*N!は一つの順列パターンのたどり方にn-1本の辺ができて
//それがn!通りの順列のパターンができるから
