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
    rep(i,n){
        rep(j,i){
            len += dist(i,j);
        }
    }
    double ans = 2 * len / n;
    printf("%.10f\n", ans);
    return 0;
}
