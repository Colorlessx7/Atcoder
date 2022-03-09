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
    vector<int> d(m);
    rep(i,m){
        cin >> d[i];
    }
    vector<vector<bool>> dp(m+1,vector<bool>(n+1,0));
    dp[0][0] = 1;
    rep(i,m){
        rep(j,n+1){
            if(dp[i][j]){
                dp[i+1][j] = 1;
                int x = n / d[i];
                rep2(k,x){
                    if(j + k*d[i] > n){
                        break;
                    }
                    dp[i+1][j+k*d[i]] = 1;
                }
            }
        }
    }
    cout << (dp[m][n] ? "Yes" : "No") << endl;
    return 0;
}

