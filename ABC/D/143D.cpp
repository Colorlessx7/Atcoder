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
    vector<int> l(n);
    rep(i,n){
        cin >> l[i];
    }
    sort(all(l));
    ll ans = 0;
    rep(i,n){
        rep(j,i){
            int r = lower_bound(l.begin(),l.end(),l[i]+l[j]) - l.begin();
            ans += r - i - 1;
        }
    }
    cout << ans << endl;
    return 0;
}
//二分探索問題
//3変数全てで全探索するとtleするので2変数で全探索して残りの変数で2分探索する
//
