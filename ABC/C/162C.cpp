#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 1; i <= N; i++)
typedef long long ll;
int main(){
    int k;
    cin >> k;
    int ans = 0;
    int sub = 0;
    rep(i,k){
        rep(j,k){
            rep(l,k){
                sub = gcd(i,j);
                ans += gcd(sub,l);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
