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
    map<ll,ll> mp;
    rep(i,n){
        ll a;
        cin >> a;
        mp[a]++;
    } 
    rep(i,m){
        ll b;
        cin >> b;
        if(mp[b] == 0){
            cout << "No" << endl;
            return 0;
        }else {
            mp[b]--;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
