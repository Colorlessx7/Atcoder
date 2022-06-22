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
  //頂点数
  int n;
  cin >> n;
  //x[i]:i人目の人の嫌いな人(functional graphのf(i)=x[i]となる)
  vector<int> x(n);
  rep(i,n){
    cin >> x[i];
    //0indexed
    x[i]--;
  }
  //c[i]:i人目の嫌いな人が先に報酬を得た場合に増加する不満度
  vector<int> c(n);
  rep(i,n){
    cin >> c[i];
  }
  //scc:有向グラフを強連結成分分解する(n頂点0辺のグラフ)
  scc_graph sc(n);
  //不満度の最小
  ll ans = 0;
  //全頂点について辺の連結を行う
  //(iからx[i]への有向辺)
  rep(i,n){
    sc.add_edge(i,x[i]);
  }
  //autoの中身(kの型)はvector<vector<int>>
  //k[i][j]:分解後の頂点集合iのj番目の頂点番号
  //sccの実行により、以下の条件を満たすような、「頂点のリスト」のリストを返す
  //全ての頂点がちょうど1つずつ、どれかのリストに含まれる
  //内側のリストと強連結成分が一対一に対応する。リスト内での頂点の順序は未定義
  //リストはトポロジカルソートされている
  //(異なる強連結成分の頂点u,vについて、uからvに到達できる時、uの属するリストはvの属するリストよりも前)
  auto k = sc.scc();
  //ks:sccで得られた頂点のリストのリストのサイズ(強連結成分分解後の頂点集合の量)
  int ks = k.size();
  //全頂点集合について処理
  rep(i,ks){
    //分解後の頂点集合一つの中の頂点数
    int kis = k[i].size();
    //分解後の頂点集合の頂点数が1以下ならコンティニュー(頂点1個ならサイクルになっていないため)
    if(kis <= 1){
      continue;
    }
    //サイクル内の不満度の最小を求める
    int mn = 1001001001;
    //サイクル内の各頂点の不満度のminをとる
    rep(j,kis){
      chmin(mn,c[k[i][j]]);
    }
    //サイクル内の不満度の最小を答えに足す
    ans += mn;
  }
  cout << ans << endl;
  return 0;
}
//問題の条件をグラフに落とし込んで解く問題
//問題の条件からfunctional graphに落とし込むことができる
//sccで解いたver
