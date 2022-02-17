#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
typedef long long ll;
int main(){
    int n;
    cin >> n;
    vector<int> p(n), q(n);
    rep(i,n) cin >> p[i];
    rep(i,n) cin >> q[i];
    vector<int> a(n);
    rep(i,n) a[i] = i+1;
    
    map<vector<int>, int> mp;
    do {
        //順列を全てmapに格納,mapのサイズがその時の順列の何番目かに対応
        mp[a] = mp.size();
    } while (next_permutation(a.begin(), a.end()));
    
    int ans = abs(mp[p] - mp[q]);
    cout << ans << endl;
    return 0;
}
