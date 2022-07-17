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
//頂点の座標に関する構造体
struct V{
  //Vのメンバ変数(x,y)の各値を格納
  ll x, y;
  //コンストラクタ
  //配列の宣言時にメモリだけ確保して
  //最初のx,yの入力がなされた時点でその値で初期化される
  V(ll x = 0, ll y = 0):x(x),y(y) {}
};
int main(){
  //頂点数
  int n;
  cin >> n;
  //開始点と終点の頂点情報のコンテナ宣言(この状態でメンバ変数にアクセスするとエラー)
  V s, t;
  //開始点と終点の頂点のメンバ変数を入力(この情報でコンストラクタにより変数の初期化がされる)
  cin >> s.x >> s.y >> t.x >> t.y;
  //各頂点(円の中心点)の座標の情報のリストの配列のコンテナ宣言
  //(この状態でメンバ変数にアクセスするとエラー)
  vector<V> o(n);
  //各円の半径についての配列
  vector<ll> r(n);
  //各円の情報の入力
  rep(i,n){
    cin >> o[i].x >> o[i].y >> r[i];
  }
  //入力xの二乗を返す関数
  auto pow2 = [](ll x){return x*x;};
  //頂点a-b間のユークリッド距離を求める関数
  auto dist = [&](V a, V b){
    return pow2(a.x-b.x) + pow2(a.y-b.y);
  };
  //si:頂点sを含む円の番号,ti:頂点tを含む円の番号
  int si = 0, ti = 0;
  //全円について頂点s,tを含むかどうか判定し、含むならsi,tiを更新する
  //(二つ以上含む点が存在するパターンがあるがdsuで判断できるため問題ない)
  rep(i,n){
    //円の中心の座標を(a,b),半径をr,調べる点Qの座標を(x,y)とすると
    //sqrt((x-a)^2+(y-b)^2)<rで円周上を除く円の内部にQが存在するか判定できる
    //円周上かどうかはsqrt((x-a)^2+(y-b)^2)=rで判定できる
    //sqrtだとdoubleに頼る必要があり、制約が10^18くらいで誤差が絶対発生するため
    //llで扱うため両辺を二乗する必要がある
    //左辺はsqrtが外れ、この式がdistに対応
    if(dist(s,o[i]) == pow2(r[i])){
      //sが円周上にある円のidがiなのでsiにiを格納
      si = i;
    }
    if(dist(t,o[i]) == pow2(r[i])){
      //tが円周上にある円のidがiなのでtiにiを格納
      ti = i;
    }
  }
  //円周が重なっている円のid同士を結合させるグラフ(頂点数nで宣言) 
  dsu uf(n);
  //円i,j間で交点が発生しているかについて判定する処理
  //(重複防止のためrep(i,n)rep(j,i)の形で回す)
  rep(i,n){
    rep(j,i){
      //円i-jの中心点間の距離をdとする
      ll d = dist(o[i],o[j]);
      //円i,jの半径をそれぞれr1,r2に格納
      ll r1 = r[i], r2 = r[j];
      //以降の判定で絶対値が出てきて、絶対値を外して考えるために大きい方をr2としておく
      if(r1 > r2){
        swap(r1,r2);
      }
      //二つの円の位置関係の式からi,jの円周上に交点が存在するか判定し、
      //交点が存在しないパターンを弾く
      //2つの円の半径をr1,r2、2つの円の中心間の距離をdとすると
      //位置関係5パターンはそれぞれ
      //・交点が存在しないパターン
      //離れている d>r1+r2
      //一方の円の内部にある d<abs(r1-r2)
      //・交点が存在するパターン
      //外接する d=r1+r2
      //内接する d=abs(r1-r2)
      //二点で交わる abs(r1-r2)<d<r1+r2 
      if(d > pow2(r1+r2)){
        continue;
      }
      if(d < pow2(r2-r1)){
        continue;
      }
      //上記の条件を満たさないなら円i,jの位置関係は残りの3パターンで
      //円i,jの円周上に交点が存在するためi,jをdsuで結合させる
      uf.merge(i,j);
    }
  }
  //si,tiが結合しているなら円周上を辿ってsからtに到達できる
  if(uf.same(si,ti)){
    cout << "Yes" << endl;
  }else {
    cout << "No" << endl;
  }
  return 0;
}
