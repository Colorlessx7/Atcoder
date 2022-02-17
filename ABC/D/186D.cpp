#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    ll sum = 0;
    ll ans = 0;
    rep(j,n){
        //オーバーフローするのでllで計算
        ans += (ll)a[j] * j;
        ans -= sum;
        sum += a[j];
    }
    cout << ans << endl;
    return 0;
}
//絶対値の問題であるためsortして考えても問題ない
//仮にa(n)を1,3,5,7とすると
//愚直解は3-1,5-1,5-3,7-1,7-3,7-5だがこれは
//3-1,5*2-(1+3),7*3-(1+3+5)として考えられる
//この時上の解法では掛け算部を18行目,引き算を19行目,引く値の合計の調整を20行目でやっている
