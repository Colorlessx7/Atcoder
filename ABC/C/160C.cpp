#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int k, n;
    cin >> k >> n;
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    vector<int> diff(n);
    rep(i,n){
        diff[i] = a[i + 1] - a[i];
    }
    diff[n - 1] = (k - a[n - 1]) + (a[0] - 0);
    int ex = 0;
    rep(i,n){
        ex = max(ex,diff[i]);
    }
    int ans = 0;
    rep(i,n){
        ans += diff[i];
    }
    ans -= ex;
    cout << ans << endl;
    return 0;
}
