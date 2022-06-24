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
  //クエリ処理
  rep(_,q){
    //x:頂点番号,k:距離(k以下の数を答える)
    int x, k;
    cin >> x >> k;
    //0indexed
    x--;
    //k回以内の移動でxから辿れる頂点を格納する配列(setを使うと重複削除の手間が省けるが低数倍が少し重くなる)
    vector<int> vs;
    //k回以内で移動できる頂点を探索するdfs(u:今見ている頂点,depth:xからの移動回数)
    auto dfs = [&](auto f, int u, int depth) -> void {
      //k回以内の移動でuに来れたのでvsにuを格納
      vs.push_back(u);
      //ベースケース(k回目の移動でuに訪れたならもう移動できないので再帰元に戻る)
      if(depth == k){
        return;
      }
      //uから訪れられる頂点全てに再帰する(この過程で重複を含む)
      for(int v : g[u]){
        f(f,v,depth+1);
      }
    };
    //頂点xからdfsを開始
    dfs(dfs,x,0);
    //重複削除の下準備でsort
    sort(all(vs));
    //重複削除(erase,unique)
    vs.erase(unique(all(vs)),vs.end());
    //k回以内で辿れる頂点の番号(1indexed)の総和
    int ans = 0;
    //k回以内で訪れられる頂点全てについて処理
    for(int v : vs){
      //答えに頂点番号を1indexedに戻して加算
      ans += v + 1;
    }
    printf("%d\n",ans);
  }
  return 0;
}
//dfsver
//次数が3の無向グラフで3回以内に辿れる頂点が少ないことを利用して
//条件を満たさなくなったら打ち切るdfsを処理する
