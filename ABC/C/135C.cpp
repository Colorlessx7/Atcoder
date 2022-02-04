#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 0; i <= N; i++)
typedef long long ll;
int main(){
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n);
    rep(i,n + 1){
        cin >> a[i];
    }
    rep(i,n){
        cin >> b[i];
    }
    ll ans = 0;
    rep(i,n){
        ll left = min(a[i],b[i]);//左に全力
        ans += left;
        a[i] -= left;//敵の残り
        b[i] -= left;//味方の残り
        ll right = min(a[i + 1],b[i]);//右に全力
        ans += right;
        a[i + 1] -= right;//次の味方がやるまでの残り
        b[i] -= right;//最後の一人以外は0になってるはず最後は場合による
    }
    cout << ans << endl;
    return 0;
}
