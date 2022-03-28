#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(ll i = 0; i < N; i++)
#define rep2(i,N) for(ll i = 1; i <= N; i++)
#define rep3(i,N) for(ll i = N - 1; i >= 0; i--)
#define rep4(i,N) for(ll i = N; i > 0; i--)
#define replr(i,l,r) for(ll i = l; i < r; i++)
#define reprl(i,l,r) for(ll i = l; i > r; i--)
#define all(x) x.begin(),x.end() 
#define allr(x) x.rbegin(),x.rend() 
typedef long long ll;
using P = pair<ll,ll>;
int main(){
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i,n){
        cin >> p[i];
        p[i]--;
    }
    vector<ll> c;
    ll cnt = 0;
    rep(i,n){
        if(p[i] == i){
            cnt++;
        }else {
            if(cnt != 0){
                c.push_back(cnt);
                cnt = 0;
            }
        }
    }
    if(cnt != 0){
        c.push_back(cnt);
    }
    ll ans = 0;
    n = c.size();
    rep(i,n){
        ans += (c[i]+2-1)/2;
    }
    cout << ans << endl;
    return 0;
}
