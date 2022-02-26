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
vecter<P> calc(ll x, ll y){
    vector<P> ret(8);
    ret[0].first = x+1;
    ret[0].second = y+2;
    ret[1].first = x+2;
    ret[1].second = y+1;
    ret[2].first = x+2;
    ret[2].second = y-1;
    ret[3].first = x+1;
    ret[3].second = y-2;
    ret[4].first = x-1;
    ret[4].second = y-2;
    ret[5].first = x-2;
    ret[5].second = y-1;
    ret[6].first = x-2;
    ret[6].second = y+1;
    ret[7].first = x-1;
    ret[7].second = y+2;
    return ret;
}
int main(){
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    vector<P> a(8);
    vector<P> b(8);
    a = calc(x1,y1);
    b = calc(x2,y2);
    rep(i,8){
        rep(j,8){
            if(a[i].first==b[j].first&&a[i].second==b[j].second){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
