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
    vector<vector<int>> dp(n+1,vector<int>(m));
    vector<int> a(n-1);
    vector<int> b(n-1);
    rep(i,n-1){
        cin >> a[i];
    }
    rep(i,n-1){
        cin >> b[i];
    }
    rep(i,n){
        rep(j,m){
            if(j == 0 || dp[i][j] != 0){
                dp[i+1][j] = max(dp[i][j],dp[i+1][j]);
                if(j + a[i] < m){
                    dp[i+1][j+a[i]] = max(dp[i+1][j+a[i]],dp[i][j]+b[i]);
                }
            }
        }
    }
    /*rep(i,n){
        rep(j,m){
            cout << dp[i][j];
        }
        cout << endl;
    }*/
    if(dp[n-1][m-1] == 0){
        cout << -1 << endl;
    }else {
        cout << dp[n-1][m-1] << endl;
    }
    return 0;
}
