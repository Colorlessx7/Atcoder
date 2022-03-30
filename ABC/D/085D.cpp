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
    ll n, h;
    cin >> n >> h;
    vector<ll> a(n),b(n);
    ll mx = 0;
    rep(i,n){
        cin >> a[i] >> b[i];
        //aの最大を探す
        mx = max(mx,a[i]);
    }
    ll ans = 0;
    //bを降順に並べる
    sort(allr(b));
    rep(i,n){
        if(b[i] > mx){
            if(h - b[i] <= 0){
                ans++;
                cout << ans << endl;
                return 0;
            }
            h -= b[i];
            ans++;
        }
    }
    ans += (h+mx-1)/mx;
    cout << ans << endl;
    return 0;
}
//貪欲法
//一番aが強い刀を振り続けた後、bの高い順に刀を投げ続ける
//考える上での優先順位はb > a
//hpが残る限りかつaの最大よりも大きいbの刀があるかぎりbの高い順に刀を投げ続け
//その処理が終わってもなおhpが残っているならaの最大の刀を振り続ける
