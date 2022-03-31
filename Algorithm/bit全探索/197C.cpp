#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(ll i = 0; i < N; i++)
#define rep2(i,N) for(ll i = 1; i <= N; i++)
#define rep3(i,N) for(ll i = N - 1; i >= 0; i--)
#define rep4(i,N) for(ll i = N; i > 0; i--)
#define replr(i,l,r) for(ll i = l; i < r; i++)
#define reprl(i,l,r) for(ll i = l; i > r; i--)
#define all(x) x.begin(),x.end() 
#define allr(x) x.rbegin(),x.rend() 
typedef long long ll;
using P = pair<ll,ll>;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
    }
    //minをとるため大きい値に
    int ans = INT_MAX;
    //s:0を境界なし、1を境界ありとしたn-1個のbitの集合
    //sを0~2^(n-1)-1まで全探索 
    rep(s,1<<(n-1)){
        //now:orの集合をxorした最終的な値、xorを処理
        int now = 0;
        //前から見た現在の値、orのみ処理
        int o = 0;
        //各境界パターンに対し問題文の処理の結果を導出
        rep(i,n){
            //次の要素をor
            o |= a[i];
            //次の要素の前に境界がある(sのi桁目が1)なら処理
            if(s>>i&1){
                //現在の値oをnowとxorさせる
                now ^= o;
                //0を0初期化
                o = 0;
            }
        }
        //境界が最大n-1、値そのものがn個であるため最後にxorをする必要がある
        now ^= o;
        //最終的な結果nowが最小を更新しているならansに格納
        ans = min(ans,now);
    }
    cout << ans << endl;
    return 0;
}
//境界線を入れるかどうかを2値としてbit全探索する問題
//
