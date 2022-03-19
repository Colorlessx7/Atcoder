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
    int t;
    cin >> t;
    rep(i,t){
        ll a, b, c;
        cin >> a >> b >> c;
        ll ans = 0;
        ll v1 = min(b / 2, c);
        ans += v1;
        b -= 2 * v1;
        c -= v1;
        v1 = min(a/2, b/2);
        ans += v1;
        a -= 2 * v1;
        b -= 2 * v1;
        v1 = min(a, c/2);
        ans += v1;
        a -= v1;
        c -= 2 * v1;
        v1 = min(a/3, c);
        ans += v1;
        a -= 3 * v1;
        c -= v1;
        a /= 5;
        ans += a;
        cout << ans << endl;
    }
    return 0;
}
//貪欲法 複雑な証明があるらしい
//優先順位としては奇数3>使用用途の少ない4>使用用途の多い2
//で3,3,4:2,2,3,3:2,4,4:2,2,2,4:2,2,2,2,2,2の順で貪欲に計算
//複雑な照明では偶奇性を使って簡略化した後
//最適解の貪欲な計算順序を仮定と矛盾の照明で導出していた
