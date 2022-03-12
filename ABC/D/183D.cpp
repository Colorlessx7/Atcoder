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
    ll n, w;
    cin >> n >> w;
    vector<ll> a(200010);
    rep(i,n){
        ll s, t, p;
        cin >> s >> t >> p;
        a[s] += p;
        a[t] -= p;
    }
    ll sum = 0;
    vector<ll> rs(200010);
    rep(i,200010){
        sum += a[i];
        rs[i] = sum;
    }
    sort(allr(rs));
    cout << (rs[0] > w ? "No" : "Yes") << endl;
    return 0;
}
//DPでは配列サイズがきついのでシミュレーションする問題
//特定の時間での湯の消費の変動量をaという配列で持って
//[S,T)の区間でP消費量が増えるというのをa[s]で+p
//a[t]で-pとして最終的にa配列の累積和をとると単位時間毎の湯の必要量がわかる
//その累積和配列をsort,reverseしてrs[0]が消費量の最大値となるので
//この時点で供給限界のwを超えているならNo,超えてないならYesを出力する
