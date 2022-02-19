#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define repp(i,N) for(int i = 0; i <= N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep3(i,N) for(int i = n - 1; i >= 0; i--)
#define rep4(i,N) for(int i = n; i > 0; i--)
#define all(x) x.begin(),x.end() 
typedef long long ll;
int main(){
    int n, k;
    cin >> n >> k;
    vector<double> p(n);
    rep(i,n){
        double ps;
        cin >> ps;
        p[i] = (1 + ps) / 2;
    }
    vector<double> y;
    y.push_back(0);
    double sum = 0;
    rep(i,n){
        sum += p[i];
        y.push_back(sum);
    }
    double ans = 0;
    double cnt = 0;
    for(int i = k; i < n+1; i++){
        cnt = y[i] - y[i - k];
        ans = max(ans,cnt);
    }
    printf("%.10f\n",ans);
    return 0;
}
