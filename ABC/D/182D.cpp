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
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
    }
    ll p = 0, q = a[0], x = 0, ans = 0;
    rep(i,n){
        //動作iの合計の座標の変化
        p += a[i];
        //動作iを座標0で始めた場合の、開始から終了までの座標の最大値
        q = max(q, p);
        //最終的な座標の最大値
        //今の座標xから動作iで行けるx+qが過去の座標の最大値を超えてるなら更新
        ans = max(ans,x + q);
        //現在の座標を示すxに動作iで移動した距離pを足して現在地の更新
        x = x + p;
    }
    cout << ans << endl;
    return 0;
}
//一連の動作をまとめて考える問題
//正の向きにA1​進む。正の向きにA2進む。正の向きにA3進む。… 正の向きにAi進む。
//という一連の動作をiとする
