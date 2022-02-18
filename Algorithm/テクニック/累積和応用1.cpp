//ABC177Cより 1つの整数列から1≤i<j≤Nを満たす
//全ての組 (i,j) についてのAi*Ajの和をmod10^9+7で求める問題
//言い換えるとAj*(Aj以前の累積和)の和となる
//a配列が1,2,3の時,1*2+1*3+2*3だが、これは1*2+(1+3)*3となり
//a[i]を2,3とすると1,1+3をxとしているのが下のプログラムである
//xの部分が累積和となっている

#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
using mint = modint1000000007;
int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
    }
    mint ans = 0;
    mint x = 0;
    rep(i,n){
        ans += a[i] * x;
        x += a[i];
    }
    cout << ans.val() << endl;
    return 0;
}
