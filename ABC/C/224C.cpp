#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int n;
    cin >> n;
    vector<ll> x(n),y(n);
    rep(i,n){
        cin >> x[i] >> y[i];
    }
    ll f = 0;
    //相違なる3点が同一直線上にあればfを+1
    //rep(i,n)rep(j,i)rep(k,j)がダブる組み合わせを無視できる3重ループ方法
    rep(i,n){
        rep(j,i){
            rep(k,j){
                int a = x[j] - x[i];
                int b = y[j] - y[i];
                int c = x[k] - x[i];
                int d = y[k] - y[i];
                //0除算回避で移項している
                //本来はb/aとd/cを比較してイコールなら同一直線上にある
                if(a * d == c * b){
                    f++;
                }
            }
        }
    }
    ll ans = 1;
    //nC3の分子部分計算
    for(int i = n; i > n - 3; i--){
        ans *= i;
    }
    //nC3の分母部分計算
    for(int i = 1; i <= 3; i++){
        ans /= i;
    }
    //nC3から3点が同一直線上にある組み合わせを引いたものが答え
    ans -= f;
    cout << ans << endl;
    return 0;
}

