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
using P = pair<int,int>;
using TP = tuple<int,int,int>;
template<typename Tx, typename Ty>Tx dup(Tx x, Ty y){return (x+y-1)/y;}
void chmin(int &x, int y){ x = min(x,y); }
void chmax(int &x, int y){ x = max(x,y); }
void chmin(ll &x, ll y){ x = min(x,y); }
void chmax(ll &x, ll y){ x = max(x,y); }
int main(){
  int n;
  cin >> n;
  //g[i]:頂点iを始点とする辺の情報(fi:終点,se:辺の長さの偶奇)
  vector<vector<P>> g(n);
  rep(i,n-1){
    //辺iの始点u,終点v,距離w
    int u, v, w;
    cin >> u >> v >> w;
    //0indexed調整
    u--; v--;
    //辺の長さの偶奇だけが必要なので%2する
    w %= 2;
    //辺の情報を格納(無向辺なのでu,v両方に格納)
    g[u].emplace_back(v,w);
    g[v].emplace_back(u,w);
  }
  //ans[i]:頂点iを何色に塗るか(-1の場合まだ訪れていないことを示す)
  vector<int> ans(n,-1);
  //頂点0(bfsの始点)を0で塗ることにする
  ans[0] = 0;
  //fi:u,se:old
  queue<P> que;
  //bfsの始点である頂点0をqueに格納(0の前に訪れた辺はないので-1)
  que.push(P(0,-1));
  //bfs
  while(que.size()){
    //queの先頭を取り出す
    P now = que.front();
    //先頭の削除
    que.pop();
    //u:今見ている頂点
    int u = now.first;
    //old:uの前にいた頂点
    int old = now.second;
    //uから1回で辿れる頂点について処理
    //(v:uからの行き先,w:距離の偶奇)
    for(auto [v,w] : g[u]){
      //着た方向に戻る遷移の回避
      if(v == old){
        continue;
      }
      //すでに訪れた頂点への遷移の回避
      if(ans[v] != -1){
        continue;
      }
      //パリティが一致ならuとvの塗る色を一致させる
      if(w % 2 == 0){
        ans[v] = ans[u];
      }else {
        //パリティが一致しないならu,vの塗る色を変える
        ans[v] = !ans[u];
      }
      //新たに向かう頂点vをuとして、元いた頂点uをoldとしてqueにpushする
      que.push(P(v,u));
    }
  }
  //色の出力
  rep(i,n){
    cout << ans[i] << endl;
  }
  return 0;
}
