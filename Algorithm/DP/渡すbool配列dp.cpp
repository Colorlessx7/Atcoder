//ABC240Cより それぞれ違う+aか+bをn回選び合計がxちょうどになるかどうか

#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep3(i,N) for(int i = n - 1; i >= 0; i--)
#define rep4(i,N) for(int i = n; i > 0; i--)
#define all(x) x.begin(),x.end() 
typedef long long ll;
using P = pair<int,int>;
int main(){
    int n, x;
    cin >> n >> x;
    vector<int> a(n),b(n);
    rep(i,n){
        cin >> a[i] >> b[i];
    }
    //DP用の配列 行はジャンプの回数0~nの分のn+1 列はジャンプの距離0~xの分のx+1
    //あらかじめ全てfalseにしておく 
    vector<vector<bool>> dp(n+1, vector<bool>(x+1, false));
    //0行目の設定
    //最初の要素(一回もジャンプせず0にいる状態)だけtrueにしておく
    dp[0][0] = true;
    //ジャンプ回数n分ループを回す このループでの計算結果をdpの次の行に格納
    //最終的にdp[n][0~x]に最後の結果が格納される
    for(int i = 0; i < n; ++i){
        //ジャンプ距離の総数0~指定された最終距離xまでループを回す
        for(int j = 0; j <= x; ++j){
            //それまでのジャンプで辿り着ける場所だったらtrueなので
            //その位置から次のジャンプで辿り着く場所(x以下)を次の行に記録
            if(dp[i][j]){
                //i回ジャンプを行った後の地点からaの距離ジャンプして
                //それがx以下ならdp[i+1][j+a]をtrueに
                if(j + a[i] <= x){
                    dp[i+1][j+a[i]] = true;
                }
                //bの距離をジャンプした場合も検証
                if(j + b[i] <= x){
                    dp[i+1][j+b[i]] = true;
                }
            }
        }
    }
    //dp[n][x]がtrueならxにちょうどジャンプできるのでYes
    //falseならちょうどジャンプできないのでNo
    cout << (dp[n][x] ? "Yes" : "No") << endl;
    return 0;
}
//DP:動的計画法問題
//愚直解としてbit全探索しようとすると2^100なのでtleする
//・複数のジャンプの仕方で同じ座標に到着する場合、それらは同一視して良い
//・途中で座標がxを超えるようなジャンプの仕方は無視して良い
//以上から次のような動的計画法を考える
//・dp[i][j]:i回ジャンプした時点で座標jの位置にいることが
//可能なら1、不可能なら0 で、0<=i<=n,0<=j<=xなので状態数はO(nx)となる
//例としてn=2,x=10 a1=3,b1=6,a2=4,b2=5の場合
//  012345678910 (11) j
//0 TFFFFFFFFF F
//1 FFFTFFTFFF F
//2 FFFFFFFTTF T (T) 
//i
//でdp[n][x]はdp[2][10]の位置でありTrueなのでYesを出力する感じになる
