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
    ll a, b, c;
    cin >> a >> b >> c;
    ll x = 2 * b - a - c;
    ll ans = 0;
    if(x >= 0){
        ans = x;
    }else {
        ll num = 0 - x;
        num = (num + 2 - 1) / 2;
        x += 2 * num;
        ans += x + num;
    }
    cout << ans << endl;
    return 0;
}
//数列Aが等差数列であることは、2A2−A1−A3=0と同値
//上の式をXとするとできる操作は
//X に −1 を加える（i=1,3 とした場合）
//X に 2 を加える （i=2 とした場合）
//となるためXに何回操作を加えたら最小で0になるか計算する
