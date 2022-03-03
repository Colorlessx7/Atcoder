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
int main(){
    int n;
    cin >> n;
    vector<int> s(n);
    int sum = 0;
    rep(i,n){
        cin >> s[i];
        sum += s[i];
    }
    sum++;
    vector<vector<bool>> dp(n+1,vector<bool>(sum));
    dp[0][0] = 1;
    rep2(i,n){
        rep(j,sum){
            if(dp[i-1][j] == 1){
                dp[i][j] = 1;
                dp[i][j+s[i-1]] = 1;
            }
        }
    }
    int ans = 0;
    for(int j = sum - 1; j >= 0; j--){
        if(dp[n][j]){
            if(j % 10 != 0){
                ans = j;
                break;
            }
        }
    }
    /*rep3(j,sum){
        cout << (dp[n][j] ? 1 : 0) << endl;
    }*/
    cout << ans << endl;
    return 0;
}
//dpを使う問題
//dpを使うということだけ解説で見て実装
