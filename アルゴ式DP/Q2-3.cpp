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
    vector<vector<int>> a(n+1,vector<int>(3));
    rep(i,n){
        rep(j,3){
            cin >> a[i][j];
        }
    }
    vector<vector<int>> dp(n+1,vector<int>(3));
    replr(i,1,n+1){
        dp[i][0] += max(dp[i-1][1],dp[i-1][2]) + a[i-1][0];
        dp[i][1] += max(dp[i-1][2],dp[i-1][0]) + a[i-1][1];
        dp[i][2] += max(dp[i-1][0],dp[i-1][1]) + a[i-1][2];
    }
    int ans = max(dp[n][0],max(dp[n][1],dp[n][2]));
    cout << ans << endl;
    return 0;
}
