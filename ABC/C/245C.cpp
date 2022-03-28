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
    vector<ll> a(n),b(n);
    rep(i,n){
        cin >> a[i];
    }
    rep(i,n){
        cin >> b[i];
    }
    vector<vector<bool>> dp(n,vector<bool>(2));
    dp[0][0] = true;
    dp[0][1] = true;
    replr(i,1,n){
        rep(j,2){
            if(dp[i-1][j]){
                if(j == 0){
                    if(k >= abs(a[i-1]-a[i])){
                        dp[i][0] = true;
                    }
                    if(k >= abs(a[i-1]-b[i])){
                        dp[i][1] = true;
                    }
                }
                if(j == 1){
                    if(k >= abs(b[i-1]-a[i])){
                        dp[i][0] = true;
                    }
                    if(k >= abs(b[i-1]-b[i])){
                        dp[i][1] = true;
                    }
                }
            }
        }
    }
    if(dp[n-1][0] || dp[n-1][1]){
        cout << "Yes" << endl;
    }else {
        cout << "No" << endl;
    }
    return 0;
}
