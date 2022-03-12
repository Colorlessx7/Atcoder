#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep3(i,N) for(int i = N - 1; i >= 0; i--)
#define rep4(i,N) for(int i = N; i > 0; i--)
#define replr(i,l,r) for(int i = l; i < r; i++)
#define all(x) x.begin(),x.end() 
typedef long long ll;
using P = pair<int,int>;
int main(){
    ll n, wm;
    cin >> n >> wm;
    vector<ll> w(n+1),v(n+1);
    rep2(i,n){
        cin >> w[i] >> v[i];
    }
    //DP用の二次元配列
    //h:何も選ばない場合(配列外参照回避)含めたn+1
    //w:何も選びようがない状態j=0を含めたwm+1
    vector<vector<ll>> dp(n+1,vector<ll>(wm+1,0));
    //i=0は初期状態で0で埋まっているためi=1スタート
    replr(i,1,n+1){
        //
        rep(j,wm+1){
            if(j >= w[i]){
                dp[i][j] = max(dp[i-1][j-w[i]]+v[i],dp[i-1][j]);
            }else {
                //重さがj以下になるように選ぶのにjより大きいものは選びようがないので
                //価値の最大値は重さが1小さい時と同じになる
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[n][wm] << endl;
    return 0;
}
//ナップザックDP
//dp[i][j]をi番目までの品物を重さがj以下になるように選んだ時の価値の最大値とする
//n=3,wm=8,w={3,4,5},v={30,50,60}とするとdpは以下のようになる
//0 0 0  0  0  0  0  0  0 
//0 0 0 30 30 30 30 30 30 
//0 0 0 30 50 50 50 80 80 
//0 0 0 30 50 60 60 80 90
//基本はdp[i-1][j]がdp[i][j]になる
//でdpの1段上のj-w[i]番目が配列外でなかったらその値にv[i]を足したものと
//dp[i-1][j]の大きい方がdp[i][j]の更新後の値になる
