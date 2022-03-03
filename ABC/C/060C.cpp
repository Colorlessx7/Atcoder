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
    ll n, t;
    cin >> n >> t;
    vector<ll> t1(n),t2(n);
    rep(i,n){
        cin >> t1[i];
        t2[i] += t1[i] + t;
    }
    ll ans = 0;
    ll l = t1[0];
    ll r = 0;
    rep(i,n){
        if(i == n-1){
            r = t2[i];
            ans += r - l;
            continue;
        }
        if(t1[i+1] < t2[i]){
            continue;
        }else {
            r = t2[i];
            ans += r - l;
            l = t1[i+1];
        }
    }
    cout << ans << endl;
    return 0;
}
