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
    vector<bool> a(2002);
    ll cnt = 0;
    while(1){
        rep2(i,2001){
            if(!a[i]){
                cout << i << endl;
                a[i] = true;
                cnt++;
                break;
            }
        }
        if(cnt == 2 * n + 1){
            break;
        }
        ll aoki;
        cin >> aoki;
        a[aoki] = true;
        cnt++; 
    }
    return 0;
}
