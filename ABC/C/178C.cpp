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
const int mod = 1000000007;
int main(){
    ll n;
    cin >> n;
    mint ans = pow_mod(10,n,mod) - pow_mod(9,n,mod) - pow_mod(9,n,mod) + pow_mod(8,n,mod);
    cout << ans.val() << endl;
    return 0;
}
//包除原理とACLのpow_mod
//ACLのpow_modは引数が(ll a,ll n,int mod)となっていて
//a^n%modが求められる
//包除原理はベン図の考え方で
//a:全体(10^n),b:Ai=0なるiが存在しない数列のパターン数(9^n)
//c:Ai=9なるiが存在しない数列のパターン数(9^n)
//d:Ai=0又は9なるiが存在しない数列のパターン数(8^n)
//ベン図に置き換えるとわかりやすい
//一応dp[i][j][k]でi:何番目の数字まで決めたか,j:0を既に使っているか,k:9を既に使っているか
//で溶けるらしい
