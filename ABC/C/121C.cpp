#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    rep(i,n){
        cin >> a[i] >> b[i];
    }
    vector<pair<int, int>> ab(n);
    rep(i,n){
        ab[i] = make_pair(a[i],b[i]);
    }
    sort(ab.begin(),ab.end());
    long long ans = 0;
    rep(i,n){
        int buy = min(m, ab[i].second);
        ans += (long long)buy * ab[i].first;
        m -= buy;
    }
    cout << ans << endl;
    return 0;
}
