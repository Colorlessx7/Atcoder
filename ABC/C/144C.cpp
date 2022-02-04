#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    ll n;
    cin >> n;
    ll ans = LLONG_MAX;//最大値をおいておく
    for(ll i = 1; i * i <= n; ++i){//jはiに依存しているため1重ループで回せる sqrt(n)がi以下の範囲でループ
        if(n % i != 0){
            continue;//割り切れない処理
        }
        ll j = n / i;//最初に割り切れた時の処理
        ans = min(ans,i + j - 2);//
    }
    cout << ans << endl;
    return 0;
}
