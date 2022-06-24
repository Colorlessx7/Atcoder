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
  ll n, a, b;
  cin >> n >> a >> b;
  ll all = 0;
  if(n % 2 == 0){
    all = n/2;
    all *= n+1;
  }else {
    all = (n+1)/2;
    all *= n;
  }
  ll ab = lcm(a,b);
  ll af = n / a;
  ll aall = 0;
  if(af % 2 == 0){
    aall = af / 2;
    aall *= (2*a+(af-1)*a);
  }else {
    aall = (2*a+(af-1)*a)/2;
    aall *= af;
  }
  ll bf = n / b;
  ll ball = 0;
  if(bf % 2 == 0){
    ball = bf / 2;
    ball *= (2*b+(bf-1)*b);
  }else {
    ball = (2*b+(bf-1)*b)/2;
    ball *= bf;
  }
  ll abf = n / ab;
  ll aball = 0;
  if(abf % 2 == 0){
    aball = abf / 2;
    aball *= (2*ab+(abf-1)*ab);
  }else {
    aball = (2*ab+(abf-1)*ab)/2;
    aball *= abf;
  }
  cout << all - aall -ball + aball << endl;
  return 0;
}
//包除原理問題
//1以上N以下の整数であって、Aの倍数でもBの倍数でもないものの総和は
//全体の和-Aの倍数の総和-Bの倍数の総和+lcm(A,B)の倍数の総和
//オーバーフローに気を付ける
//オーバーフローに気をつけながら色々変数をつけて頑張って汚くなったACver
//_f:項数 _all:_の倍数の総和で等差数列の和の公式の公差が1でないものに当てはめて計算している
