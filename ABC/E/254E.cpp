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
int main(){
  //n:頂点数,m:辺の本数
  int n, m;
  cin >> n >> m;
  //g:無向グラフ
  vector<vector<int>> g(n);
  //辺の入力
  rep(i,m){
    int a, b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  //q:クエリ数
  int q;
  cin >> q;
  //ある頂点からの距離を格納
  //(クエリ処理ループ内で宣言しないのはコンストラクタでnに対しての線形時間がかかりO(n)でTLEするため)
  //(あと頂点数nに対して、dist[i]を変化させるのが1クエリで1+3+6+12=22個で
  //変化させた場所を都度-1に戻した方が早い)
  vector<int> dist(n,-1);
  //クエリ処理
  rep(_,q){
    //x:頂点番号,k:距離(k以下の数を答える)
    int x, k;
    cin >> x >> k;
    //0indexed
    x--;
    //bfs用のqueue
    queue<int> que;
    //開始点xをpush
    que.push(x);
    //開始点xの距離を0に
    dist[x] = 0;
    //k回以内の移動で辿り着ける頂点を格納する配列
    //(distと違い、sizeが0なので定数時間O(1)でコンストラクタを呼べる)
    vector<int> vs;
    //bfsの開始(普通bfsはO(N)だがk回以内の移動で打ち切るのでO(22))
    while(que.size()){
      //queueの先頭をuに格納
      int u = que.front();
      //queueの先頭を削除
      que.pop();
      //uはk回以内に訪れることができる頂点なのでvsに格納
      vs.push_back(u);
      //k回移動した先がuならもう移動できないのでコンティニュー
      if(dist[u] == k){
        continue;
      }
      //まだ移動できるならuから辿れる頂点vを処理
      for(int v : g[u]){
        //vがすでに訪れた頂点ならコンティニュー(出戻り回避)
        if(dist[v] != -1){
          continue;
        }
        //上の条件を抜けたらvがuから出戻りなしで一回で辿れる頂点になるので距離をuの距離+1にする
        dist[v] = dist[u] + 1;
        //新たにuから辿れる頂点vをqueueにpush
        que.push(v);
      }
    }
    //k回以内で辿れる頂点の番号(1indexed)の総和
    int ans = 0;
    //k回以内で辿れる頂点の総数
    int vsz = vs.size();
    //k回以内の移動で訪れられる頂点のみをループ処理
    //(ここで全頂点について-1に戻すような処理にしているとO(Q*22)がO(QN)になりTLE)
    rep(i,vsz){
      //答えに頂点番号を1indexedに戻して加算
      ans += vs[i] + 1;
      //訪れた頂点の距離を-1に初期化する
      dist[vs[i]] = -1;
    }
    cout << ans << endl;
  }
  return 0;
}
//bfs問題
//次数が3の無向グラフで3回以内に辿れる頂点が少ないことを利用して
//条件を満たさなくなったら打ち切るbfsを処理する
