#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep3(i,N) for(int i = N - 1; i >= 0; i--)
#define rep4(i,N) for(int i = N; i > 0; i--)
#define all(x) x.begin(),x.end() 
typedef long long ll;
using P = pair<int,int>;
int main(){
    int h, w;
    cin >> h >> w;
    vector<vector<char>> c(h, vector<char>(w));
    rep(i,h){
        rep(j,w){
            cin >> c[i][j];
        }
    }
    //dp用の配列,現在のマスを含めて最大後何マス動けるかという数字を格納
    //0初期化,壁のマスは0から変わらない
    vector<vector<int>> dp(h, vector<int>(w,0));
    //ゴールから考えるのでiをh-1~0の順にループを回す(jも同様)
    rep3(i,h){
        rep3(j,w){
            //壁の位置はスルー
            if(c[i][j] == '#'){
                continue;
            }
            //壁ではないので1から計算開始
            dp[i][j] = 1;
            //漸化式処理部分
            //下に行ける場合
            if(i+1 < h){
                dp[i][j] = max(dp[i][j],dp[i+1][j]+1);
            }
            //右に行ける場合
            if(j+1 < w){
                dp[i][j] = max(dp[i][j],dp[i][j+1]+1);
            }
        }
    }
    //スタート地点が答えになるのでそこを出力
    cout << dp[0][0] << endl;
    return 0;
}
//dpで解く問題
//.... 7321
//.#.# 6010
//..#. 5402
//#... 0321
//ゴールから考えて、現在のマスを含めて後何マス進めるかを
//それぞれのマスについて調べると上の右の図のようになる
//答えはスタート地点の数字のみなので
//ゴールから見た時の行き止まりは適当に処理させるだけで良い
//この時漸化式は
//壁の位置はdp[i][j]=0     (c[i][j]=='#)
//行き止まりはdp[i][j]=1
//途中の通路はdp[i][j]=max((dp[i+1][j]+1)&(i+1<h),(dp[i][j+1]+1)&(j+1<w))
//(dpの一つ右の値の+1(右に進める場合有効)とdpの一つ下の値+1(下に進める場合有効)の大きい方が答え)
