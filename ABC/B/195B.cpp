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
int main(){
    int a, b, w;
    cin >> a >> b >> w;
    //m:個数の最小値,M:個数の最大値
    int m = 1001001001, M = 0;
    //みかんが最小重さ1g,目標総量1000kgなので
    //ループ回数は1000000(g)となる
    rep2(n,1000000){
        //AN≤1000W≤BNが成り立つならちょうど買える
        if(a*n <= 1000*w && 1000*w <= b*n){
            //最小値,最大値の更新
            m = min(m,n);
            M = max(M,n);
        }
        //計算量削減 
        //この条件以降前の条件が成りたつnは存在しない
        if(a*n > 1000*w){
            break;
        }
    }
    //最大値が更新されていなかったらちょうど買えない事になる
    if(M == 0){
        cout << "UNSATISFIABLE" << endl;
    }else{
        cout << m << ' ' << M << endl;
    } 
    return 0;
}
//1個がAグラム以上Bグラム以下のみかんをちょうど
//N個選んでWキログラムにすることはできるか？という問題
