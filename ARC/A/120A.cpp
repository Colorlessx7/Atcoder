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
    vector<ll> rs(n+1);
    rs[0] = 0;
    ll maxa = 0;
    ll sum = 0;
    rep(i,n){
        cin >> a[i];
    }
    rep2(i,n){
        rs[i] = rs[i-1] + a[i-1];
    }
    ll ans = 0;
    rep(i,n){    
        maxa = max(maxa,a[i]);
        sum += rs[i+1];
        ans = sum + ((ll)i+1) * maxa;
        cout << ans << endl;
    }
    return 0;
}
//3 1,2,3の場合
//k=1の時a=(1)でmax=1、f(a)=(a[0]+max)=(1+1)=2となる
//k=2の時a=(1,2)でmax=2,f(a)を考えるとき一つ目の1でmax足してf(a)=(1+2)+...=3+...
//maxより大きくなったのでmaxを3に更新,二つ目の2でmax足してf(a)=3+(2+3)=8
//k=3時a=(1,2,3)でmax=3,一つ目の1でmax足してf(a)=(1+3)+...=4+...
//maxより大きくなったのでmaxを4に更新,二つ目の2でmax足してf(a)=4+(2+4)+...=10+...
//maxより大きくなったのでmaxを6に更新,三つ目の3でmax足してf(a)=10+(3+6)=19
//という挙動をとる
//i=1でf(a)=A+m1
//i=2でf(a)=2A+B+2m2
//i=3でf(a)=3A+2B+C+3m3
//i=nでf(a)=nm+na1+(n-1)a2+(n-2)a3+⋯+1⋅an(ただしnはaの長さ)
//nmの項はmを更新した上で毎回計算する
//na1+(n−1)a2+(n−2)a3+⋯+1⋅anはnが1増えるため
//a1+a2+a3+⋯+anだけ増えるから、常にこの値を持っておいて足す(または累積和を持っておく)
//新たに1⋅an+1=xという項が増えるのでxを足す
//常にA1,A2,A3,…,Aiの合計及び最大値を持ちながらf(a)の値を更新していくことでO(N)で解く
