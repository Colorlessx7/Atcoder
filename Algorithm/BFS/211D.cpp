#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep3(i,N) for(int i = N - 1; i >= 0; i--)
#define rep4(i,N) for(int i = N; i > 0; i--)
#define all(x) x.begin(),x.end() 
typedef long long ll;
using P = pair<int,int>;
using mint = modint1000000007;
int main(){
    int n, m;
    cin >> n >> m;
    //グラフの二次元配列
    vector<vector<int>> G(n);
    rep(i,m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        //無向グラフの持ち方
        //隣接する頂点のリストを各頂点に持たせる
        //ここで辺を張る
        G[a].push_back(b);
        G[b].push_back(a);
    }
    //未到達ならこの数字がdistに格納されている
    const int INF = 1001001001;
    //グラフの各頂点が1から何回で行けるかを格納
    vector<int> dist(n,INF);
    queue<int> q;
    //最初に1からスタートなのでqueueに1(0)をpush
    q.push(0);
    //1(0)にはすでにいる(0で行ける)ので0を格納
    dist[0] = 0;
    //queueで取り出された頂点の順番を保持するリスト DPで使用
    vector<int> vs;
    //BFS queueが空になるまで
    while(q.size()){
        //到達した頂点をqueueから取り出す
        int v = q.front();
        //忘れずqueueの先頭を削除
        q.pop();
        vs.push_back(v);
        //隣接する頂点を全部見る
        for(int u : G[v]){
            //その頂点にもう到達しているのならスルー
            if(dist[u] != INF){
                continue;
            }
            //頂点vから1回で頂点uに辿り着いたので
            //頂点uに到達するのに必要な回数は頂点vのそれ+1
            dist[u] = dist[v] + 1;
            //その頂点uから行ける頂点を確認するためにpush
            q.push(u);
        }
    }
    //DP処理 距離が1増えるような辺だけ使った経路(最短経路)を数える
    vector<mint> dp(n);
    dp[0] = 1;
    //配るdp queueで取り出された頂点の順番でDPを更新
    for(int v : vs){
        for(int u : G[v]){
            //条件を満たすならuはvから1で進める最短経路なので
            //1からvまでの最短経路の数をuまでの最短経路の数に+
            //他のvからも最短経路(同じ長さ)でuに到達できる可能性がある
            if(dist[u] == dist[v] + 1){
                dp[u] += dp[v];
            }
        }
    }
    //頂点1(0)からn(n-1)までの最短経路の数が答え
    mint ans = dp[n-1];
    cout << ans.val() << endl;
    return 0;
}
//BFSの後にDPをして解く問題
//グラフの最短路を考えるときはBFSをするといい
//BFSをして何回でその頂点に辿り着けるかを層分けすると
//層を距離2以上で繋ぐ辺が存在しなくなり、かつ層内の辺を考える必要がなくなる
//つまり、隣接する層の間にのみ辺がある状態になる
//するとこのグラフが有向グラフの中のDAGになる
//今回はこのDAGの有向辺を1から辿り、nに辿り着く経路数を求めれば良くなる
//これはDPの典型なのでDPでとく
