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
    ll n;
    cin >> n;
    ll k = 0;
    ll nn = n;
    while(nn){
        k++;
        nn /= 10;
    }
    ll ans = LLONG_MAX;
    string x = to_string(n);
    vector<char> x2(k);
    rep(i,k){
        x2[i] = x[i];
    }
    replr(i,1,1<<k){
        string y = "";
        ll cnt = 0;
        rep(j,k){
            if(i & (1 << j)){
                y += x2[j];
            }else {
                cnt++;
            }
        }
        ll num = stoll(y);
        if(num % 3 == 0){
            ans = min(ans,cnt);
        }
    }
    if(ans != LLONG_MAX){
        cout << ans << endl;
    }else {
        cout << -1 << endl;
    }
    return 0;
}
//
