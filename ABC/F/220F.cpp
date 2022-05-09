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
  //n:頂点数
  ll n;
  cin >> n;
  //根付き木の辺の接続に関するグラフ
  vector<vector<ll>> g(n);
  //t[i]:頂点iを部分木の根とした時のその部分木のサイズを示す
  vector<ll> t(n);
  //ans[i]:i頂点から別の頂点に行くまでに辿る辺の本数の合計
  vector<ll> ans(n);
  //辺の入力(いつもの)
  rep(i,n-1){
    ll a, b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  //基準となる根(頂点0)のSum(0~n-1)(dis(i,j))を求めて、それを返す関数
  //ついでに各頂点の部分木のサイズ(配列t)の前計算を行う
  //ラムダ式再帰(引数f:再帰用関数,v:今見ている頂点,p:今見ている頂点が一つ前にいた頂点(親))
  auto dfs1 = [&](auto& f,ll v, ll p=-1) -> ll {
    //res:頂点vの部分木内の頂点だけを見た時のSum(dis(i,j))(0初期化)
    ll res = 0;
    //dfsなので初めて頂点vを訪れた時に個々の処理を行う
    //頂点vの部分木のサイズはとりあえず頂点vを含んでいるため1としておく
    t[v] = 1;
    //頂点vから辺を1つだけ辿って行ける頂点について処理
    for(ll u : g[v]){
      //親に戻る遷移はしない
      if(u == p){
        continue;
      }
      //uからuの部分木内の各頂点までの距離をxとすると、uの根である頂点vから
      //それらの頂点までの距離は全てx+1となる(vはuの部分木の外側であるため)
      //xの合計がf(f,u,v)に対応し、これは頂点uの部分木内の頂点だけを見た時のSum(dis(i,j))である
      //+1の合計がt[u]に対応する(t[u]:uの部分木のサイズ)
      //再帰前はt[u]が更新されていないが再帰終了して戻ってくるタイミングでは更新されているので問題ない
      res += f(f,u,v) + t[u];
      //vの部分木の頂点である頂点uの部分木のサイズをvにたす
      t[v] += t[u];
    }
    //頂点vの部分木内の頂点だけを見た時のSum(dis(i,j))を再帰元に返す
    return res;
  };
  //根付き木の根である頂点0の全ての頂点にたどり着くまでに辿る辺の数をdfs1で求める
  ans[0] = dfs1(dfs1,0);
  //各頂点のSum(1..n)(dis(i,j))をdfsで決める処理
  auto dfs2 = [&](auto& f,ll v, ll p=-1) -> void {
    //頂点vから辺1つで辿れる頂点について処理
    for(ll u : g[v]){
      //親に戻る遷移はしない
      if(u == p){
        continue;
      }
      //ans[u]:uのSum(0~n-1)(dis(i,j)),ans[v]:vのSum(0~n-1)(dis(i,j))
      //t[u]:頂点uの部分木のサイズ(vからuに移動したときに
      //uから各頂点に向かう過程で、頂点にたどり着くために辿る辺の本数が1少なくなる頂点の数)
      //n-t[u]:頂点uの部分木でない頂点の個数(vからuに移動した時に
      //uから各頂点に向かう過程で、頂点にたどり着くために辿る辺の本数が1多くなる頂点の数)
      ans[u] = ans[v] + (n - t[u]) - t[u];
      //vから1回で辿れる頂点uのSum(1..n)(dis(i,j))を求められたので、
      //uから1回で辿れる頂点のSum(1..n)(dis(i,j))を求めるためにdfsを行う
      f(f,u,v);
    }
  };
  //dfs2を開始
  dfs2(dfs2,0);
  //出力部
  rep(i,n){
    //endlが重いのでprintfで出力
    printf("%lld\n",ans[i]);
  }
  return 0;
}
//dfsをして事前処理をした後にdfsで頂点が変わった場合の法則性から計算量を落とす問題
//ある頂点から別の全ての頂点にたどり着くまでに辿る辺の数を求めた後に、
//その頂点から1つの辺のみで辿れる頂点についての別の全ての頂点にたどり着くまでに辿る辺の数を考える上で
//辿る辺の本数の変化を考えると開始点となる頂点の部分木の頂点は全て本数が-1されて、
//開始点となる頂点の部分木でない頂点は全て本数が+1されることがわかる
//この考えから各頂点の部分木のサイズと根のSum(1..n)(dis(i,j))をdfsで求めて、
//その後に、一回で辿れる頂点から順にSum(1..n)(dis(i,j))をdfsで決めていくことができる

//別解:全方位木dp
//
