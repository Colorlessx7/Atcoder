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
    ll l, r;
    cin >> l >> r;
    //rを狭める 1と2020はmod2019の上では同じなので
    //rとl+2019の2週分の小さい方の範囲までループを回せば大丈夫
    r = min(r, l+4038);
    //答えは2018以下なのでその最大を持ってminに備える
    int ans = 2018;
    //単純に2重ループさせる(i,jが被らないように)
    for(ll i = l; i <= r; i++){
        for(ll j = i+1;j <= r; j++){
            //求めたい計算
            int x = i*j%2019;
            //最小をとる
            ans = min(ans,x);
        }
    }
    cout << ans << endl;
    return 0;
}
//愚直にやるとTLE
//ループ範囲を狭めてから愚直に2重ループさせることで解く
//
