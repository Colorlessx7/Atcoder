#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    ll r,x,y;
    cin >> r >> x >> y;
    //原点から目的地までのユークリッド距離の2乗
    ll d2 = x*x + y*y;
    ll ans = 1;
    //無限ループ
    while(1){
        //目的地まで原点から最短経路でans歩進み、届くのか判定
        if(r*r*ans*ans >= d2){
            break;
        }
        //届かないなら歩数+1
        ++ans;
    }
    //1歩で届くコーナーケース処理
    if(ans == 1){
        //1歩で越すなら2歩が答え
        if(r*r != d2){
            ans = 2;
        }
    }
    cout << ans << endl;
    return 0;
}
//詳しい解説
//https://www.youtube.com/watch?v=wHgVlM0UVO4
//https://atcoder.jp/contests/abc198/editorial/1043
//原点から (X,Y) までのユークリッド距離を d とすると
//d = n * Rで割り切れる歩数 n歩
//d=R かつ d≤2R のとき 2
//それ以外のとき d/Rの切り上げとなる
