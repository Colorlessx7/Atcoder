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
ll a, b, c, d;
ll f(ll x){
  ll cc = x / c;
  ll dd = x / d;
  ll cd = x / lcm(c,d);
  return x - cc - dd + cd;
}
int main(){
  cin >> a >> b >> c >> d;
  cout << f(b) - f(a-1) << endl;
  return 0;
}
//解説acver f(x)はx以下でcでもdでも割り切れる数の総数を求める
//a~bまでの範囲のf()を求める場合f(b)-f(a-1)をすればもとまる
//肝心のf(x)は全体の総数xから
//cで割り切れるものの個数x/cと、(割り切れるものの個数は(全体数/割る数)を切り捨てたもの)
//dで割り切れるものの個数x/dを引いて、ダブりであるcでもdでも割り切れる数を足すと求まる
//cでもdでも割り切れる数の個数はxからcとdの最小公倍数lcm(c,d)を割って切り捨てたもの
