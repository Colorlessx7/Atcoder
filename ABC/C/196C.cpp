#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i < N; i++)
typedef long long ll;
//左右同じものがくっついている(11,9898等)ものを用意する関数
ll f(ll x){
    //to_stringでxを文字列に
    string s = to_string(x);
    //s to iだと文字列をintにする　今回はllなのでs to ll
    return stoll(s + s);
}
int main(){
    ll n;
    cin >> n;
    ll x = 1;
    //x=1,2,~88,89でf(x)が11,22,~8888,8989みたいになる
    while(f(x) <= n){
        ++x;
    }
    //xをインクリメントしているのでwhileを超えたらxが条件をギリギリ超える値になっているから-1
    ll ans = x - 1;
    cout << ans << endl;
    return 0;
}
