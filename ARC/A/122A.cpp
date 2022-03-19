#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep3(i,N) for(int i = N - 1; i >= 0; i--)
#define rep4(i,N) for(int i = N; i > 0; i--)
#define replr(i,l,r) for(int i = l; i < r; i++)
#define reprl(i,l,r) for(int i = l; i > r; i--)
#define all(x) x.begin(),x.end() 
#define allr(x) x.rbegin(),x.rend() 
typedef long long ll;
using P = pair<int,int>;
using mint = modint1000000007;
int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
    }
    int sz = 4;
    vector<vector<pair<mint,mint>>> dp1(n+1);
    dp1[3].resize(2);
    dp1[3][0] = make_pair(2,1);
    dp1[3][1] = make_pair(2,1);
    dp1[4].resize(3);
    dp1[4][0] = make_pair(3,2);
    dp1[4][1] = make_pair(4,1);
    dp1[4][2] = make_pair(3,2);
    replr(i,5,n+1){
        if(n <= 4){
            break;
        }
        dp1[i].resize(sz);
        int x = i / 2;
        rep(j,x){
            dp1[i][j].first = dp1[i-1][j].first + dp1[i-2][j].first;
            dp1[i][j].second = dp1[i-1][j].second + dp1[i-2][j].second;
        }
        replr(j,x,sz){
            dp1[i][j].first = dp1[i][sz-1-j].first;
            dp1[i][j].second = dp1[i][sz-1-j].second;
        }
        sz++;
    }
    vector<mint> dpfibo(n+1);
    dpfibo[0] = 1;
    dpfibo[1] = 1;
    replr(i,2,n+1){
        dpfibo[i] = dpfibo[i-1] + dpfibo[i-2];
    }
    mint ans = dpfibo[n] * a[0];
    rep(i,n-1){
        ans += dp1[n][i].first * a[i+1];
        ans -= dp1[n][i].second * a[i+1];
    }
    cout << ans.val() << endl;
    return 0;
}
//TLE解
//DPを二次元配列pairでやったもの
