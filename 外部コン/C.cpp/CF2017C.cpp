#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int n;
    cin >> n;
    int a1 = 1;
    rep(i,n){
        a1 *= 3;
    }
    int a2 = 1;
    rep(i,n){
        int a;
        cin >> a;
        if(a % 2 == 0){
            a2 *= 2;
        }
    }
    int ans = a1 - a2;
    cout << ans << endl;
    return 0;
}
