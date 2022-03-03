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
    int n, m;
    cin >> n >> m;
    vector<int> x(m);
    rep(i,m){
        cin >> x[i];
    }
    sort(all(x));
    vector<int> d;
    for(int i = 1; i < m; i++){
        int f = x[i] - x[i-1];
        d.push_back(f);
    }
    sort(all(d));
    n--;
    rep(i,n){
        d.pop_back();
    }
    n = d.size();
    ll ans = 0;
    rep(i,n){
        ans += d[i];
    }
    cout << ans << endl;
    return 0;
}
//数学的考察 
