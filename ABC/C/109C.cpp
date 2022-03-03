#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep3(i,N) for(int i = N - 1; i >= 0; i--)
#define rep4(i,N) for(int i = N; i > 0; i--)
#define all(x) x.begin(),x.end() 
typedef long long ll;
using P = pair<int,int>;
int main(){
    int n, x;
    cin >> n >> x;
    vector<int> y(n);
    rep(i,n){
        cin >> y[i];
    }
    y.push_back(x);
    sort(all(y));
    vector<int> d;
    for(int i = 1; i <= n; i++){
        int f = y[i] - y[i-1];
        d.push_back(f);
    }
    int m = d[0];
    rep(i,n){
        m = gcd(m,d[i]);
    }
    cout << m << endl;
    return 0;
}
//数学的考察 gcd
