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
const ll mod = 998244353;
int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
    }
    vector<vector<ll>> dp(n,vector<ll>(10,0));
    dp[0][a[0]] = 1;
    rep(i,n-1){
        rep(j,10){
            if(dp[i][j] != 0){
                ll x = (a[i+1] + j) % 10;
                ll y = (a[i+1] * j) % 10;
                //modをとるときは+=だと機能しないのでこの形にする
                dp[i+1][x] = (dp[i][j] + dp[i+1][x]) % mod;
                dp[i+1][y] = (dp[i][j] + dp[i+1][y]) % mod;
            }
        }
    }
    rep(i,10){
        cout << dp[n-1][i] << endl;
    }
    return 0;
}
//DPでとく問題
//解説でdpでとくことだけ見て実装してAC
//とりうる値が0~9の10通りなのでDPでとく
