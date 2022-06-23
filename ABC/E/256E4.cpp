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
  //辺の情報(0:コスト,1:辺の始点,2:辺の終点(ただこの解法では無向グラフとして扱う))
  vector<TP> v(n);
  rep(i,n){
    v[i] = {c[i],i,x[i]};
  }
  //各辺の情報についてコストを降順にsortする
  //(最大全域木を求めるクラスカル法でコストが大きい順に処理するため)
  sort(allr(v));
  //n頂点0辺のunionfindを宣言(クラスカル法を用いて最大全域木(森)を求める)
  dsu uf(n);
  //不満度の最小
  ll ans = 0;
  //クラスカル法の処理(コストの大きい順に辺の情報を全て処理)
  for(auto [cost,from,to] : v){
    //連結している場合は最大全域木にその辺が含まれないので削除したとみなしコストを答えに加算
    if(uf.same(from,to)){
      ans += cost;
    }
    //連結していない場合は連結させる(連結している場合も処理するが特に何も起こらない)
    uf.merge(from,to);
  }
  cout << ans << endl;
  return 0;
}
//問題の条件をグラフに落とし込んで解く問題
//問題の条件から無向グラフに落とし込むことができる
//unionfindでクラスカル法を用いて最大全域木(森)を求めてから
//全部のコストの和から全域森のコストを引いて答えを求める解法
//(今回の解法では全域森に含まれないもの(!全部のコストの和から全域森のコストを引いたもの)のみを答えに足している)
//無向グラフにおける全域木はグラフが連結であるという条件を保ったまま辺を消去して得られる木のこと
//最小全域木は、全域木を構成する辺のコストの総和が最小となるもののことを指す
//最小全域木問題は、与えられたグラフの最小全域木またはそのコストを求める問題である
//ただし今回は最大全域木を求める
//最大全域木は、全域木を構成する辺のコストの総和が最大となるもののことを指す
//最小全域木はグラフの辺を、コストが小さい順に、閉路を作らないように採用していく
//という貪欲法で求められる(今回は最大全域木を求めるのでコストが大きい順にやる)
//無向グラフとして何故扱えるかはおそらくサイクル内の最も重い辺を消す問題で向きが関係なくなるから
