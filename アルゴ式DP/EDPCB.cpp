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
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    rep(i,n){
        cin >> h[i];
    }
    vector<int> dp(n);
    dp[0] = 0;
    replr(i,1,n){
        int x = i;
        if(x > k){
            x = k;
        }
        int f = i - 1;
        int mn = INT_MAX;
        rep(j,x){
            mn = min(dp[f]+abs(h[i]-h[f]),mn);
            f--;
        }
        dp[i] = mn;
    }
    cout << dp[n-1] << endl;
    return 0;
}
//A問題の1,2マス前のどっちから飛んでくるかを考えるときに
//その2つからminをとったが今回は1~kマス前のどこから飛ぶかを考えるから
//minをk回とる nより前にkマス存在しない場合を考えてその時は場合分けをする必要がある
