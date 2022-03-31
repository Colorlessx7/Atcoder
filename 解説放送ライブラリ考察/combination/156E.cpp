#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(ll i = 0; i < N; i++)
#define rep2(i,N) for(ll i = 1; i <= N; i++)
#define rep3(i,N) for(ll i = N - 1; i >= 0; i--)
#define rep4(i,N) for(ll i = N; i > 0; i--)
#define replr(i,l,r) for(ll i = l; i < r; i++)
#define reprl(i,l,r) for(ll i = l; i > r; i--)
#define all(x) x.begin(),x.end() 
#define allr(x) x.rbegin(),x.rend() 
typedef long long ll;
using P = pair<ll,ll>;
using mint = modint1000000007;
const int mod = 1000000007;
struct combination {
  vector<mint> fact, ifact;
  combination(int n):fact(n+1),ifact(n+1) {
    assert(n < mod);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
    ifact[n] = fact[n].inv();
    for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
  }
  mint operator()(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n]*ifact[k]*ifact[n-k];
  }
};
int main() {
  int n, k;
  cin >> n >> k;
  //問題の条件上最後の状態で0人の部屋がn個以上存在することがない為
  //入力のkが大きい値の時を考慮してkがn-1を超えていたらn-1にしておく
  k = min(k, n-1);
  //構造体combinationの初期化
  //この時n!までの階乗とその逆元が計算される
  //((n-i-1)+i)Ciが必要なものなのでn!とその逆元までが
  //事前に計算されている必要があるためsizeをnで初期化する
  combination c(n);
  mint ans;
  //最後の状態で0人になった部屋の個数でそれぞれ計算する
  for (int i = 0; i <= k; i++) {
    //c()で構造体のoperator()の処置を行う
    //
    ans += c(n,i) * c((n-i-1)+i, i);
  }
  cout << ans.val() << endl;
  return 0;
}
//前提知識:mod上での二項定理
//nCk(mod10^9+7)を求める時の問題点が2つあり
//計算量がO(k)あり遅い、mod上で除算は出来ず逆元を取らないといけない

//考察部分
//この問題のちょうどK回の移動はk回以下での移動と言い換えることができる
//その理由は例を挙げると
//1,1,1,1,1を2回で移動させたものが0,1,1,3,0とすると
//1,1,1,1,1から0,2,1,1,1、0,1,1,2,1そして0,1,1,3,0というように
//無駄な移動を挟めば必ずk回にできる
//ただこれは今回の問題の制約上許されているだけで
//K=1の場合行って戻る動作ができないため何も動かさない状態を作れない
//N=2の場合中継地点が存在しないため無駄な動作で回数を増やすことができない
//今度は0,1,1,3,0が操作により実現可能かを考える上で
//元々の1,1,1,1,1との差分をとると-1,0,0,2,-1となる
//操作1回で+の場所を-1して-の場所を+1するため必要な最小操作回数は
//+の部分の値を足したものになる
//ただ今回は-1(元々0)の部分を計算したほうが早い(最小移動回数=0の個数)
//これによりk回以内に操作できる数列は和がnでかつ0の個数がk個以下のものとなる
//これの個数を計算する方法は
//0が0個からk個までの個数をそれぞれ計算して足し合わせれば良い(0の個数を固定する)
//0がi個ある時の数列の個数を計算すると
//まずn個の数字の中でi個0の位置を固定するため0の場所がnCi通り(n=5でi=2だと0,?,?,0,?)
//で残りのn-i箇所に1以上の数を割り当てて和がnになる場合の数を求めたいが
//これは面倒なので0以上をn-i個並べた時の和がn-(n-i)=i個の場合の数として考える(xとしておく)
//すると0がi個の時の場合の数がnCi*xとなる
//xの求め方は
//n-i個の箱に区別できないボールをi個入れる方法が何通りあるかという形になり、
//これをさらに言い換えるとボールがi個あり、n-i-1個の仕切り線があり
//これを自由に並び替える方法は何通りかという形になる
//oo|o||oとするとこれは2,1,0,1に対応する
//つまり数式で表すと((n-i-1)+i)Ciとなる(oと|の組み合わせ((n-i-1)+i)からoの位置(i)を選ぶ)
//で最終的にnCi*((n-i-1)+i)Ciとなる(67行目に対応)
