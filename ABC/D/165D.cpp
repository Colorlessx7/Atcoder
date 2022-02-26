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
    ll a, b, n;
    cin >> a >> b >> n;
    ll ans = (a*(b-1))/b - a*((b-1)/b);
    if(b > n){
        ans = (a*n)/b - a*(n/b);
    }
    cout << ans << endl;
    return 0;
}
//数学的考察で解いた問題
//1~nをxだとすると(a*x)/b-a*(x/b)が計算式だが
//これはnが無限まであるとすれば
//xがb-1の時が最大でxがbの時計算結果がガクッと落ちる
//例外がnがbより小さい時でこの場合はx=nとして計算すればよい
