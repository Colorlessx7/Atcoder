#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    ll n;
    cin >> n;
    ll l = 1;
    int cnt = 0;
    ll ans = 0;
    while(l <= n){
        ll r = l * 1000;
        ll len = min(n + 1,r) - l;
        ans += len * cnt;
        l *= 1000;
        cnt++;
    }
    cout << ans << endl;
    return 0;
}
