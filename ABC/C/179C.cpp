#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 1; i <= N; i++)
typedef long long ll;
int main(){
    int n;
    cin >> n;
    ll ans = 0;
    rep(i,n / 2){
        ans += (n - 1) / i;
    }
    ans += ((n - 1) - (n / 2));
    cout << ans << endl;
    return 0;
}
