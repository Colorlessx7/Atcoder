#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(ll i = 0; i < N; i++)
#define rep2(i,N) for(ll i = 1; i <= N; i++)
#define rep3(i,N) for(ll i = N - 1; i >= 0; i--)
#define rep4(i,N) for(ll i = N; i > 0; i--)
#define replr(i,l,r) for(ll i = l; i < r; i++)
#define reprl(i,l,r) for(ll i = l; i >= r; i--)
#define all(x) x.begin(),x.end() 
#define allr(x) x.rbegin(),x.rend() 
using ll = long long;
using P = pair<ll,ll>;
void chmin(ll &x, ll y){ x = min(x,y); }
void chmax(ll &x, ll y){ x = max(x,y); }
int main(){
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n){
    cin >> a[i];
  }
  //a[i]の制約を少し超えそうなくらいのdsuのサイズを用意
  const ll m = 200005;
  //dsuのコンストラクタ サイズm
  dsu d(m);
  //回文の一致させないといけない2要素についての辺を張る
  //(配列の先頭は0,末尾はn-1なので先頭からi足して末尾からi引いたものが回文の一致させる関係となる)
  //下の書き方だと2重に辺を貼ることになるがdsuでは特に問題はない
  rep(i,n){
    d.merge(a[i],a[n-1-i]);
  }
  //dsuで必要な最小連結操作数
  ll ans = 0;
  //dsuの各頂点について回す
  rep(i,m){
    //頂点番号iが連結成分の親でないならコンティニュー
    if(d.leader(i) != i){
      continue;
    }
    //頂点番号iが連結成分の親なら連結成分の要素-1を最小連結操作数に足す
    ans += d.size(i) - 1;
  }
  //出力
  cout << ans << endl;
  return 0;
}
//素集合データ構造unionfindで解く問題
//計算量は O(N) から O(NlogN) 程度
//(また連結成分ごとに、DFS(深さ優先探索)やBFS(幅優先探索)を行うことでも解ける)
//回文とはi番目とn-1-i番目が一致しているもののことを言う
//回文に登場する数字自体を頂点として、回文の同じ位置関係(i,n-1-i)のものに辺を張って
//(最終的に同じ数になっていないといけない数字の集合の)無向グラフとする
//例として、1を5に5を3にしないといけない場合1を5にすると5に1の部分が吸収合併されて
//そこから5を3にすると1の部分も3になるため上のように辺を張った後に各連結成分に対して
//元の状態から何回で1つの連結成分の形にできるかの数の合計が答えとなる
//元の状態から1つの連結成分にするために必要な操作数は要素数-1回となる
//(一回の操作で2つを連結させると全体の要素数が1減るため)
