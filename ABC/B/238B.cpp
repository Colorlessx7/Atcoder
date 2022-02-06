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
    vector<int> cut;//累積和用配列 pizzaの切れ込みの角度
    cut.push_back(0);//累積和なので最初に0を挿入
    int sum = 0;
    rep(i,n){
        sum += a[i];//累積和のための合計の保持
        cut.push_back(sum % 360);//問題の都合360を超えると0からなのでmod処理
    }
    cut.push_back(360);//問題の都合上最後のpizzaの中心角を測るための最大値要素
    sort(cut.begin(),cut.end());//360で割る以上角度がぐちゃぐちゃになるのでsort
    int ans = 0;
    rep(i,n + 1){
        int now = cut[i + 1] - cut[i];//各pizzaの中心角
        ans = max(ans,now);//最大ならansに格納
    }
    cout << ans << endl;
    return 0;
}
