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
    string s;
    cin >> s;
    ll ans = 0;
    vector<ll> d;
    char x = s[0];
    ll cnt = 1;
    for(int i = 1; i < n; i++){
        if(x != s[i]){
            d.push_back(cnt);  
            cnt = 1;
            x = s[i];
            continue;
        }
        cnt++;
    }
    d.push_back(cnt);
    n = d.size();
    rep(i,n){
        if(d[i] >= 2){
            ans += choose2(d[i]);
        }
    }
    cout << ans << endl;
    return 0;
}
