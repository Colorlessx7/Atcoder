#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int n;
    cin >> n;
    vector<int> x(n);
    rep(i,n){
        cin >> x[i];
    }
    double sum = 0;
    rep(i,n){
        sum += x[i];
    }
    sum /= n;
    int sum2 = sum;
    sum -= sum2;
    if(sum >= 0.5){
        sum2++;
    }
    int ans = 0;
    rep(i,n){
        ans += (x[i] - sum2) * (x[i] - sum2);
    }
    cout << ans << endl;
    return 0;
}
