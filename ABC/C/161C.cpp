#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    ll n, k;
    cin >> n >> k;    
    ll ans1 = n % k;
    ll ans2 = k - ans1;
    ll ans = min(ans1,ans2);
    cout << ans << endl;
    return 0;
}
