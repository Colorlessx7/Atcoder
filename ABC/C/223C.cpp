#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    double n;
    cin >> n;
    vector<double> a(n),b(n);
    rep(i,n){
        cin >> a[i] >> b[i];
    }
    double sum1 = 0;
    vector<double> sp;
    sp.push_back(0);
    rep(i,n){
        sum1 += a[i] / b[i];
        sp.push_back(sum1);
    }
    sum1 /= 2;
    double ans = 0;
    rep(i,n+1){
        if(sum1 <= sp[i]){
            ans += (sum1 - sp[i - 1]) * b[i - 1];
            break;
        }
        if(i != 0){
            ans += a[i - 1];
        }
        
    }
    printf("%.10f\n",ans);
    return 0;
}
