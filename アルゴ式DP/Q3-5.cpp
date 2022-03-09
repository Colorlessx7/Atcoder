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
    int n, m;
    cin >> n >> m;
    vector<int> w(n);
    rep(i,n){
        cin >> w[i];
    }
    const int INF = 1001001001;
    vector<vector<int>> dp(n+1,vector<int>(m+1,INF));
    dp[0][0] = 0;
    rep(i,n){
        rep(j,m+1){
            if(dp[i][j] != INF){
                dp[i+1][j] = min(dp[i][j],dp[i+1][j]);
                if(j + w[i] <= m){
                    dp[i+1][j+w[i]] = min(dp[i+1][j+w[i]],dp[i][j]+1);
                }
            }
        }
    }
    if(dp[n][m] == INF){
        cout << -1 << endl;
    }else {
        cout << dp[n][m] << endl;
    }
    return 0;
}
