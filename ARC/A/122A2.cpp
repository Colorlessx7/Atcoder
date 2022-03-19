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
using mint = modint1000000007;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
    }
    vector<vector<mint>> dp(n+1,vector<mint>(2));
    dp[0][0] = 1;
    replr(i,1,n+1){
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
        dp[i][1] = dp[i-1][0];
    }
    mint ans = 0;
    rep(i,n){
        ans+=a[i]*((dp[i][0]*dp[n-i][0])-(dp[i][1]*dp[n-i-1][0]));
    }
    cout << ans.val() << endl;
    return 0;
}
//DPの正解
//Aiの前に来る符号が+である場合の数と-である場合の数を求めるDPは
//  i 0 1 2 3 4 5 6 
//j  
//0   1 1 2 3 5 8 13
//1   0 1 1 2 3 5 8   
//とフィボナッチ数列のような形になっている
//ansの導出部は計算結果を示すと(3,1,5)の時
//ans += a[0] * ((dp[0][0]*dp[3][0]) - (dp[0][1]*dp[2][0]))
//ans += 3 * ((1 * 3) - (0 * 2)) = 9
//ans += a[1] * ((dp[1][0]*dp[2][0]) - (dp[1][1]*dp[1][0]))
//ans += 1 * ((1 * 2) - (1 * 1)) = 1
//ans += a[2] * ((dp[2][0]*dp[1][0]) - (dp[2][1]*dp[0][0]))
//ans += 5 * ((2 * 1) - (1 * 1)) = 5 でans=15となる
//感じとしてはa[i]:そもそもの足す数
//左項dp[i][0]:グラフの一つ前の根から足す数の頂点へ向かう+の数
//右項dp[i][1]:グラフの一つ前の根から足す数の頂点へ向かう-の数
//左項dp[n-i][0]:足す数の+頂点からの部分木の葉の総数
//右項dp[n-i-1][0]:足す数の-頂点からの部分木の葉の総数

