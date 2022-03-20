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
    int k;
    cin >> k;
    ll ans = 0;
    rep2(i,k){
        rep2(j,k){
            if(i * j > k){
                break;
            }
            ans += k / (i * j);
        }
    }
    cout << ans << endl;
    return 0;
}
//調和級数を使って変数2つで残り一つを固定し全探索する問題
//AB≤Kとなるような(A,B)の組はO(KlogK)個しかなく(キーワード:調和級数)、
//A,Bを固定したときCの候補はK/AB(の切り捨て)個であるため、
//この値の(A,B)の候補すべてに対する合計として答えを求めれば、
//O(KlogK)時間でこの問題を解くことができます。
