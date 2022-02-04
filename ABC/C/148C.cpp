#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int a, b;
    cin >> a >> b;
    ll ans = a / (ll)gcd(a,b) * b;
    cout << ans << endl;  
    return 0;
}
