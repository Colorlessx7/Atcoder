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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(m);
    vector<ll> rs;
    rep(i,m){
        cin >> a[i];
    }
    a.push_back(0);
    a.push_back(n+1);
    sort(all(a));
    ll x = LLONG_MAX;
    rep(i,a.size()-1){
        ll ai = a[i+1] - a[i] - 1;
        if(ai == 0){
            continue;
        }
        x = min(x,ai);
        rs.push_back(ai);
    }
    ll ans = 0;
    rep(i,rs.size()){
        ans += (rs[i] + x - 1) / x;
    }
    cout << ans << endl;
    return 0;
}
