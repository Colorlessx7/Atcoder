#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep3(i,N) for(int i = n - 1; i >= 0; i--)
#define rep4(i,N) for(int i = n; i > 0; i--)
#define all(x) x.begin(),x.end() 
typedef long long ll;
using P = pair<int,int>;
using mint = modint1000000007;
const int mod = 1000000007;
int main(){
    string s;
    cin >> s;
    int n = s.size();
    vector dp(n+1, vector<int>(9));
    dp[0][0] = 1;
    string t = "chokudai";
    rep(i,n){
        rep(j,9){
            (dp[i+1][j] += dp[i][j]) %= mod;
            if(j < 9 && s[i] == t[j]){
                (dp[i+1][j+1] += dp[i][j]) %= mod;
            }
        }
    }
    cout << dp[n][8] << endl;
    return 0;
}
//現在見ているdp[i][j]から+=の形で影響されるdp[i+1][j]とdp[i+1][j+1]に値を配るDPの書き方
