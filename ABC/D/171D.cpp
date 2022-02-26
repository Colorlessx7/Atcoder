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
    ll n;
    cin >> n;
    map<ll,ll> mp;
    ll sum = 0;
    rep(i,n){
        ll a;
        cin >> a;
        mp[a]++;
        sum += a;
    }
    ll q;
    cin >> q;
    rep(i,q){
        ll b, c;
        cin >> b >> c;
        if(mp[b] == 0){
            cout << sum << endl;
            continue;
        }
        sum += (c-b)*mp[b];
        mp[c] += mp[b];
        mp[b] = 0;
        cout << sum << endl;
    }
    return 0;
}
