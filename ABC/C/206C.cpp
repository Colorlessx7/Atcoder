#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    ll n;
    cin >> n;
    map<int,int> mp;
    rep(i,n){
        int a;
        cin >> a;
        mp[a]++;
    }
    ll now = n;
    ll ans = 0;
    for(auto p : mp){
        now -= p.second;
        ans += now * p.second;
    }
    cout << ans << endl;
    return 0;
}
