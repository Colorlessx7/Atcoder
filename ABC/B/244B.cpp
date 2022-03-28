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
    string t;
    cin >> t;
    vector<ll> a(4);
    ll cnt = 0;
    rep(i,n){
        if(t[i] == 'S'){
            a[cnt]++;
        }
        if(t[i] == 'R'){
            cnt++;
            cnt %= 4;
        }
    }
    ll x = a[0] - a[2];
    ll y = a[3] - a[1];
    cout << x << " " << y << endl;
    return 0;
}
