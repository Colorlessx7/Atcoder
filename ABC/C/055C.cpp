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
    ll n, m;
    cin >> n >> m;
    ll ans = 0;
    if(n * 2 > m){
        ans = m / 2;
    }else {
        ans += n;
        m -= 2 * n;
        m /= 4;
        ans += m;
    }
    cout << ans << endl;
    return 0;
}
