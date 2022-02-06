//ABC238Bより

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

/*　累積和は配列処理の一つで元の配列のサイズ+1の配列を作る
元の配列が 3 7 14 44　だとすると
累積和配列は　0 3 10 24 68 となる
累積和は配列のある場所から別の場所までの合計を計算する速度がとてもはやい

方法は16 ~ 24行の処理で
まず累積和用の配列をサイズの指定を(push_backならせずに)配列に直接書き込むなら元の配列の+1という形で宣言する
配列の最初の要素を0にする
元の配列の要素をsumに追加
その時点のsumを配列の次の要素に格納(この時点で問題の条件に応じた処理をすることもある)
上2行の処理を元の配列のサイズの回数分行う
問題の条件により累積和配列の順番が狂ったらsortする*/
