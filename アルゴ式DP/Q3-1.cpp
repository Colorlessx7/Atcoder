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
    vector<vector<bool>> dp(n,vector<bool>(m));
    vector<int> a(n-1);
    rep(i,n-1){
        cin >> a[i];
    }
    dp[0][0] = 1;
    rep(i,n-1){
        rep(j,m){
            if(dp[i][j]){
                dp[i+1][j] = 1;
                if(i <= n-2 && j + a[i] < m){
                    dp[i+1][j+a[i]] = 1;
                }
            }
        }
    }
    int ans = 0;
    rep(j,m){
        if(dp[n-1][j]){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
