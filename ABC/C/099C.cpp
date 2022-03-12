#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep3(i,N) for(int i = N - 1; i >= 0; i--)
#define rep4(i,N) for(int i = N; i > 0; i--)
#define replr(i,l,r) for(int i = l; i < r; i++)
#define all(x) x.begin(),x.end() 
typedef long long ll;
using P = pair<int,int>;
int main(){
    int n;
    cin >> n;
    //nの制約より少し多めにDP配列のサイズをとる
    vector<int> dp(100010);
    //1円玉だけで取り出した場合の必要回数で初期化
    rep(i,n+1){
        dp[i] = i;
    }
    //DP処理部分
    rep2(i,100000){
        //冪乗を管理するための変数
        int power = 6;
        while(power <= i){
            dp[i] = min(dp[i],dp[i-power]+1);
            power *= 6;
        }
        power = 9;
        while(power <= i){
            dp[i] = min(dp[i],dp[i-power]+1);
            power *= 9;
        }
    }
    cout << dp[n] << endl;
    return 0;
}
//DPで解く問題
//お金の取り出し方は1,6,6^2,6^3,6^4,6^5,6^6,9,9^2,9^3,9^4,9^5の12通り
//dp[i]をi円取り出すための最小回数とすると
//1^1円取り出す場合に 1+dp[i-1^1] 6^1円取り出す場合に 1+dp[i-6^1]
//9^1円取り出す場合に 1+dp[i-9^1] 6^2円取り出す場合に 1+dp[i-6^2]
//9^2円取り出す場合に 1+dp[i-9^2] 6^3円取り出す場合に 1+dp[i-6^3]
//9^3円取り出す場合に 1+dp[i-9^3] 6^4円取り出す場合に 1+dp[i-6^4]
//9^4円取り出す場合に 1+dp[i-9^4] 6^5円取り出す場合に 1+dp[i-6^5]
//9^5円取り出す場合に 1+dp[i-9^5] 6^6円取り出す場合に 1+dp[i-6^6]
//となり、これの最小値が取り出し方の最小回数となる
//これを1~nまで順に計算しminをとり、更新していく
//ただしiよりも6又は9の冪乗の値が小さい場合は物理的に不可能でかつ
//dpも配列外参照を起こすため考慮しないというのをwhileで実装している
