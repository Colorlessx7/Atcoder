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
    int n;
    cin >> n;
    ll ans = 0;
    rep(i,n){
        ll a;
        cin >> a;
        if(i == 0){
            ans = a;
            continue;
        }
        ans = a / gcd(a,ans) * ans;
    }
    cout << ans << endl;
    return 0;
}
