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
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> x(n);
    rep(i,n){
        cin >> x[i];
    }
    vector<vector<bool>> dp(n+1,vector<bool>(a));
    dp[0][0] = 1;
    rep(i,n){
        rep(j,a){
            if(dp[i][j]){
                dp[i+1][j] = 1;
                dp[i+1][(j+x[i])%a] = 1;
            }
        }
    }
    cout << (dp[n][b] ? "Yes" : "No") << endl;
    return 0;
}

