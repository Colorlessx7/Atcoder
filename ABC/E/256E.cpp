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
  vector<int> state(n);
  // 0: not visited (まだ訪れてない状態)
  // 1: visited (calculating) (訪れてはいるが、サイクルかどうかの判定をしていない状態)
  // 2: visited (calculated) (訪れて、かつサイクルかどうかの判定も終えている状態)
  ll ans = 0;
  //全頂点について処理
  rep(i,n){
    //完全に訪れていない頂点だけ処理
    if(state[i] == 0){
      //vs:頂点iからdfsをした時に発見されたサイクルを構成する頂点の集合
      vector<int> vs;
      //dfs(v:今見ている頂点,戻り値:)
      auto dfs = [&](auto f, int v) -> int {
        //stateが2の場合、頂点vがサイクルかどうかの判定をすでに終えているので-1を返す
        if(state[v] == 2){
          return -1;
        }
        //stateが1の場合に処理(ここでサイクルが存在することが確定する)
        if(state[v] == 1){
          //この時のvがサイクルの開始点でありサイクルの終点となる
          //再帰元にこのvを返す
          return v;
        }
        //vに一回も訪れていなかったのでstateを1にする
        state[v] = 1;
        //r:dfs探索の終点(-1なら探索が終了したところに繋がった場合
        //r=v(0~n-1)の場合見つけたサイクルの開始点かつ終点の頂点番号)
        int r = f(f,x[v]);
        //rが決まり、dfsでのサイクル判定探索が終了したのでstateを2に変更
        state[v] = 2;
        //未探索部分でサイクルが見つからず、すでに調査を終了していた頂点につながった場合
        //state[v]=2のifを通り-1が帰ってくる。この場合に処理
        if(r == -1){
          //辿ってきた一つ前の頂点のrに-1を返す
          return -1;
        }
        //以下はdfsでサイクルを発見した場合の帰りの処理
        //サイクルの構成要素に今見ている頂点vを格納
        vs.push_back(v);
        //r=vなら発見したサイクルを構成する頂点を全部vsに格納し終えたので-1を返して再帰を終了させる
        if(r == v){
          return -1;
        }
        //サイクルを構成する頂点をまだvsに全部格納できていない場合は
        //サイクルの開始点かつ終了点のrを再帰元に返す
        return r;
      };
      //頂点iからのdfsを実行
      dfs(dfs,i);
      //頂点iからのdfsで新しいサイクルを発見した場合に処理
      //(サイクルを構成する頂点がvsに格納されている場合)
      if(vs.size()){
        //mn:サイクルの中の不満度の最小値を求める(minを取るため大きい値で初期化)
        int mn = 1001001001;
        //サイクルを構成する頂点郡の中の頂点vの不満度はc[v]なのでその最小を求める
        for(int v : vs){
          mn = min(mn,c[v]);
        }
        //答えにサイクルの不満度の最小を足す
        ans += mn;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
//問題の条件をグラフに落とし込んで解く問題
//問題の条件からfunctional graphに落とし込むことができる
//この問題で与えられている人間関係をグラフの言葉を使って言い換えると
//N頂点N辺の自己辺を持たない有向グラフGがある。各頂点の出次数は1で、頂点iから出る辺はXiに向かう
//このグラフの特性はGの連結成分がK個あってそれをC1,C2,...CNとするとき、各連結成分には閉路が1つだけ存在する
//実際に答えを求めるには、Functional Graph の閉路の部分をすべて列挙できればよい
//この解法では列挙をdfsで行なっているが他の方法として
//unionfind,scc,Σ C - 最大全域木の方法でも解くことができる
