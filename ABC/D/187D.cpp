#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep3(i,N) for(int i = N - 1; i >= 0; i--)
#define rep4(i,N) for(int i = N; i > 0; i--)
#define replr(i,l,r) for(int i = l; i < r; i++)
#define all(x) x.begin(),x.end() 
#define allr(x) x.rbegin(),x.rend() 
typedef long long ll;
using P = pair<int,int>;
int main(){
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    ll aoki = 0;
    vector<ll> diff(n);
    rep(i,n){
        cin >> a[i] >> b[i];
        aoki += a[i];
        ll x = a[i] * 2 + b[i];
        diff.push_back(x);
    }
    sort(allr(diff));
    int cnt = 0;
    while(aoki >= 0){
        aoki -= diff[cnt];
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}
