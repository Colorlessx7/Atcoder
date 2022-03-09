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
    vector<int> w(n);
    int m = 0;
    rep(i,n){
        cin >> w[i];
        m += w[i];
    }
    vector<vector<bool>> dp(n+1,vector<bool>(m+1));
    dp[0][0] = 1;
    rep(i,n){
        rep(j,m+1){
            if(dp[i][j]){
                dp[i+1][abs(j-w[i])] = 1;
                dp[i+1][j+w[i]] = 1;
            }
        }
    }
    rep(j,m+1){
        if(dp[n][j]){
            cout << j << endl;
            return 0;
        }
    }
    return 0;
}
