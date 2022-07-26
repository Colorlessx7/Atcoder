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
// Coodinate Compression
// https://youtu.be/fR3W5IcBGLQ?t=8550
template<typename T=int>
//座標圧縮用のライブラリ
struct CC {
  //初期化済みかどうかのbool変数(defaultは未初期化でコンストラクタでfalseになる)
  bool initialized;
  //座標圧縮配列
  vector<T> xs;
  //コンストラクタ
  CC(): initialized(false) {}
  //引数xを座標圧縮配列xsの末尾に格納する
  void add(T x) { xs.push_back(x);}
  //座標圧縮処理初期化
  void init() {
    //昇順に並べる(後に重複削除をするため)
    sort(xs.begin(), xs.end());
    //重複削除
    xs.erase(unique(xs.begin(),xs.end()),xs.end());
    //init関数で初期化したためtrueに
    initialized = true;
  }
  //引数xが何番目かを調べる関数(昇順に0indexedで何番目かが設定される)
  int operator()(T x) {
    //座標圧縮初期化をしていないなら行う
    if (!initialized) init();
    //upper_boundで得たindex-1としておくとxsに登録されていない値でも辻褄が合いやすい
    return upper_bound(xs.begin(), xs.end(), x) - xs.begin() - 1;
  }
  //xs配列のi(:index)番目の値を返す関数
  T operator[](int i) {
    //座標圧縮初期化をしていないなら行う
    if (!initialized) init();
    //xsのi番目の値を返す
    return xs[i];
  }
  //座標圧縮配列のサイズを答える関数
  int size() {
    //座標圧縮初期化をしていないなら行う
    if (!initialized) init();
    //座標圧縮配列xsのサイズを答える
    return xs.size();
  }
};
//引数xの配列を座標圧縮してBITで転倒数を求める関数
ll f(vector<int> x){
  //引数xのサイズをnとする
  int n = x.size();
  //座標圧縮構造体の呼び出し
  CC cc;
  //構造体ccの座標圧縮配列xsに配列xの各要素を格納する
  rep(i,n){
    cc.add(x[i]);
  }
  //座標圧縮後の配列のサイズをmとする
  int m = cc.size();
  //転倒数を求めるためサイズmのBITの宣言
  fenwick_tree<int> d(m);
  //xの転倒数
  ll res = 0;
  //xの転倒数を求める
  //O(N),全体O(NlogN)
  rep(i,n){
    //xのi番目の要素が座標圧縮配列xsの何番目の要素かをaとする
    //a(0indexed)
    int a = cc(x[i]);
    //転倒数はi<jとして2つの数字を選択した時の値Ai,AjがAi>Ajとなるi,jの組み合わせの総数
    //xのi番目の要素(座標圧縮後のa番目)を追加した時に増える転倒数は
    //すでにBITに格納されているi個の要素の中のaより大きい数の個数分増えるので
    //全体iから新規追加のa以下の個数d.sum(0,a+1)を引いたものがaを追加した時の転倒数の
    //増加量になるのでこれをresに加算する
    //d.sum(0,a+1)は[0,a]の範囲の総和を返す(O(logN))
    res += i - d.sum(0,a+1);
    //BITにa番目の要素が追加されたのでa番目の要素に1を足す
    d.add(a,1);
  }
  //転倒数を返す
  return res;
}
int main(){
  //球の個数
  int n;
  cin >> n;
  //c[i]:球iの色,x[i]:球iの数字
  vector<int> c(n),x(n);
  rep(i,n){
    cin >> c[i];
  }
  rep(i,n){
    cin >> x[i];
  }
  //key:球の色,value:色keyの球に書かれた数字
  map<int,vector<int>> mp;
  //mapに球の色と数字の情報を入力
  rep(i,n){
    mp[c[i]].push_back(x[i]);
  }
  //全体の転倒数(色を無視した時の転倒数)を答えとする
  ll ans = f(x);
  //全体の転倒数から同じ色の球の集合の転倒数それぞれを引いていく
  for(auto p : mp){
    ans -= f(p.second);
  }
  cout << ans << endl;
  return 0;
}
//座標圧縮をしてからBITで転倒数を求める問題
//色を考慮しなかった状態の転倒数から色で分けた各数列の転倒数を引いたものが答えとなる
//
