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
    vector<vector<int>> dp(n+1, vector<int>(9));
    rep(i,n+1){
        dp[i][0] = 1;
    }
    string t = "chokudai";
    rep(i,n){
        rep(j,8){
            if(s[i] != t[j]){
                dp[i+1][j+1] = dp[i][j+1];
            }else {
                dp[i+1][j+1] = (dp[i][j+1] + dp[i][j]) % mod;
            }
        }
    }
    cout << dp[n][8] << endl;
    return 0;
}
//DP動的計画法問題 もらうDPver
