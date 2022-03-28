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
    string s;
    cin >> s;
    int n = s.size();
    //ダブリングDP 
    vector<vector<ll>> dp(18,vector<ll>(n));
    rep(i,n){
        if(s[i] == 'R'){
            //Rなら1回の動作でiマス目からi+1マス目に移動
            dp[0][i] = i + 1;
        }else {
            //Lなら1回の動作でiマス目からi-1マス目に移動
            dp[0][i] = i - 1;
        }
    }
    rep(i,17){
        rep(j,n){
            //ダブリング処理 一段上の値をjとしてdpを見ることで(2^i)*2の動作と等しくなる
            dp[i+1][j] = dp[i][dp[i][j]];
        }
    }
    //答えの配列
    vector<ll> ans(n);
    rep(i,n){
        //2^17操作した後の移動先がdpの値なので
        //ans[a]のaがマスaの最終的な人数に対応するように処理
        ans[dp[17][i]]++;
    }
    //出力部
    rep(i,n){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
//ダブリングで解く問題
//10^100はtleするので考察するとsの中で最も長く続いたRorLの回数より多い
//偶数回の操作をした後の状況を再現したものと等しくなる
//周期は2(RLの場所で交互に移動し続ける)操作がこの周期で完全に固まるのは
//sの長さ10^5を超えて+2位したタイミングなのでダブリングは2^0~2^17まで
//
