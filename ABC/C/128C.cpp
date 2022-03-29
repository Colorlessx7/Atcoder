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
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> s(n);
    rep(i,m){
        ll k;
        cin >> k;
        rep(j,k){
            ll g;
            cin >> g;
            g--;
            s[g].push_back(i);
        }
    }
    vector<ll> p(m);
    rep(i,m){
        cin >> p[i];
    }
    ll ans = 0;
    rep(i,1<<n){
        vector<ll> cnt(m);
        bool frag = true;
        rep(j,n){
            if(i & (1<<j)){
                for(ll v : s[j]){
                    cnt[v]++;
                }
            }
        }
        rep(j,m){
            if(cnt[j] % 2 != p[j]){
                frag = false;
            }
        }
        if(frag){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
