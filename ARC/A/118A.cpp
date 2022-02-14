#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    ll t, n;
    cin >> t >> n;
    ll price = (100 * n - 1) / t;  // 本体価格
    ll tax = n;                    // 税
    cout << price + tax << endl;
    return 0;
}
