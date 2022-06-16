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
  //グラフの接続情報
  //es[i].first:i番目の辺を取り除いた時の報酬(コスト)
  //es[i].second.first:i番目の辺で結合している頂点の番号1
  //es[i].second.second:i番目の辺で結合している頂点の番号2
  vector<pair<int,P>> es;
  //辺の情報の入力
  rep(i,m){
    //a,b:辺で結合している頂点の番号
    //c:その辺を取り除いた時に得られるコスト
    int a, b, c;
    cin >> a >> b >> c;
    //0indexed調整
    a--; b--;
    //辺の情報としてesに追加
    es.emplace_back(c,P(a,b));
  }
  //辺の情報をsortする(辺のコストが昇順に並び、コストが一致なら
  //辺で結合している頂点の番号が昇順に並ぶ(fi,seの順に優先))
  sort(all(es));
  //報酬
  ll ans = 0;
  //unionfind(n頂点)
  dsu d(n);
  //全辺の情報についてループ
  for(auto [c,e] : es){
    auto [a,b] = e;
    //c:その辺を取り除いた時に得られるコスト
    //a,b:辺で結合している頂点の番号
    //cが0未満かa,bが未結合なら結合させる(cが0未満のものを消すと報酬がマイナスなので結合させる)
    //(消した時に報酬が少ない順に辺の情報が並んでいて、
    //条件から全頂点が連結成分にならないといけないので、連結していないなら連結させる)
    if(c < 0 || !d.same(a,b)){
      //a,bを連結させる
      d.merge(a,b);
    }else {
      //今見ている辺を取り除き、コストcを報酬として得る
      ans += c;
    }
  }
  cout << ans << endl;
  return 0;
}
//dsuなのでsame(a,b)はa-bに辺が繋がっているかではなく
//頂点a,bそれぞれの属する連結成分の代表元が一致しているかを判定している
