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
using P = pair<ll,ll>;
using mint = modint998244353;
int main(){
    ll a, b, c;
    cin >> a >> b >> c;
    mint ans = a * (a+1);
    ans *= b * (b+1);
    ans *= c * (c+1);
    ans /= 8;
    cout << ans.val() << endl;
    return 0;
}
//Wolfram Alphaに突っ込め
