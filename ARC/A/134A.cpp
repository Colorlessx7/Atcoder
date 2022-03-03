#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep3(i,N) for(int i = N - 1; i >= 0; i--)
#define rep4(i,N) for(int i = N; i > 0; i--)
#define all(x) x.begin(),x.end() 
typedef long long ll;
using P = pair<int,int>;
int main(){
    ll n, l, w;
    cin >> n >> l >> w;
    vector<ll> a(n+2);
    a[0] = 0;
    rep2(i,n){
        cin >> a[i];
    }
    a[n+1] = l;
    ll ans = 0;
    rep(i,n+1){
        if(i == 0 && a[i] < a[i+1]){
            ans += (a[i+1] - a[i] + w - 1) / w;
            continue;
        }
        if(a[i] + w < a[i+1]){
            ans += (a[i+1] - (a[i] + w) + w - 1) / w;
        }
    }
    cout << ans << endl;
    return 0;
}
