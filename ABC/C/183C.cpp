#include<bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){//n=4の場合
    int n, k;
    cin >> n >> k;
    vector<vector<int>> t(n, vector<int>(n));
    vector<int> p;//順列生成用の配列
    rep(i,n){
        rep(j,n){
            cin >> t[i][j];//4*4
        }
    }
    for(int i = 1; i < n; i++){//順列生成のための要素出し
        p.push_back(i);//1,2,3
    }
    int ans = 0;
    do{
        int tot = t[0][p[0]];//T1,2
        rep(i,n - 2){
            tot += t[p[i]][p[i + 1]];//T2,3 T3,4      
        }
        tot += t[p.back()][0];//T4,1
        if(tot == k){
            ans++;
        }
    }while(next_permutation(p.begin(),p.end()));//順列生成
    cout << ans << endl;
    return 0;
}
//都市番号は0,1,2,,,,N-1 
