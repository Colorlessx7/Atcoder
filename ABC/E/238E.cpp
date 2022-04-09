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
int main(){
  ll n, q;
  cin >> n >> q;
  //dsu:union-find n+1個の頂点(累積和配列の個数分)で初期化
  dsu d(n+1);
  rep(i,q){
    ll l, r;
    cin >> l >> r;
    //累積和からSum(l~r)を求める方法がS(r)-S(l-1)なので
    //lだけ-1しておく
    --l;
    //辺の接続
    d.merge(l,r);
  }
  //判定部 頂点0とnが連結しているならYes,そうでないならNo
  if(d.same(0,n)){
    cout << "Yes" << endl;
  }else {
    cout << "No" << endl;
  }
  return 0;
}
//累積和の考え方からグラフ問題に変換して、dsuで解く問題(dfsでも可)
//注意点として数列の値を全て特定できるかの問題ではない
//その場合は全体が連結かどうかをdsuで判定すれば良い
//問題文はSum(al~ar)の値をq回与えられてSum(a1~an)を答えられれば良い
//累積和を考える例として3,1,4,1,5というaが答えだとすると
//累積和は0,3,4,8,9,14となる(この最後の14が今回求めたいSum(a1~an)部分)
//クエリが(1,3),(2,5),(2,3)とすると、
//値の和はそれぞれ累積和の8-0=8,14-3=11,8-3=5となる
//クエリ1,2を+,クエリ3を-とした場合に8+11-5=14となり、答えが求められるのでYesとなる

//この累積和の関係を式に直すとl~rの和が累積和をsとした時s(r)-s(l-1)となり、
//これをXとするとs(r)=s(l-1)+X,s(l-1)=s(r)-Xとなり、
//今回の問題ではクエリとしてXが都度提示されるため、
//s(r),s(l-1)のどちらかがわかっているならどちらも特定できる
//つまり、累積和で考えた時のs[0](=0なので特定済み)と
//s[n]がわかるならばSum(a1~an)が特定できるという問題を
//都度渡されるXをl-1とrを繋ぐ辺として最終的に0とnが連結かどうか見る問題に変換できる
//区間の和を2変数にしてグラフ問題に変えるのはよくあるパターンらしい
