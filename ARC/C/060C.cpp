#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep3(i,N) for(int i = N - 1; i >= 0; i--)
#define rep4(i,N) for(int i = N; i > 0; i--)
#define replr(i,l,r) for(int i = l; i < r; i++)
#define all(x) x.begin(),x.end() 
typedef long long ll;
using P = pair<int,int>;
int main(){
    int n, a;
    cin >> n >> a;
    vector<ll> x(n);
    rep(i,n){
        cin >> x[i];
    }
    vector<vector<vector<ll>>> dp(51,vector<vector<ll>>(51,vector<ll>(3010)));
    dp[0][0][0] = 1;
    replr(i,0,n){
        rep(j,n+1){
            rep(k,2500){
                if(dp[i][j][k]){
                    dp[i+1][j+1][k+x[i]] += dp[i][j][k];
                    dp[i+1][j][k] += dp[i][j][k];
                }
            }
        }
    }
    ll ans = 0;
    replr(i,1,n+1){
        ans += dp[n][i][i*a];
    }
    cout << ans << endl;
    return 0;
}
//dp[i][j][k] = i枚目までのカードでj枚選んで合計がkである組合せ
//カードを選ばない dp[i + 1][j][k] += dp[i][j][k]
//カードを選ぶ dp[i + 1][j + 1][k + x[i]] += dp[i][j][k]
