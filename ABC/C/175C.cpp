#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    ll x, k, d;
    cin >> x >> k >> d;
    //反復横跳びに移行するまでの移動数
    ll l = abs(x) / d;
    ll ans = 0;
    //0以上の反復横跳び点
    ll ans1 = 0;
    //0未満の反復横跳び点
    ll ans2 = 0;
    //反復横跳びに移行する程移動できるのか判定
    if(k < l){
        //始点が+なら最終も+なのでxから移動分を引いたものが答え
        if(x >= 0){
            ans = x - k * d;
            cout << ans << endl;
            return 0;
        }else {
            //始点が-なら最終も-なので-xから移動分を足したものが答え
            ans = abs(x + k * d);
            cout << ans << endl;
            return 0;
        }
    }else {
        //kから反復横跳び開始までの移動分を引いてkを反復横跳び回数とする
        k -= l;
        //
        if(x >= 0){
            //ans1:反復横跳び開始点で+
            ans1 = x - l * d;
            //ans2:反復横跳び先の点で-なので絶対値に
            ans2 = abs(ans1 - 1 * d);
        }else {
            //ans1:反復横跳び開始点で-
            ans1 = x + l * d;
            //ans2:反復横跳び先の点で+になる
            ans2 = ans1 + 1 * d;
            //ans1:-だったので絶対値に
            ans1 = abs(ans1);
        }
        //反復横跳び回数が偶数なら元の位置ans1に
        if(k % 2 == 0){
            ans = ans1;
        }else {
            ////反復横跳び回数が奇数なら反復横跳び先ans2に
            ans = ans2;
        }
    }
    cout << ans << endl;
    return 0;
}
//最終的に0を境に反復横跳びする
