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
using mint = modint998244353;
int main(){
    ll n;
    cin >> n;
    vector<ll> a(n),b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    vector<vector<mint>> dp(n,vector<mint>(3001));
    replr(i,a[0],b[0]+1){
        dp[0][i] = 1;
    }
    rep(i,n-1){
        rep(j,3001){
            if(dp[i][j] != 0){
                ll mx = max(j,a[i+1]);
                replr(k,mx,b[i+1]+1){
                    dp[i+1][k] += dp[i][j];
                }
            }
        }
    }
    mint ans = 0;
    rep(i,3001){
        ans += dp[n-1][i];
    }
    cout << ans.val() << endl;
    return 0;
}
//dptle解
