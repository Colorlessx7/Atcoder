#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int n;
    cin >> n;
    vector<ll> l(n),r(n);
    rep(i,n){
        int t;
        cin >> t >> l[i] >> r[i];
        //閉区間と開区間の4パターンを全て閉区間として考えたい
        //全てを2倍して、開区間の部分を1ずらすと全て閉区間として扱える
        l[i] *= 2;
        r[i] *= 2;
        //左端が開区間なら+1方向にずらす
        if(t >= 3){
            l[i]++;
        }
        //右端が開区間なら-1方向にずらす
        if(t % 2 == 0){
            r[i]--;
        }
    }
    int ans = 0;
    //同じペアを2回やらないように
    //rep(i,n)rep(j,i)でjは常にi未満を試すため重複なくできる
    rep(i,n){
        rep(j,i){
            //閉区間同士が被ってないか判定
            if(r[i] < l[j]){
                continue;
            }
            if(r[j] < l[i]){
                continue;
            }
            //被っている場合+
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}
