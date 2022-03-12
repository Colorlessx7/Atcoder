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
    vector<int> h(n);
    rep(i,n){
        cin >> h[i];
    }
    vector<int> dp(n);
    //最初の足場に立っているときはコストを払っていないので0初期化
    dp[0] = 0;
    //DP処理部分
    replr(i,1,n){
        //i=1からループを回すが1の時だけは2つ前に足場が存在しないので
        //+1マス飛ぶことしか出来ない為、処理を分ける
        if(i >= 2){
            dp[i] = min((dp[i-2]+abs(h[i]-h[i-2])),(dp[i-1]+abs(h[i]-h[i-1])));
        }else {
            dp[i] = dp[i-1]+abs(h[i]-h[i-1]);
        }
    }
    //nマス目の最小コストを出力
    cout << dp[n-1] << endl;
    return 0;
}
//一次元配列DPで解く問題
//逆から考えると足場Nに辿り着くにはN-1かN-2の足場から飛び移るしかない
//よって足場iに辿り着くまでの最小コストをdp[i]とすると
//dp[n-1]+abs(h[n-1]-h[n])とdp[n-2]+abs(h[n-2]-h[n])の小さい方が答えとなる
//
