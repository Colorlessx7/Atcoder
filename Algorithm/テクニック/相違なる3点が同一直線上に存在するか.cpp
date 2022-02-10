/* 証明がわかりやすいように1つの点が原点になるように3点を平行移動しておく。
3点A(0,0),B(x1,y1),C(x2,y2)が同一直線上にあるかは、ABとACの傾きが等しいかで判定できる
y1/x1=y2/x2であれば相違なる3点が同一直線上に存在するか判定できるがこの場合0除算が発生する為
両辺にx1,x2をかけてx2y1=x1y2が成り立つか判定すれば良い
*/

//ABC181Cより

#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int n;
    cin >> n;
    vector<double> x(n),y(n);
    rep(i,n){
        cin >> x[i] >> y[i];
    }
    //rep(i,n)rep(j,i)rep(k,j)がダブる組み合わせを無視できる3重ループ方法
    rep(i,n){
        rep(j,i){
            rep(k,j){
                //a:x1,b:y1,c:x2,d:y2
                int a = x[j] - x[i];
                int b = y[j] - y[i];
                int c = x[k] - x[i];
                int d = y[k] - y[i];
                //0除算回避で移項している
                //本来はb/aとd/cを比較してイコールなら同一直線上にある
                if(a * d == c * b){
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}

//応用例 ABC224Cより

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
                //a:x1,b:y1,c:x2,d:y2
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

