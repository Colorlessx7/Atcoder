#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n),b(n),c(m),d(m);
    rep(i,n){
        cin >> a[i] >> b[i];
    }
    rep(i,m){
        cin >> c[i] >> d[i];
    }
    vector<int> ans(n);
    int ch = INT_MAX; 
    rep(i,n){
        rep(j,m){
            int tmp = abs(a[i] - c[j]) + abs(b[i] - d[j]);
            if(ch > tmp){
                ch = tmp;
                ans[i] = j + 1;
            }
        }
        ch = INT_MAX;
    }
    rep(i,n){
        cout << ans[i] << endl;
    }
    return 0;
}
