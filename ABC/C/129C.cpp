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
using mint = modint1000000007;
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    rep(i,m){
        cin >> a[i];
    }
    vector<mint> dp(n+1);
    dp[0] = 1;
    int cnt = 0;
    if(cnt < m && a[cnt] == 1){
        dp[1] = 0;
        cnt++;
    }else {
        dp[1] = 1;
    }
    replr(i,2,n+1){
        if(cnt < m && a[cnt] == i){
            dp[i] = 0;
            cnt++;
            continue;
        }
        dp[i] = dp[i-2] + dp[i-1]; 
    }
    cout << dp[n].val() << endl;
    return 0;
}
//DPとmintで解く問題
//0段目を1通りとして1段目に穴があるかないかで0or1にして
//以降の穴がある部分もその場所のdpを0として
//以降はdpの処理でdp[i] = dp[i-2] + dp[i-1] とすれば解ける
//注意点として穴が存在しないパターンと全ての穴の地点を超えた後に
//次の穴の位置を見ようとしてa[i]が配列外参照を起こしてREすることがあるので注意
