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
    vector<int> v(n);
    rep(i,n){
        cin >> w[i];
    }
    rep(i,n){
        cin >> v[i];
    }
    vector<vector<int>> dp(n+1,vector<int>(m+1));
    rep(i,n){
        rep(j,m+1){
            if(j >= w[i]){
                dp[i+1][j] = max(dp[i][j-w[i]]+v[i],dp[i][j]);
            }else {
                dp[i+1][j] = dp[i][j];
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}

