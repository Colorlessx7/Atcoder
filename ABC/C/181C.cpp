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
    rep(i,n){
        rep(j,i){
            rep(k,j){
                int a = x[j] - x[i];
                int b = y[j] - y[i];
                int c = x[k] - x[i];
                int d = y[k] - y[i];
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
