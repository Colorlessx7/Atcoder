#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int n, a, b;
    cin >> n >> a >> b;
    int ans = 0;
    rep(i,n){
        string s;
        int d;
        cin >> s >> d;
        if(d < a){
            d = a;
        }else if(d > b){
            d = b;
        }
        if(s == "West"){
            d *= -1;
        }
        ans += d;
    }
    if(ans > 0){
        cout << "East" << " " << ans << endl;
    }else if(ans == 0){
        cout << 0 << endl;
    }else {
        ans *= -1;
        cout << "West" << " " << ans << endl;
    }
    return 0;
}
