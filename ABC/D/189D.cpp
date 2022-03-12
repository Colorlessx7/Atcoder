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
    ll n;
    cin >> n;
    vector<vector<ll>> dp(n+1,vector<ll>(2));
    rep(j,2){
        dp[0][j] = 1;
    }
    replr(i,1,n+1){
        string s;
        cin >> s;
        if(s == "AND"){
            dp[i][0] += dp[i-1][0] * 2;
            dp[i][0] += dp[i-1][1]; 
            dp[i][1] += dp[i-1][1];
        }else {
            dp[i][1] += dp[i-1][1] * 2;
            dp[i][1] += dp[i-1][0]; 
            dp[i][0] += dp[i-1][0];
        }
    }
    cout << dp[n][1] << endl;
    return 0;
}
