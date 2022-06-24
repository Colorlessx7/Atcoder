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
//等差数列の和を計算する関数(Sum(i=1~n)(i))
//等差数列の和は1/2 * 項数 * (初項 + 末項) (公差=1の時)
ll f(ll n){
  return (1+n)*n/2;
}
//n=10でa=3の時のn以下のaの倍数の総和は、
//対象の数字が3,6,9でこれは1,2,3という等差数列のaの倍数となる
//n=12でa=4の時のn以下のaの倍数の総和は、
//対象の数字が4,8,12でこれは1,2,3という等差数列のaの倍数となる
//この等差数列はaの倍数でかつ公差が1で、項数がn/aになる
//よってn以下のaの倍数の総和は項数n/aの等差数列の和にaをかけたものになる
ll f2(ll n, ll a){
  return f(n/a)*a;
}
int main(){
  ll n, a, b;
  cin >> n >> a >> b;
  //ansに全体の和を格納
  ll ans = f(n);
  //ansからAの倍数の総和を引く
  ans -= f2(n,a);
  //ansからBの倍数の総和を引く
  ans -= f2(n,b);
  //ansからa,bの最小公倍数の倍数の総和を足す
  ans += f2(n,lcm(a,b));
  cout << ans << endl;
  return 0;
}
//包除原理問題
//1以上N以下の整数であって、Aの倍数でもBの倍数でもないものの総和は
//全体の和-Aの倍数の総和-Bの倍数の総和+lcm(A,B)の倍数の総和
//オーバーフローに気を付ける
