#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep3(i,N) for(int i = N - 1; i >= 0; i--)
#define rep4(i,N) for(int i = N; i > 0; i--)
#define all(x) x.begin(),x.end() 
typedef long long ll;
using P = pair<int,int>;
//最小公倍数を求める関数
ll lcm(ll a,ll b){
    return a / gcd(a,b) * b;
}
ll f(ll x, ll c, ll d){
    ll res = x;
    res -= x/c;
    res -= x/d;
    res += x/lcm(c,d);
    return res;
}
int main(){
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll ans = f(b,c,d) - f(a-1,c,d);
    cout << ans << endl;
    return 0;
}
//解説acver f(x)はx以下でcでもdでも割り切れる数の総数を求める
//a~bまでの範囲のf()を求める場合f(b)-f(a-1)をすればもとまる
//肝心のf(x)は全体の総数xから
//cで割り切れるものの個数x/cと、(割り切れるものの個数は(全体数/割る数)を切り捨てたもの)
//dで割り切れるものの個数x/dを引いて、ダブりであるcでもdでも割り切れる数を足すと求まる
//cでもdでも割り切れる数の個数はxからcとdの最小公倍数lcm(c,d)を割って切り捨てたもの
