#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    rep(i,n){
        cin >> a[i];
    }
    rep(i,m){
        cin >> b[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    //カーソル 小さかった方を進める
    int ai = 0, bi = 0;
    //minを取るのででかい値を入れておく
    int ans = 1001001001;
    //カーソルがa,b配列の最後尾(最大値)になったら終了
    while(ai < n && bi < m){
        //a,bのカーソルが示す配列の値の差の最小値をansに格納
        ans = min(ans, abs(a[ai] - b[bi]));
        //カーソルの示す配列の値が小さい方を動かす
        if(a[ai] < b[bi]){
            ++ai;
        }else {
            ++bi;
        }
    }
    cout << ans << endl;
    return 0;
}
