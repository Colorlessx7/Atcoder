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
            dp[i][n-1] = a[i][n-1];
            continue;
        }
        dp[i][n-1] += dp[i-1][n-1] + a[i][n-1];
    }
    rep3(j,n){
        if(j == n-1){
            dp[0][j] = a[0][j];
            continue;
        }
        dp[0][j] += dp[0][j+1] + a[0][j];
    }
    replr(i,1,n){
        for(int j = n-2; j >= 0; j--){
            dp[i][j] = min(dp[i-1][j],dp[i][j+1]) + a[i][j];
        }
    }
    cout << dp[n-1][0] << endl;
    return 0;
}
