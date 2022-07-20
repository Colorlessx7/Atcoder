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
  //個数
  int cnt = 0;
  //順列全探索
  do{
    //n頂点の移動なのでn-1回の移動回数分回す
    rep(i,n-1){
      //順列のi番目とi+1番目がさす座標間のユークリッド距離を計算し合計に足す
      len += dist(p[i],p[i+1]);
    }
    //順列一パターンを処理したので個数を+1する
    cnt++;
  }while(next_permutation(all(p)));
  //合計/個数を計算
  double ans = len/cnt;
  printf("%.10f\n",ans);
  return 0;
}
