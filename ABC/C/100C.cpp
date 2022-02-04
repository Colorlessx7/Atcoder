#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
    }
    int ans =0;
    rep(i,n){
        while(a[i] % 2 == 0){
            a[i] /= 2;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
