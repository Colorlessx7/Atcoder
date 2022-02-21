//ABC211Cより　文字列sから8文字選びそれが左からchokudaiになってるパターン数

#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep3(i,N) for(int i = n - 1; i >= 0; i--)
#define rep4(i,N) for(int i = n; i > 0; i--)
#define all(x) x.begin(),x.end() 
typedef long long ll;
using P = pair<int,int>;
using mint = modint1000000007;
const int mod = 1000000007;
int main(){
    string s;
    cin >> s;
    int n = s.size();
    //dp用配列は番兵(配列外参照回避)込みのサイズ
    //行が空文字列とsのサイズ分の合計n+1個
    //列が空文字列,c,ch…,chokudaiの8+1=9個
    vector dp(n+1, vector<int>(9));
    //番兵要素の設定で1行目の全列に1を代入
    rep(i,n+1){
        dp[i][0] = 1;
    }
    //比較用文字列tの準備
    string t = "chokudai";
    rep(i,n){
        rep(j,8){
            //s文字列のi番目の文字とtのj番目の文字が違う場合
            //一つ前の列と値が同じになる
            //同じだった場合は1つ前の列の値とその上にある値の合計になる
            //ただ値が大きくなるため計算時にmodをとる
            if(s[i] != t[j]){
                dp[i+1][j+1] = dp[i][j+1];
            }else {
                dp[i+1][j+1] = (dp[i][j+1] + dp[i][j]) % mod;
            }
        }
    }
    //最終的な答えがdp[n][8]に格納されるのでそれを出力
    cout << dp[n][8] << endl;
    return 0;
}
//DP動的計画法で解く問題 もらうDPver
//     abcababc
//    111111111
//  a 011122333
// ab 001113366
//abc 000111117
//abcで考えると上のようになる(横i,縦j)
//この時漸化式はdp[i+1][j+1]=
//1                     (j=0)
//0                     (i=0,1<=j<=3)この時の3はa,b,cの個数としての3
//dp[i][j+1]            (1≤i≤N,1≤j≤3,S[i]!=T[j])3は上と同様
//dp[i][j+1] + dp[i][j] (1≤i≤N,1≤j≤3,S[i]==T[j])3は上と同様
