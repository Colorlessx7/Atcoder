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
    auto dist = [&](int i, int j){
        double dx = x[i] - x[j];
        double dy = y[i] - y[j];
        return sqrt(dx * dx + dy * dy);
    };
    double len = 0;
    //全ての頂点間の辺の長さの合計を求める
    rep(i,n){
        rep(j,i){
            len += dist(i,j);
        }
    }
    //平均=ΣX*2(n-1)!/n!の(n-1)!/n!部分を約分すると1/nになる
    //それを計算したものがans
    double ans = 2 * len / n;
    printf("%.10f\n", ans);
    return 0;
}
//式変形によって順列全探索を改善してO(N^2)にしたもの(145C3)をさらに
//式変形したパターン
