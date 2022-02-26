#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep3(i,N) for(int i = n - 1; i >= 0; i--)
#define rep4(i,N) for(int i = n; i > 0; i--)
#define all(x) x.begin(),x.end() 
typedef long long ll;
using P = pair<long long,long long>;
vector<ll> calc(ll x){
    vector<ll> ret(8);
    ret[0] = x+1;
    ret[1] = x+2;
    ret[2] = x+2;
    ret[3] = x+1;
    ret[4] = x-1;
    ret[5] = x-2;
    ret[6] = x-2;
    ret[7] = x-1;
    return ret;
}
vector<ll> calc2(ll y){
    vector<ll> ret(8);
    ret[0] = y+2;
    ret[1] = y+1;
    ret[2] = y-1;
    ret[3] = y-2;
    ret[4] = y-2;
    ret[5] = y-1;
    ret[6] = y+1;
    ret[7] = y+2;
    return ret;
}
int main(){
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    vector<ll> ax(8);
    vector<ll> ay(8);
    vector<ll> bx(8);
    vector<ll> by(8);
    ax = calc(x1);
    ay = calc2(y1);
    bx = calc(x2);
    by = calc2(y2);
    rep(i,8){
        rep(j,8){
            if(ax[i]==bx[j]&&ay[i]==by[j]){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
