const ll INF = 1LL << 60;
struct edge{ll to, cost;};
struct graph{
  ll V;
  vector<vector<edge>> G;
  vector<ll> d;
  graph(ll n){
    init(n);
  }
  void init(ll n){
    V = n;
    G.resize(V);
    d.resize(V);
    rep(i,V){
      d[i] = INF;
    }
  }
  void add_edge(ll s, ll t, ll cost){
    edge e;
    e.to = t, e.cost = cost;
    G[s].push_back(e);
  }
  void dijkstra(ll s){
    rep(i,V){
      d[i] = INF;
    }
    d[s] = 0LL;
    priority_queue<P,vector<P>, greater<P>> que;
    que.push(P(0LL,s));
    while(que.size()){
      P p = que.top(); que.pop();
      ll v = p.second;
      if(d[v] < p.first) continue;
      for(auto e : G[v]){
        if(d[e.to] > d[v] + e.cost){
          d[e.to] = d[v] + e.cost;
          que.push(P(d[e.to],e.to));
        }
      }
    }
  }
};
