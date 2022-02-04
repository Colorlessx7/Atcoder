#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> h(n);
    rep(i,n){
        cin >> h[i];
    }
    vector<bool> c(n,1);
    rep(i,m){
        int a, b;
        cin >> a >> b;
        a--; 
        b--;
        if(h[a] > h[b]){
            c[b] = 0;
        }else if(h[a] < h[b]){
            c[a] = 0;
        }else if(h[a] = h[b]){
            c[a] = 0;
            c[b] = 0;
        }
    }
    int ans = 0;
    rep(i,n){
        if(c[i] == 1){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
