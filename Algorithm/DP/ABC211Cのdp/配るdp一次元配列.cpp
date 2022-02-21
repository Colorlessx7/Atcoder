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
    vector<int> dp(9);
    dp[0] = 1;
    string t = "chokudai";
    rep(i,n){
        rep(j,8){
            if(s[i] == t[j]){
                (dp[j+1] += dp[j]) %= mod;
            }
        }
    }
    cout << dp[8] << endl;
    return 0;
}
//DP動的計画法で解く問題 配るDP一次元配列ver
//注意点:今回はchokudaiだから大丈夫だがaaaのような文字列だと
//a一つでa,aa,aaaができるというバグが発生する
//(本来はa一つのみの場合はaだけしか作れないようにしたい)
//この場合は一応rep(j,8)のループを後ろから回すことによってうまくいくらしい
