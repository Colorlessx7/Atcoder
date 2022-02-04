#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
int main(){
    int n;
    cin >> n;
    vector<int> d(n);
    rep(i,n){
        cin >> d[i];
    }
    sort(d.begin(),d.end());
    int ans = d[n / 2] - d[n / 2 - 1];
    cout << ans << endl; 
    return 0;
}
