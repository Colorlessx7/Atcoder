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
    ll n;
    cin >> n;
    vector<ll> a(n+2);
    a[0] = 0; a[n+1] = 0;
    rep2(i,n){
        cin >> a[i];
    }
    ll ans = 0;
    for(int i=1; i<n+2; i++){
        ans += abs(a[i] - a[i-1]);
    }
    rep2(i,n){
        if((a[i-1]>=a[i]&&a[i]>=a[i+1])||(a[i-1]<=a[i]&&a[i]<=a[i+1])){
            cout << ans << endl;
        }else {
            int x = abs(a[i] - a[i-1]) + abs(a[i+1] - a[i]);
            x -= abs(a[i+1] - a[i-1]);
            cout << ans - x << endl;
        }
    }   
    return 0;
}
//数学的考察
//あらかじめ全体の値を求めて都度差分を引く問題
