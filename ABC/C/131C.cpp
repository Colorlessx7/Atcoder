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
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll lcm = c / gcd(c,d) * d;
    ll scale = lcm / c + lcm / d - 1;
    scale = lcm - scale;
    ll x1 = a / lcm;
    if(a % lcm != 0){
        x1++; 
    }
    ll x2 = b / lcm;
    ll ans = 0;
    ans += (x2 - x1) * scale;
    ll left = x1 * lcm - a + 1;
    ll right = b - x2 * lcm;
    ll l = (left + c - 1) / c + (left + d - 1) / d;
    //ll r = (right + c - 1) / c + (right + d - 1) / d - 1;
    //ll l = left / c + left / d;
    ll r = right / c + right / d;
    ans += left + right - l - r + 1;
    /*cout << left << endl;
    cout << right << endl;
    cout << l << endl;
    cout << r << endl;*/
    cout << ans << endl;
    return 0;
}
//scale:最小公倍数1スパンで登場するc,dで割り切れない数の総数
//自分で無理やり計算したver
