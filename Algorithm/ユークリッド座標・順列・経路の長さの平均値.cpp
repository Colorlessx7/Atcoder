#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    rep(i,n){
        cin >> x[i] >> y[i];
    }
    auto dist = [&](int i, int j){//ラムダ式　main関数の中で関数を指定している　1つずつユークリッド距離を求める関数
        double dx = x[i] - x[j];
        double dy = y[i] - y[j];
        return sqrt(dx * dx + dy * dy);
    };
    double len = 0;
    rep(i,n){//(i,j)が(1,0)(2,0)(2,1)となりこれにより各ユークリッド距離の合計がもとまる
        rep(j,i){
            len += dist(i,j);//12行目へ
        }
    }
    double ans = 2 * len / n;//全経路の平均は2*各辺の長さの合計をユークリッド座標の数で割ったもの
    printf("%.10f\n", ans);
    return 0;
}
