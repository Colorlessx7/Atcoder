#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int l;
    cin >> l;
    ll ans = 1;
    for(int i = 1; i <= 11; ++i){
        ans *= l - i;
        ans /= i;
    }
    cout << ans << endl;
    return 0;
}
