#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(ll i = 0; i < N; i++)
#define rep2(i,N) for(ll i = 1; i <= N; i++)
#define rep3(i,N) for(ll i = N - 1; i >= 0; i--)
#define rep4(i,N) for(ll i = N; i > 0; i--)
#define replr(i,l,r) for(ll i = l; i < r; i++)
#define reprl(i,l,r) for(ll i = l; i >= r; i--)
#define all(x) x.begin(),x.end() 
#define allr(x) x.rbegin(),x.rend() 
using ll = long long;
using P = pair<ll,ll>;
void chmin(ll &x, ll y){ x = min(x,y); }
void chmax(ll &x, ll y){ x = max(x,y); }
//クエリの情報のペア(k,i)を一括で管理するための構造体
//k:大きい方から何番目が必要か,i:何番目のクエリなのか
struct Q{
  ll k, i;
  //コンストラクタ 入力を受け取ってk,iをペアとして持つだけ
  //stlのpairとは少し違うが似たようなことをやっている
  Q(ll k, ll i):k(k),i(i) {}
};
int main(){
  //n:頂点数,q:クエリ数
  ll n, q;
  cin >> n >> q;
  //x:各頂点に書かれた数字
  vector<ll> x(n);
  rep(i,n){
    cin >> x[i];
  }
  //根付き木をグラフとして管理
  vector<vector<ll>> to(n);
  //根付き木の辺を接続する処理(辺はn-1個存在する)
  rep(i,n-1){
    ll a, b;
    cin >> a >> b;
    //0indexed処理のため-1
    a--; b--;
    //無効グラフとして双方向に辺を接続
    to[a].push_back(b);
    to[b].push_back(a);
  }
  //各頂点毎にクエリが与えられているか格納する配列
  //例として、頂点jにクエリが3つきていたらqs[j]に
  //(k,i)のペア3つが格納される
  //k:大きい方から何番目が必要か,i:何番目のクエリなのか
  vector<vector<Q>> qs(n);
  rep(i,q){
    //v:頂点番号,k:大きい方からk番目が欲しい
    ll v, k;
    cin >> v >> k;
    //頂点は0indexed管理なので-1
    //大きい方から20個をまとめた配列を見る過程でその配列の添字が0indexedになっているので-1
    v--; k--;
    //頂点vに対するクエリの情報のペア(k,i)をqs[v]に格納
    qs[v].emplace_back(k,i);
  }
  //クエリの結果の値を格納する配列(サイズはクエリの数q個分)
  vector<ll> ans(q);
  //制約より上から20番目までが分かればいいので20という数字を持っておく
  const ll K = 20;
  //dfsの過程で部分木の根となる頂点の、部分木に含まれる頂点に書かれた整数のうち
  //大きい方から20個を格納した配列を作る処理
  //葉の頂点についての上から20個を格納した配列を
  //根の頂点についての上から20個について格納した配列と合体させ、上から20個を抜き出す
  //aが根の上から20個について、bが葉の上から20個についての配列
  auto merge = [&](vector<ll> &a, const vector<ll> &b){
    //配列aの末尾に配列bの全要素を追加する
    a.insert(a.end(),all(b));
    //降順になるようにsort
    sort(allr(a));
    //根の上から20個についての配列のサイズが20を超えたらサイズを20になるように調整
    a.resize(K);
    //根の上から20個についての配列aを返す
    return a;
  };
  //引数はf:ラムダ式で再帰を書くときにラムダ式を使っている関数の名前を関数内で使えないため
  //dfsという関数をfという名前で使っている
  //v:dfsで今見ている頂点の番号,p:dfsで今見ている頂点の根の頂点番号
  //(最初の頂点0は木全体の根の場所なのでその頂点の根が存在しないため取り得ない-1で初期化)
  //矢印以降のvectorは戻り値の型
  //(今回はllを型とする一次元配列)を示す(書かなかったら型推論される)
  auto dfs = [&](auto f, ll v, ll p=-1) -> vector<ll>{
    //res:dfsで今見ている頂点の部分木の数字の上から20個を格納する配列
    vector<ll> res(K);
    //resの最初に格納されている値を今見ている頂点に書かれた数字とする
    res[0] = x[v];
    //現在の頂点vから一回で辿り着ける葉全てについて探索する
    for(ll u : to[v]){
      //木でdfsをする過程で根(頂点v)から親(頂点p)に戻らないようにする処理
      if(u == p){
        continue;
      }
      //dfsの再帰処理部分
      //ラムダ式なのでdfsとは書けず、関数fを呼び出して再帰する
      //今から再帰で潜ろうとする頂点uが再帰先の今見ている頂点vとなり、
      //今(再帰元)見ている頂点vが再帰先の今見ている頂点の親pとなる
      //再帰関数の戻り値的にdの方はvector<ll>となる
      auto d = f(f,u,v);
      //再帰先の処理が全て終わって再帰元に戻ってきた結果、再帰先の葉の
      //部分木の数字の上からmax20個を格納した配列が完成したので
      //今見ている頂点vの部分木の数字の上からmax20個を格納した配列と合体させる
      merge(res,d);
    }
    //頂点vの部分木の数字の上からmax20個を格納した配列が完成したので
    //頂点vに対するクエリがあるならばそれの処理をする
    for(auto [k,i] : qs[v]){
      //i番目のクエリの答えがdfsで今見ている頂点vの部分木の数字の上から
      //max20個を格納した配列のk番目に大きい値になるのでそれを格納
      ans[i] = res[k];
    }
    //再帰元に配列resを返す
    return res;
  };
  //dfsを根の頂点番号である0(1の0indexed)から開始
  dfs(dfs,0);
  //dfs処理が全て終了した後にクエリの全結果がansに格納されたので全て出力
  rep(i,q){
    printf("%d\n",ans[i]);
  }
  return 0;
}
//K<=20という制約から、N頂点の根付き木の各頂点毎にその頂点の部分木に含まれる
//頂点に書かれた整数のうち、大きい方からmax20個を持った配列を作ってクエリに答える
//解説放送のプログラムではdfsで葉から、大きい方からmax20個を持った配列を作りながら
//一つ上の根にそれを合体させながら全ての頂点の処理をしていき、
//その中でクエリを確認し、答えの配列に格納していくという処理をしている
