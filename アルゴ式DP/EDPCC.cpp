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
    int n;
    cin >> n;
    vector<int> a(n),b(n),c(n);
    rep(i,n){
        cin >> a[i] >> b[i] >> c[i];
    }
    vector<vector<int>> dp(n,vector<int>(3));
    dp[0][0] = a[0];
    dp[0][1] = b[0];
    dp[0][2] = c[0];
    replr(i,1,n){
        dp[i][0] = max(dp[i-1][1],dp[i-1][2]) + a[i];
        dp[i][1] = max(dp[i-1][0],dp[i-1][2]) + b[i];
        dp[i][2] = max(dp[i-1][0],dp[i-1][1]) + c[i];
    }
    cout << max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2])) << endl;
    return 0;
}
//一次元配列でdpをしてdp[i]をi日目までの幸福の最大値とすると
//その前日にとった行動と同じものが選択できないという問題の都合上できない
//よって二次元配列でdpをする
//dp[i][j]とするとi,jはi日目に行動jをした場合のi日目までの幸福の最大値とすることができる
//するとdpの初期値は1日目に選んだ行動で得た幸福量なので
//dp[0][0]=a[0],dp[0][1]=b[0],dp[0][2]=c[0]となる
//2日目以降の状態遷移は現在の1日前に今日取る行動以外をした場合の幸福量の大きい方
//に今日とる行動の幸福量を足したものになる
//そして最終的にはn日目の各dpの最大値が答えとなる 
