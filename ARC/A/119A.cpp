#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep3(i,N) for(int i = N - 1; i >= 0; i--)
#define rep4(i,N) for(int i = N; i > 0; i--)
#define replr(i,l,r) for(int i = l; i < r; i++)
#define reprl(i,l,r) for(int i = l; i > r; i--)
#define all(x) x.begin(),x.end() 
#define allr(x) x.rbegin(),x.rend() 
typedef long long ll;
using P = pair<int,int>;
int main(){
    ll n;
    cin >> n;
    ll ans = LLONG_MAX;
    ll a, b, c;
    //i:b,プログラム中のbは2^bを指す
    rep(i,61){
        //オーバーフロー回避のためllでキャスト
        b = (ll)1 << i;
        //オーバーフロー回避のためbの状況を見て終了
        if(b < 0 || b > 1e18){
            break;
        }
        a = n / b;
        c = n - a * b;
        //cout << a << " " << b << " " << c << endl;
        ans = min(ans,a+i+c);
    }
    cout << ans << endl;
    return 0;
}
//条件を絞った全探索
//指数の2^b部分が2^60くらいでnの制約の範囲を越えるため
//bで全探索する
//この時a,cはaが大きいほどcの数を減らせるため貪欲に
//aをn/bの切り捨てでとり、cは決まったa*2^bから決まる
//この時のa,b,cの合計をminでとって最小を求める
