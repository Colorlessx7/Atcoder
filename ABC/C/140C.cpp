#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int n;
    cin >> n;
    vector<int> b(n - 1);
    rep(i,n - 1){
        cin >> b[i];
    }
    vector<int> a(n);
    a[0] = b[0];
    rep(i,n - 1){
        if(i == n - 2 || b[i] <= b[i + 1]){
            a[i + 1] = b[i]; 
        }else {
            a[i + 1] = b[i + 1];
        }   
    }
    int ans = 0;
    rep(i,n){
        ans += a[i];
    }
    cout << ans << endl;
    return 0;
}
