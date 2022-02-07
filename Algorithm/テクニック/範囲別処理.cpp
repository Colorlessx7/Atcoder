//ABC195Cより　1~999,1000~999999など値の範囲によって計算が違う場合、
//値の範囲の左端をl右端をrとして同じ数字で都度倍することにより範囲別で処理させることができる

#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    ll n;
    cin >> n;
    ll l = 1;
    int cnt = 0;
    ll ans = 0;
    while(l <= n){
        ll r = l * 1000;
        ll len = min(n + 1,r) - l;
        ans += len * cnt;
        l *= 1000;
        cnt++;
    }
    cout << ans << endl;
    return 0;
}
