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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i,n){
    cin >> a[i];
  }
  //二分探索
  //数列Bを1~Aiを全て1つずつ格納したものとすると
  //数列Bに含まれるm以上の値はK個以下かという条件で二分探索をする
  //wa:Aiの最小値以下の取り得ない値で初期化
  //ac:Aiの最大値以上の
  ll wa = -1, ac = 2e9;
  //最大値をX以下にするまでにかかる回数を計算する関数
  auto f = [&](ll x){
    //回数
    ll res = 0;
    //全てのアトラクションにたいして処理O(N)
    rep(i,n){
      //a[i]がxより多い場合xまでa[i]を下げられるので下げられる回数をresに加算
      res += max(0ll,a[i]-x);
    }
    //回数を返す
    return res;
  };
  //二分探索処理(waとacがこの順番で隣接するまで処理)
  //(終了時点でf(ac) < K <= f(wa)という関係になる)
  //(ac:配列a全てをacになるまで使ってもまだ回数が残っているギリギリの範囲)
  //(wa:ちょうどK回分か、回数をカウントしすぎてる状態)
  //計算量はO(logAi)=O(9.30...)くらい
  while(wa+1<ac){
    //二分探索の中心点
    int wj = (wa+ac)/2;
    //配列aの要素を全てwj以下にするためにかかる操作回数がk未満なら処理
    if(f(wj) < k){
      //acのカーソルをwjまで移動
      ac = wj;
    }else {
      //配列aの要素を全てwj以下にするためにかかる操作回数がk以上なら処理
      //waのカーソルをwjまで移動
      wa = wj;
    }
  }
  //満足度の最大(0初期化)
  ll ans = 0;
  //asum:等差1,初項l,末項r,項数n=r-l+1の等差数列の和を計算する関数
  auto asum = [&](ll l, ll r){
    //等差数列の和の公式を計算し、返す
    return (l+r)*(r-l+1)/2;
  };
  //全ての数列aの要素について回す
  //二分探索で求めたacで[ac+1,a[i]]の範囲()
  rep(i,n){
    //a[i]がac以下ならac+1以上の値からacまでアトラクションiを使って満足度をacまで
    //下げる工程が存在しないため、高橋の満足度が増えないためコンティニュー
    if(a[i] <= ac){
      continue;
    }
    //a[i]がac+1以上ならアトラクションiの満足度がa[i]の状態からac+1の状態まで
    //アトラクションに乗って満足度をacまで下げるため
    //高橋の満足度はΣi (i=ac+1...a[i])増えるのでasum関数で等差数列の和を求めてansに加算 
    ans += asum(ac+1,a[i]);
  }
  //f(ac)<kより、Σ(a[i]-ac+1+1) (a[i] > acの時のみ)がk未満であり、
  //上記の計算後、k-f(ac)回分まだどれかのアトラクションに乗ることができる状態になる
  //全てのac+1以上の満足度のアトラクションを全てacになるように
  //乗り尽くしたので貪欲に全アトラクションの中から満足度が最大になるように
  //選ぶならk-f(ac)個以上存在する満足度acのアトラクションからk-f(ac)個選んで乗るのが
  //満足度の最大になる
  //式は、ac:アトラクション1つ当たりの満足度,k-f(ac):残りのアトラクション搭乗回数
  ans += ac*(k-f(ac));
  cout << ans << endl;
  return 0;
}
