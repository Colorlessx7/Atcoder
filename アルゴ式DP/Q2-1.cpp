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
    vector<vector<int>> dp(4,vector<int>(4));
    rep(i,4){
        cin >> dp[0][i];
    }
    replr(i,1,4){
        rep(j,4){
            if(j != 0){
                dp[i][j] += dp[i-1][j-1]; 
            }
            dp[i][j] += dp[i-1][j];
            if(j != 3){
                dp[i][j] += dp[i-1][j+1]; 
            }
        }
    }
    cout << dp[3][3] << endl;
    return 0;
}
