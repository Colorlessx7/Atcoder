#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep3(i,N) for(int i = N - 1; i >= 0; i--)
#define rep4(i,N) for(int i = N; i > 0; i--)
#define all(x) x.begin(),x.end() 
typedef long long ll;
using P = pair<int,int>;
using mint = modint998244353;
int main(){
    ll n;
    cin >> n;
    vector<vector<mint>> dp(n,vector<mint>(9));
    rep(j,9){
        dp[0][j] = 1;
    }
    for(int i = 1; i < n; i++){
        rep(j,9){
            if(j != 0){
                dp[i][j] += dp[i-1][j-1];
            }
            dp[i][j] += dp[i-1][j];
            if(j != 8){
                dp[i][j] += dp[i-1][j+1];
            }
        }
    }
    mint ans = 0;
    rep(j,9){
        ans += dp[n-1][j];
    }
    cout << ans.val() << endl;
    return 0;
}
