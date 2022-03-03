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
int main(){
    ll n,a,b,c,d,e;
    cin >> n >> a >> b >> c >> d >> e;
    ll x = min(a,b);
    x = min(x,c);
    x = min(x,d);
    x = min(x,e);
    ll ans = (n + x - 1) / x + 4;
    cout << ans << endl;
    return 0;
}
//数学的考察問題
//最も人数を運べない移動手段の場所で最終的に
//集団が全体数n/その移動手段の移動人数xを切り上げた集団数に分かれる
//その複数集団のうち最初の集団が5の移動手段を乗り継ぎ5で目的地に到着する
//その後残りの集団がそれぞれ1ずつ遅れて到着するため
//移動数5 + n / xの切り上げに1引いたもの = (n + x - 1) / x + 4となる
