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
    ll t;
    cin >> t;
    rep(i,t){
        ll l, r;
        cin >> l >> r;
        //Aを決めた時の式の数に関する等差数列の長さ
        ll x = r - 2 * l;
        //幅を考える上で上の式では重なりを無視していたので+1
        x++;
        //等差数列の和
        ll ans = (x*(1+x))/2;
        //答えが0のパターンlとrが同じでかつ0でない時
        if(l == r && l != 0){
            ans = 0;
        }
        //答えが0のパターン2l>rの時(500~520では520-500してもCが500以上にならない)
        if(2 * l > r){
            ans = 0;
        }
        cout << ans << endl;
    }
    return 0;
}
//サンプルの説明に着目
//A:4の式が1つ,A:5の式が2つ,A:6の式が3つという部分から法則性を考える
//
