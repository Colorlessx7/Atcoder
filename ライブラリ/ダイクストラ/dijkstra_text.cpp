//struct:dijkstraでやれることリスト
//add_edge(a,b,c):aからbへ向かうコストcの辺を張る
//dijkstra(s):頂点sからの各頂点への最短距離を計算する
//get(t):sからtまでの最短経路の頂点番号を調べる
//retpath():get(t)で作ったsからtまでの最短経路の頂点番号を出力する


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
  //一つ前に訪れた頂点を格納する配列
  vector<ll> prev;
  //ダイクストラの経路復元用の配列
  vector<ll> path;
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
    //頂点sからの距離を示す配列のサイズを頂点数で要素をINFで初期化
    d.resize(V,INF);
    //一つ前に訪れた頂点の番号の配列をサイズを頂点数、要素を-1で初期化
    prev.resize(V,-1);
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
          //e.toの一つ前に訪れた頂点vをprev[e.to]に格納
          prev[e.to] = v;
          //新たに最短経路となったe.toまでの累計コストd[e.to]と向かう頂点e.toのpairを
          //queに格納
          //未確定リストのソート(que内で昇順に並ぶ)
          que.push(P(d[e.to],e.to));
        }
      }
    }
  }
  //頂点sから頂点tまでの経路復元用の関数(引数t:ゴールの頂点番号)
  void get(ll t){
    //都度経路を初期化する
    path.clear();
    //開始点sの一つ前の頂点prev[s]はひとつ前が存在しないため
    //必ず-1となるので開始点までを逆順にループする処理になっている
    for(ll i = t; i != -1; i = prev[i]){
      //頂点iをpathに格納
      path.push_back(i);
    }
    //逆順になっているので反転させる
    reverse(all(path));
  }
  //経路を出力する関数(getで入手したs-tの経路を出力する)
  void retpath(){
    //pathの配列のサイズをfに格納
    ll f = path.size();
    //経路を順に出力
    rep(i,f){
      //頂点番号は1indexedなのを処理上で0indexedにしていることが多いので+1している
      cout << path[i] + 1 << endl;
    }
  }
};
