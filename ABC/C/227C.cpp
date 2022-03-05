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
    ll n;
    cin >> n;
    ll ans = 0;
    for(ll a = 1; a * a * a <= n; a++){
        //a <= bなのでbはaから回す
        for(ll b = a; a * b * b <= n; b++){
            //a,bが定まった時のcの最大はn/(ab)の切り捨てとなる
            ll maxc = n / (a * b);
            //b <= cよりcのとりうる範囲はmaxcとbの間の範囲
            //端を含まないといけないので+1
            ans += maxc - b + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
//全探索するとTLEするので探索範囲を狭める
//今回はa,b,cの大小関係が決まっている(A<=B<=C)ので制約を順に追うと
//ABC<=N BよりCの方が大きいので ABB<=ABC<=N
//よって２番目のBのループはa*b*b <= nまで回す
//AよりBの方が大きので AAA<=ABB<=ABC<=N よってAAA<=Nなので
//A <= Nの3乗根 となるから最初のAのループは1からa*a*a<=nまで回す
//
