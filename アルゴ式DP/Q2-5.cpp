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
    rep(i,n){
        string s;
        cin >> s;
        rep(j,n){
            if(s[j] == '#'){
                dp[i][j] = -1;
            }
        }
    }
    bool f = 1;
    rep(i,n){
        if(dp[i][0] == -1){
            f = 0;
            break;
        }
        if(f){
            dp[i][0] = 1;
        }
    }
    f = 1;
    rep(j,n){
        if(dp[0][j] == -1){
            f = 0;
            break;
        }
        if(f){
            dp[0][j] = 1;
        }
    }
    replr(i,1,n){
        replr(j,1,n){
            if(dp[i][j] == -1){
                continue;
            }
            dp[i][j] += dp[i-1][j] + dp[i][j-1];
            if(dp[i-1][j] == -1){
                dp[i][j]++;
            }
            if(dp[i][j-1] == -1){
                dp[i][j]++;
            }
        }
    }
    cout << dp[n-1][n-1] << endl;
    return 0;
}
