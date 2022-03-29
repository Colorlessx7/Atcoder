#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(ll i = 0; i < N; i++)
#define rep2(i,N) for(ll i = 1; i <= N; i++)
#define rep3(i,N) for(ll i = N - 1; i >= 0; i--)
#define rep4(i,N) for(ll i = N; i > 0; i--)
#define replr(i,l,r) for(ll i = l; i < r; i++)
#define reprl(i,l,r) for(ll i = l; i > r; i--)
#define all(x) x.begin(),x.end() 
#define allr(x) x.rbegin(),x.rend() 
typedef long long ll;
using P = pair<ll,ll>;
int main(){
    ll n, k;
    cin >> n >> k;
    vector<vector<ll>> dp(n,vector<ll>(k));
    rep(i,k){
        dp[0][i] = 1;
    }
    rep(i,n-1){
        rep(j,k){
            rep(l,k){
                if(j == l){
                    continue;
                }
                dp[i+1][l] += dp[i][j];
            }
        }
    }
    ll ans = 0;
    rep(i,k){
        ans += dp[n-1][i]; 
    }
    cout << ans << endl;
    return 0;
}
