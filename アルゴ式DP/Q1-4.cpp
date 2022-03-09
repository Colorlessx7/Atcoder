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
    int n;
    cin >> n;
    vector<int> dp(n+1);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    replr(i,4,n+1){
        dp[i] += dp[i-1] + dp[i-2] + dp[i-3];
    }
    cout << dp[n] << endl;
    return 0;
}
