#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int d, n;
    cin >> d >> n;
    if(n == 100){
        n++;
    }
    string ans = to_string(n);
    rep(i,d){
        ans += "00";
    }
    cout << ans << endl;
    return 0;
}
