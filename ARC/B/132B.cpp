#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep3(i,N) for(int i = N - 1; i >= 0; i--)
#define rep4(i,N) for(int i = N; i > 0; i--)
#define replr(i,l,r) for(int i = l; i < r; i++)
#define reprl(i,l,r) for(int i = l; i > r; i--)
#define all(x) x.begin(),x.end() 
#define allr(x) x.rbegin(),x.rend() 
typedef long long ll;
using P = pair<int,int>;
int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  for (auto &v : p)
    cin >> v;
  //distの初期値 if文の条件式と制約から10^5は絶対超えている必要がある
  const int INF = 1e9;
  //おそらく操作2だけで昇順に並び替えることができるか
  //0なら操作2だけで昇順にsortでき、1ならできない(降順)
  const bool rev = (n == 2 || p[0] - 1 == p[1] || p[1] - 1 == p[2]);
  //ind:順列pにおいて1が何番目に存在するかのイテレータを返す
  //distで使うときは1のある場所をindで示す
  const int ind = find(p.begin(), p.end(), 1) - p.begin();
  //操作回数の最小値を格納する配列
  //dist[rev][ind]とするとrevは0の時何らかの操作があったかもしれない状態から
  //
  vector dist(2, vector(n, INF));
  //状態1つから2つの操作で2つの状態に遷移できるためqueueを使う
  queue<pair<int, int>> que;
  //初期化
  dist[rev][ind] = 0;
  que.emplace(rev, ind);
  //ラムダ式(main内のstlをそのまま使えるのが強み)[&]でmain内の変数を参照できる
  const auto update = [&](const int rev, const int ind, const int val) {
    //初期値は基本的にINFなのでここを通るのは他のrev,indの影響を受けて値が変わってから
    if (dist[rev][ind] <= val)
      return;
    dist[rev][ind] = val;
    
    que.emplace(rev, ind);
  };
  while (que.size()) {
    //本来はpair<int,int>だがautoで右辺値参照させることで
    //このスコープ内で??.first,??.secondみたいなわかりづらい書き方をしなくて済む
    const auto [rev, ind] = que.front();
    que.pop();
    //操作2を行った場合の1の位置をindとした場合の
    update(rev, (ind + n - 1) % n, dist[rev][ind] + 1);
    //操作1を行った場合の1の場所をindとした場合の
    update(!rev, n - 1 - ind, dist[rev][ind] + 1);
  }
  cout << dist[0][0] << endl;
  return 0;
}
//n = 5 なら入力は
//1,2,3,4,5 2,3,4,5,1 3,4,5,1,2 4,5,1,2,3 5,1,2,3,4と
//5,4,3,2,1 4,3,2,1,5 3,2,1,5,4 2,1,5,4,3 1,5,4,3,2の2n通りしか問題として
//p行列に与えられない問題である
//n = 2の時のみ重複で2通りとなる
//基本途中の状態としてありうるものはO(n)通りしかない
//以上のことを念頭において解法を考えると全探索を通したくなるが
//入力の長さnをそのまま使うと各操作にO(n)かかりtleするので
//各状態を1の位置,操作2だけで昇順に並び替えられるかどうかの組として持つ

//3,2,1という例があったとして
//操作2だけで昇順にできないので初期化はdist[1][2]=0とする 以下に状態を示す
//(縦:rev,横ind)
//  0 1 2 - 0 1 2 - 0 1 2 - 0 1 2 - 0 1 2 - - - 0 1 2 -
//  3 2 1 - 3 2 1 - 3 2 1 - 3 2 1 - 3 2 1 - - - 3 2 1 -
//0 . . . - . . . - 1 . . - 1 . . - 1 2 . - - - 1 2 1 -
//1 . . 0 - . 1 0 - . 1 0 - 2 1 0 - 2 1 0 - - - 2 1 0 -
//初期状態321,321から操作2で213,321から操作1で123
//213から操作2で132,213から操作1で312
//123から操作2で231(降順のパターンで1が2番目に操作2で来るのは最初に続いて2回目なので処理されない)
//123から操作1で321
//最終的に昇順にする必要があるためdist[0][0]が答え

//全探索して昇順になる場合の最速操作数と降順になる場合の最速操作数を更新させ続けて
//それが終わり次第出力させるだけ
