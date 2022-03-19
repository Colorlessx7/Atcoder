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
    ll n;
    cin >> n;
    ll l = 0, r = 2e9;
    while(r - l > 1){
        ll m = (l + r) / 2;
        if(m * (m + 1) / 2 <= n + 1){
            l = m;
        }else {
            r = m;
        }
    }
    cout << n - l + 1 << endl;
    return 0;
}
//貪欲法・二分探索問題
//n+1の長さの丸太を小さいサイズ(1から)順に切り出していくのが最適解
//二分探索でr=n+1ではなくて2e9としている理由は二分探索の判定式にm^2が
//出てきてnが10^18なのでlong longの桁の限界を超えオーバーフローするため
//計算の都合1から順にサイズを大きくしながら切り出してもnの半分には到底及ばないため
//オーバーフローしない10^18の半分くらいまでを二分探索の範囲としている
