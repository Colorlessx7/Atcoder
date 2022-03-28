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
    vector<char> s(3);
    rep(i,3){
        cin >> s[i];
    }
    vector<char> t(3);
    rep(i,3){
        cin >> t[i];
    }
    ll cnt = 0;
    rep(i,3){
        if(s[i] == t[i]){
            cnt++;
        }
    }
    ll ch = 0;
    if(cnt == 3){
        ch = 0;
    }else if(cnt == 1){
        ch = 1;
    }else if(cnt == 0){
        ch = 2;
    }
    ll ans = 1000000000000000000;
    ans -= ch;
    if(ans % 2 == 0){
        cout << "Yes" << endl;
    }else {
        cout << "No" << endl;
    }
    return 0;
}
