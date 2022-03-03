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
    int n, ans;
    cin >> n >> ans;
    int k;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n - i; j++){
            if(n - i - j < 0){
                continue;
            }
            k = n - i - j;
            if(ans == 10000 * i + 5000 * j + 1000 * k){
                printf("%d %d %d\n",i,j,k);
                return 0;
            }
        }
    }
    printf("-1 -1 -1\n");
    return 0;
}
//普通にやると3重ループだが、変数が2つ定まると残りの1つは一意に定まる為、
//2重ループで全探索できる 変数が一意に定まる場合を忘れるのでよく覚える
//実装で手こずった部分
//k=n-i-jでkがマイナスの状態で計算されていた
//iとjだけでnを超えていてのに処理が続いていた
