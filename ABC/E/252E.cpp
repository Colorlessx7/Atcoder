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
using P = pair<ll,int>;
using TP = tuple<int,int,int>;
template<typename Tx, typename Ty>Tx dup(Tx x, Ty y){return (x+y-1)/y;}
void chmin(int &x, int y){ x = min(x,y); }
void chmax(int &x, int y){ x = max(x,y); }
void chmin(ll &x, ll y){ x = min(x,y); }
void chmax(ll &x, ll y){ x = max(x,y); }
//ダイクストラの辺の情報の構造体
struct Edge {
  //to:頂点aからの辺の向かう先、cost:距離、id:辺の情報(i番目の辺である)
  int to, cost, id;
  //コンストラクタ
  //配列宣言時メモリ確保,emplace_backで入力が与えられてそれで初期化される
  Edge(int to, int cost, int id):
    to(to), cost(cost), id(id) {}
};
int main(){
  //n:頂点数,m:辺の本数
  int n, m;
  cin >> n >> m;
  //g[a]:頂点aからの辺の情報
  //g[a][j]:頂点aからの辺のj番目の辺の情報
  //to:頂点aからの辺の向かう先、cost:距離、id:辺の情報(i番目の辺である)
  vector<vector<Edge>> g(n);
  //辺の情報の入力
  rep(i,m){
    //a:辺iの始点,b:辺iの終点,c:辺iの距離
    int a, b, c;
    cin >> a >> b >> c;
    //0indexed調整
    a--; b--;
    //aからの辺の情報を追加する
    g[a].emplace_back(b,c,i+1);
    //bからの辺の情報を追加する
    g[b].emplace_back(a,c,i+1);
  }
  //距離の初期値(最大初期化)
  const ll INF = 1e18;
  //dist[i]:頂点0からiまでの最短距離(最大初期化)
  vector<ll> dist(n,INF);
  //ダイクストラ木の頂点iがどの辺から辿ってくるのが最短か(辺の番号,取り得ない値で初期化)
  vector<int> from(n,-1);
  //ダイクストラのためのPQ(fiの距離について昇順に並ぶ)
  priority_queue<P,vector<P>,greater<P>> q;
  //頂点0(1)からの距離なので始点である頂点0の距離を0初期化する
  dist[0] = 0;
  //始点である頂点0の情報をPQに格納(最短距離0、出発元の頂点番号0)
  q.emplace(0,0);
  //ダイクストラの実行
  while(q.size()){
    //PQの先頭を取り出し、dを距離,vを現在の頂点番号として扱う
    auto [d,v] = q.top(); q.pop();
    //PQから取り出したものが最新の情報であるかどうかを確認
    //vへの最短距離がdでない場合、qにpushした後に最短が更新されているため
    //qにpushした時の頂点のたどり方が最短でなくなっているのでコンティニューして捨てる
    //(ここを忘れると実行時間が入力によっては間に合わないことがある)
    if(dist[v] != d){
      continue;
    }
    //頂点vから1つの辺で辿れる頂点について処理
    //u:頂点vから向かう先,cost:v-u間の距離,id:何番目の辺かの情報
    for(auto [u,cost,id] : g[v]){
      //nd:頂点0から最短距離でvまで辿り、今見ている辺でuまで辿る時の距離
      ll nd = d+cost;
      //現状の頂点0からuまでの距離がnd以下なら今見ている辺を辿ってuに向かう経路は
      //最短距離の経路ではないのでコンティニューして捨てる
      if(dist[u] <= nd){
        continue;
      }
      //uへの最短距離をndで更新
      dist[u] = nd;
      //辺idを辿って頂点uに行くのが最短になるため最短距離の辺のたどり方
      //を格納する配列fromの頂点uの情報をidで更新
      from[u] = id;
      //辺idを辿るたどり方が最短を更新したので
      //最短距離ndと頂点vから向かった先の頂点の情報uをqにpushする
      q.emplace(nd,u);
    }
  }
  //2番目(i=1)の頂点以降の頂点にどの辺を辿って到達すれば最短かがfromに格納されているので
  //それを順に出力する
  replr(i,1,n){
    cout << from[i] << endl;  
  }
  return 0;
}
//ダイクストラ法を使ってダイクストラ木を求める問題
