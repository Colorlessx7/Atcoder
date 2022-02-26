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
    ll n, m, x;
    cin >> n >> m >> x;
    vector<ll> c(n);
    vector<vector<ll>> a(n,vector<ll>(m));
    rep(i,n){
        cin >> c[i];
        rep(j,m){
            cin >> a[i][j];
        }
    }
    ll k = 1 << n;
    vector<ll> ch(m);
    bool f = 0;
    ll sum = 0;
    ll ans = LLONG_MAX;
    for(int i = 0; i < k; i++){
        sum = 0;
        f = 0;
        rep(k,m){
            ch[k] = 0;
        }
        rep(j,n){
            if(i>>j&1){
                sum += c[j];
                rep(k,m){
                    ch[k] += a[j][k];
                }
            }
        }
        rep(k,m){
            if(ch[k] < x){
                f = 1;
                break;
            }
        }
        if(f){
            continue;
        }
        ans = min(ans,sum);
    }
    if(ans == LLONG_MAX){
        ans = -1;
    }
    cout << ans << endl;
    return 0;
}
