#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep3(i,N) for(int i = N - 1; i >= 0; i--)
#define rep4(i,N) for(int i = N; i > 0; i--)
#define replr(i,l,r) for(int i = l; i < r; i++)
#define reprl(i,l,r) for(int i = l; i > r; i--)
#define all(x) x.begin(),x.end() 
#define allr(x) x.rbegin(),x.rend() 
typedef long long ll;
using P = pair<int,int>;
int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
    }
    //解きやすいように降順sort
    sort(allr(a));
    ll ans = 0;
    //足せる回数
    int t = n-1;
    rep(i,n){
        //基本は2回たせる
        int lim = 2;
        //最初の要素だけ1回しか足すことができない
        if(i == 0){
            lim = 1;
        }
        //1要素に対してたせる回数までループ
        rep(j,lim){
            //たせる回数の総数が0になったらおしまい
            if(t > 0){
                //答えにa[i]を足す
                ans += a[i];
                //たせる回数の総数をひく
                t--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
//貪欲法のような問題
//​ans+=a[i/2]でも溶ける
