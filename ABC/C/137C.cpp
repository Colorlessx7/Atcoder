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
ll choose2(ll n){
    return n*(n-1)/2;
}
int main(){
    int n;
    cin >> n;
    map<vector<int>,int> mp;
    rep(i,n){
        string s;
        cin >> s;
        vector<int> sc(26,0);
        rep(j,10){
            int x = s[j] - 'a';
            sc[x]++;
        }
        mp[sc]++;
    }
    ll ans = 0;
    for(auto p : mp){
        if(p.second >= 2){
            ans += choose2(p.second);
        }
    }
    cout << ans << endl;
    return 0;
}
