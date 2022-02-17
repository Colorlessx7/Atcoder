#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int n;
    cin >> n;
    //正解配列 添字が計算結果に対応
    vector<int> ans(n + 1);
    for(int x = 1; x <= 100; x++){
        for(int y = 1; y <= 100; y++){
            for(int z = 1; z <= 100; z++){
                int s = x*x + y*y + z*z;
                s += x*y + y*z + z*x;
                //計算結果が制約外ならスルー
                if(s > n){
                    continue;
                }
                //計算結果に対応した場所に出現回数を+1
                ans[s]++;
            }   
        }
    }
    for(int i = 1; i <= n; i++){
        cout << ans[i] << endl;
    }
    return 0;
}
//全探索問題
//f(n)を以下の2つの条件の両方を満たすような3つの整数の組(x,y,z)の個数とする
//1≤x,y,z
//x^2+y^2+z^2+xy+yz+zx=n
//整数 N が与えられるので、f(1),f(2),f(3),…,f(N) をそれぞれ求める
//制約 1≤N≤10^4
//2乗の項に着目 xが100より大きいとその項だけでnの制約を超える
//だからx,y,zそれぞれ1~100までの3重ループで全探索しても間に合う
