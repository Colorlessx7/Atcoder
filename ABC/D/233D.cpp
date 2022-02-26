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
    ll n, k;
    cin >> n >> k; 
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
    }
    //累積和格納用配列(size+1)0初期化
    vector<ll> s(n+1);
    //累積和のi=rの時のr未満の範囲のk+slの登場頻度を格納
    map<ll,ll> mp;
    //累積和処理
    rep(i,n){
        s[i+1] = s[i]+a[i];
    }
    //答えカウント用
    ll ans = 0;
    rep(i,n+1){
        //累積和配列に今見ているsiよりk小さい値が
        //すでに登場しているのならその分答えを足す
        ans += mp[s[i]];
        //今後のsiを確認する上で今のsiよりk大きい値が出てきたら
        //答えにプラスされるように事前に頻度の調整をする
        mp[s[i]+k]++;
    }
    cout << ans << endl;
    return 0;
}
//累積和とmapを使って解く問題
//a1,a2,…,anが累積和で0,s1(0+a1),s2(s1+a2),…,sn(sn-1+an)となる
//区間の総和は累積和からsr-slで求めることができる
//区間の総和がkになればいいということはsr-sl=kで移項してsr=k+sl
//k+slをmapに都度格納することによってO(n)で求められる
//例が8,-3,5,7,0,-4なら累積和が0,8,5,10,17,17,13となり
//答えをカウントするループで
//mp ()の位置でansにたされる 
//0:0-0-0-0-0-0-0-0
//5:0-1-1-(1)-1-1-1-1
//8:0-0-0-0-0-0-0-0
//10:0-0-0-1-(1)-1-1-1
//13:0-0-1-1-1-1-1-(1)
//15:0-0-0-0-1-1-1-1
//17:0-0-0-0-0-0-0-0
//18:0-0-0-0-0-0-0-1
//22:0-0-0-0-0-1-2-2
//で答えが0-0-0-1-2-2-2-3
//となる
