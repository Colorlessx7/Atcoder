#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    rep(i,n){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    double ans = v[0];
    rep(i,n - 1){
        ans = (ans + v[i+1]) / 2; 
    }
    cout << ans << endl;
    return 0;
}
