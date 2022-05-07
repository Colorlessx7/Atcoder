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
const ll INF = 1LL << 60;
//辺についてを管理するデータ構造
//to:辺の向かう先,cost:辺の移動にかかるコスト
struct edge{ll to, cost;};
//ダイクストラ法を処理する構造体
struct graph{
  //頂点数
  ll V;
  //重み付きグラフ(G[i]でi頂点からの辺の情報を示す)
  vector<vector<edge>> G;
  //dijkstra関数で求める頂点sからの最短距離を格納する配列
  vector<ll> d;
  //コンストラクタ(初期化はinit関数で)
  graph(ll n){
    init(n);
  }
  //コンストラクタの初期化を処理する関数(n:頂点数)
  void init(ll n){
    //頂点数nをVに格納
    V = n;
    //重み付きグラフGのサイズを頂点数で調整
    G.resize(V);
    //頂点sからの距離を示す配列のサイズを頂点数で初期化
    d.resize(V);
    //全頂点の頂点sからの最短距離をINFで初期化
    rep(i,V){
      d[i] = INF;
    }
  }
  //重み付きグラフGに辺を追加する処理
  //(s:辺の始点,t:辺の終点,cost:辺の移動にかかるコスト)
  void add_edge(ll s, ll t, ll cost){
    //辺についての構造体edge(変数名e)を初期化
    edge e;
    //辺の終点tをtoに、辺のコストをcostに格納する
    e.to = t, e.cost = cost;
    //頂点sからの辺の情報eを重み付きグラフGに追加する
    G[s].push_back(e);
  }
  //ダイクストラ法を実行する関数(O(E+V)logV)
  //始点から探索を開始し
  void dijkstra(ll s){
    //全頂点をINFで初期化する処理
    //(ダイクストラ法をそれぞれ別の頂点で2回以上行う場合のために必要)
    rep(i,V){
      d[i] = INF;
    }
    //頂点sからの距離なのでsへの距離を0で初期化する
    d[s] = 0LL;
    //優先度付きqueueを用いて候補の中から距離が最小のものを求められるので
    //計算量をO(v)からO(logv)に落とすことができる
    //pairはfirstがコスト,secondが頂点番号となっている
    //3つ目のgreaterでqueueの中身を昇順にして最小値の取得を簡単に処理できる
    //おそらく比較関数を使用していないのでpairのfirst、secondの順に基準として昇順に並ぶ
    priority_queue<P,vector<P>, greater<P>> que;
    //始点ノード(コスト0,頂点番号s)から探索を開始
    que.push(P(0LL,s));
    //queの中身を全て処理するまで処理
    while(que.size()){
      //queの最小のpairをpに格納し、queの先頭の情報を削除
      P p = que.top(); que.pop();
      //よく使うのでpのsecondの頂点番号(現在の頂点)をvに退避
      ll v = p.second;
      //既にvに到達してsからの最小コストd[v]が確定し、さらにvから移動できる頂点の情報のpairを
      //queに格納したようなvに対し、別の経路で遠回りしてvに辿り着いた場合は
      //既に決まったsからvへの最小コストd[v]を遠回りでvに辿り着いた時のコストp.secondが
      //超えているのでコンティニューで以降の処理をスキップする
      //(これにより以降の経路に対して既に最短距離でなくなったp.secondが影響しなくなる)
      if(d[v] < p.first) continue;
      //vから1回で行ける頂点に対しての処理
      for(auto e : G[v]){
        //d[e.to]:隣接頂点の現時点での頂点sからの累計コスト(e.toがvから1回で行ける頂点)
        //d[v]+e.cost:新しい累計コスト
        //(d[v]:今の頂点までの累計コスト,e.cost:e.toへ向かうためのコスト)
        //新しい累計コストの方が小さかった場合以下の処理を行う
        if(d[e.to] > d[v] + e.cost){
          //隣接ノードの累計コストをより小さい新しい累計コストで更新
          //最短経路を小さい順に貪欲に決めていくためこの更新は各頂点1回ずつだと思われる
          d[e.to] = d[v] + e.cost;
          //新たに最短経路となったe.toまでの累計コストd[e.to]と向かう頂点e.toのpairを
          //queに格納
          //未確定リストのソート(que内で昇順に並ぶ)
          que.push(P(d[e.to],e.to));
        }
      }
    }
  }
};
int main(){
  //n:頂点数
  ll n;
  cin >> n;
  //頂点数nの重み付きグラフgを宣言
  graph g(n);
  //無向辺の個数回ループ
  rep(i,n-1){
    //a,b:辺の頂点番号,c:辺のコスト
    ll a, b, c;
    cin >> a >> b >> c;
    //頂点番号の0indexed調整
    a--; b--;
    //無向辺なのでaからbとbからaの両方辺をはる
    g.add_edge(a,b,c);
    g.add_edge(b,a,c);
  }
  //q:クエリ数,k:経由する頂点番号
  ll q, k;
  cin >> q >> k;
  //頂点番号の0indexed調整
  k--;
  //頂点kを開始点としてダイクストラ法の実行
  g.dijkstra(k);  
  //クエリ処理(O(q))
  rep(i,q){
    //x,y:辺の頂点番号
    ll x, y;
    cin >> x >> y;
    //頂点番号の0indexed調整
    x--; y--;
    //d[x]:x-kの最短距離,d[y]:k-yの最短距離
    //これらを足し合わせた物が答え(O(1))
    cout << g.d[x] + g.d[y] << endl;
  }
  return 0;
}
