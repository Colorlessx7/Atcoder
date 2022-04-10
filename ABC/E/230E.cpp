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
  ll n;
  cin >> n;
  ll ans = 0;
  //iは問題文と同様にSum(i=1~n)においてのi
  //iの遷移は単純なインクリメント等ではないためfor文の3つ目は空白
  //i=niで遷移させ続けると最終的にi=n+1になって終了する
  for(ll i = 1; i <= n;){
    //今の値(n/iの切り捨て)をxとする
    ll x = n / i;
    //niはn/iの切り捨てがギリギリxでなくなるiの値を求める
    //n/xでn/iの切り捨て=xとなるiの最大値が計算される
    //それに+1することでn/iの切り捨てがギリギリxでなくなるiの値になる
    ll ni = n / x + 1;
    //問題文の処理通り切り捨ての値xにその個数(ni-i)個かけたものを答えにたす
    ans += x * (ni - i);
    //切り捨ての値xが変わる最初の値niにiを遷移
    i = ni;
  }
  cout << ans << endl;
  return 0;
}
//n/iの切り捨ての値がとりうる範囲が少ないことを利用する問題

//sqrt(n)で分割して考える
//sqrt(n)<=10^6なので,i<=sqrt(n)とi>sqrt(n)に分けた時、
//i>sqrt(n)はn/iの切り捨てが<=sqrt(n)以下なので
//iは最大でもsqrt(n)種類しかない
//方針としては同じ値になるiをまとめて計算する
//問題文からSum(j=1~sqrt(n))(n/iの切り捨て=jになるiの個数)
//が分かればよくて、n/iの切り捨てがjになるiの個数は
//n/i <= n/iの切り捨て < n/i +1 となり、
//n/i <= j < n/i +1となる
//移項するとn/i <= j < (n+i)/i
//n <= i*j < n+i
//よってSum(i=1~n)(n/iの切り捨て)は
//n <= ij から n/j <= i <= n/(j-1)と
//ij <= n+i から i(j-1) <= n よって i <= n/(j-1)
//の2式になり、合わせるとn/j <= i <= n/(j-1) で
//これが満たされるiの個数はn/(j-1) - n/jで求められる
//(なおどっちに丸めるかは考えないといけない)
//ここから実装しようとすると普通にやるi<=sqrt(n)と
//上記の方法でやるi>sqrt(n)で境界線の処理がめんどくさくなるため
//iの種類がこちらも最大sqrt(n)種類しかないので
//上記の方法をi<=sqrt(n)の範囲でもやる
