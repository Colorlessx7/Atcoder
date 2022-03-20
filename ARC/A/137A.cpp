#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep3(i,N) for(int i = N - 1; i >= 0; i--)
#define rep4(i,N) for(int i = N; i > 0; i--)
#define replr(i,l,r) for(ll i = l; i < r; i++)
#define reprl(i,l,r) for(ll i = l; i > r; i--)
#define all(x) x.begin(),x.end() 
#define allr(x) x.rbegin(),x.rend() 
typedef long long ll;
using P = pair<ll,ll>;
int main(){
    ll l, r;
    cin >> l >> r;
    ll ans = 0;
    ll ans1 = 0;
    ll ans2 = 0;
    reprl(i,r,l){
        if(gcd(i,l) == 1){
            ans1 = i - l;
            break;
        }
    }
    replr(i,l,r){
        if(gcd(i,r) == 1){
            ans2 = r - i;
            break;
        }
    }
    ans = max(ans1,ans2);
    for(ll i = l; i <= l + 1000; i++){
        for(ll j = r; j >= r - 1000; j--){
            ll gd = gcd(i,j);
            if(gd == 1){
                gd = j-i;
            }else {
                continue;
            }
            ans = max(ans,gd);
        }
    }
    cout << ans << endl;
    return 0;
}
