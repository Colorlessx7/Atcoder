#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> l(m),r(m);
    rep(i,m){
        cin >> l[i] >> r[i];
    }
    int maxl = 1;
    int minr = n;
    int ans = 0;
    rep(i,m){
        maxl = max(maxl,l[i]);
        minr = min(minr,r[i]);
    }
    ans = minr - maxl + 1;
    ans = max(ans,0);
    cout << ans << endl;
    return 0;
}
