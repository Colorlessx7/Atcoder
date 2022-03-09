#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep3(i,N) for(int i = N - 1; i >= 0; i--)
#define rep4(i,N) for(int i = N; i > 0; i--)
#define replr(i,l,r) for(int i = l; i < r; i++)
#define all(x) x.begin(),x.end() 
#define allr(x) x.rbegin(),x.rend() 
typedef long long ll;
using P = pair<int,int>;
int main(){
    int n;
    cin >> n;
    vector<vector<int>> dp(n,vector<int>(n,0));
    vector<vector<int>> a(n,vector<int>(n));
    rep(i,n){
        rep(j,n){
            cin >> a[i][j];
        }
    }
    rep(i,n){
        if(i == 0){
            dp[i][0] = a[i][0];
            continue;
        }
        dp[i][0] += dp[i-1][0] + a[i][0];
    }
    rep(j,n){
        if(j == 0){
            dp[0][j] = a[0][j];
            continue;
        }
        dp[0][j] += dp[0][j-1] + a[0][j];
    }
    replr(i,1,n){
        replr(j,1,n){
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]) + a[i][j];
        }
    }
    cout << dp[n-1][n-1] << endl;
    return 0;
}
