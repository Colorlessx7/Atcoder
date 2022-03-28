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
    ll n, k;
    cin >> n >> k;
    ll r, s, p;
    cin >> r >> s >> p;
    //考えるのがだるいのでrをrに勝てるpに変えた(他も同様)
    swap(r,p);
    swap(s,p);
    string t;
    cin >> t;
    //DPのサイズ決め dpの一次元目を何番目
    ll d = n / k + 2;
    ll ans = 0;
    //n/kの余り0~k-1それぞれを独立したDPとして処理
    rep(i,k){
        //dp[a][b]とするとa:何番目までじゃんけんをしたか,b:最後に出した手
        vector<vector<ll>> dp(d,vector<ll>(3));
        //DPの初期化、aはまだジャンケンをしていないので0
        //bは0:グー,1:チョキ,2:パーとする 点をまだ獲得していないので全て0初期化
        dp[0][0] = 0; dp[0][1] = 0; dp[0][2] = 0;
        //DPを最後まで処理した時のaが違うため添字aをcntとして記録
        ll cnt = 0;
        //n/kの余りiからk個飛ばしでn-1までdpを処理
        for(ll j = i; j < n; j += k){
            //敵がグーを出す場合
            if(t[j] == 'r'){
                //基本は直前の出してない2つの手の最大を得点とする
                //パーを出す場合(dp[cnt+1][2])ならパーの得点(r)をそれに+
                dp[cnt+1][0] = max(dp[cnt][1],dp[cnt][2]);
                dp[cnt+1][1] = max(dp[cnt][0],dp[cnt][2]);
                dp[cnt+1][2] = max(dp[cnt][0],dp[cnt][1]) + r;
            }
            //チョキを出された場合
            if(t[j] == 's'){
                //グー出したら得点+
                dp[cnt+1][0] = max(dp[cnt][1],dp[cnt][2]) + s;
                dp[cnt+1][1] = max(dp[cnt][0],dp[cnt][2]);
                dp[cnt+1][2] = max(dp[cnt][0],dp[cnt][1]);
            }
            //パーを出された場合
            if(t[j] == 'p'){
                dp[cnt+1][0] = max(dp[cnt][1],dp[cnt][2]);
                //チョキ出したら得点+
                dp[cnt+1][1] = max(dp[cnt][0],dp[cnt][2]) + p;
                dp[cnt+1][2] = max(dp[cnt][0],dp[cnt][1]);
            }
            cnt++;
        }
        //DP処理後(cnt-1回のジャンケン終了時)の最後の手3つの得点から最大値を選んで答えに+
        ans += max(dp[cnt][0],max(dp[cnt][1],dp[cnt][2])); 
    }
    cout << ans << endl;
    return 0;
}
//アルゴ式DPのQ2-3の連続不可の仕事選びの難化版
//1個前が選べないという条件がK個前が選べないに変わったもの
//k=3とした時、1,4,7 2,5,8 3,6,9 という感じでn/kの余りでそれぞれ独立している為
//kの余りでそれぞれに別々でDPすることによってk個の連続不可の仕事選びDPの問題に分離できる
//
