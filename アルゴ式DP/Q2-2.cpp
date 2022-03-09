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
    vector<vector<int>> dp(n,vector<int>(n));
    rep(i,n){
        cin >> dp[0][i];
    }
    replr(i,1,n){
        rep(j,n){
            if(j != 0){
                dp[i][j] += dp[i-1][j-1]; 
            }
            dp[i][j] += dp[i-1][j];
            if(j != n-1){
                dp[i][j] += dp[i-1][j+1]; 
            }
            dp[i][j] %= 100;
        }
    }
    cout << dp[n-1][n-1] << endl;
    return 0;
}
