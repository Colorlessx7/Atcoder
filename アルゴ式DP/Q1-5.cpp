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
    const int INF = 1001001001;
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
    }
    vector<int> dp(n,INF);
    dp[0] = 0;
    replr(i,1,n){
        int x;
        if(i >= m){
            x = m;
        }else {
            x = i;
        }
        rep2(j,x){
            dp[i] = min(dp[i],dp[i-j] + j * a[i]);
        }
    }
    cout << dp[n-1] << endl;
    return 0;
}
