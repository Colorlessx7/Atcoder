#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
    }
    ll max = a[0];
    ll ans = 0;
    rep(i,n){
        if(a[i] > max){
            max = a[i];
        }else {
            ans += max - a[i];
        }
    }
    cout << ans << endl;
    return 0;
}
