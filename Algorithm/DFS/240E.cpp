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
//根付き木の頂点数
ll n;
//根付き木の辺の接続に関する配列
vector<vector<ll>> g;
//問題の[l,r]のl,st[i]でi番目の頂点についての[li,ri]のliに対応
vector<ll> st;
//上のrについて
vector<ll> ed;
//探索で見つけた葉につける番号(lになる)
//次見つけた葉が何番目の葉かを示す(1indexed)
ll cnt = 1;
//dfs処理部分
//dfsしながら葉の区間[l,r]を決めていく
//u:今見ている頂点番号,bef:どの頂点からuに遷移したか(uの根の番号)
void dfs(ll u, ll bef){
  //頂点uの区間[l,r]のlをcntとする
  //dfsで頂点uに辿り着いた時点でuを部分木の根とした時の葉の探索はまだできていない
  //(uが葉かの判定もできていない)からとりあえずまだ見つかっていないcnt番目の葉から
  //何個かの葉がuの部分木内に存在するため、その最小番目の葉の番号であるcntが区間のlとなる
  st[u] = cnt;
  //uから1回で辿れる頂点にdfsする範囲ループ(根に戻るのを除く)
  for(ll v : g[u]){
    //根に戻る遷移を回避する処理
    if(v == bef){
      continue;
    }
    //uから遷移できる頂点vについてdfs
    dfs(v,u);
  }
  //間違った点1
  //今見ている頂点uが葉であるか判定
  //g[u].size()==1で頂点uの次数が1であるか確認する(次数が1なら根と繋がる辺しかない)
  //bef!=-1の判定をする理由は、頂点0から繋がる辺が1つのみで、その辺から繋がった先の頂点から
  //たくさんの頂点に辺が繋がっているような根付き木の場合に、
  //根である頂点0を葉と判断させないようにするため
  if(g[u].size() == 1 && bef != -1){
    //今見ている頂点が葉だったので次見つけた葉の番号を1進める
    cnt++;
  }
  //間違った点2
  //[l,r]のrの更新はすでに見つけた葉の数を格納すれば良いので
  ///次見つけた葉が何番目の葉かを示すcntから1引いたものがrとなる
  //dfsにより関数のこの部分に到達した時点で頂点uから辿り着ける頂点には全て到達している
  //(部分木に何番目の葉(l)から何番目の葉(r)まで存在するかがわかっている状態)
  ed[u] = cnt - 1;
  //void関数なのでここでreturnはいらない
}
int main(){
  cin >> n;
  //グローバル変数では入力を受け取っていないnなどの変数で配列を宣言しても
  //segmantationfaultを起こすのでmain関数内でresizeしておく必要がある
  g = vector<vector<ll>>(n);
  st = vector<ll>(n);
  ed = vector<ll>(n);
  //根付き木の辺の設定
  rep(i,n-1){
    ll u, v;
    cin >> u >> v;
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  //dfsの開始
  dfs(0,-1);
  //出力部
  rep(i,n){
    cout << st[i] << " " << ed[i] << endl;
  }
  return 0;
}
//dfs問題
//貪欲に考えると葉の個数がmax(L1...LN,R1...RN)の最小値となる
//葉の登場順に番号をつけて行って、葉の[l,r]をその番号をxとすると[x,x]として
//部分木の根の[l,r]をその部分木の葉の番号xの中の最小をl,最大をrとして更新し続けたものが答えとなる
//
