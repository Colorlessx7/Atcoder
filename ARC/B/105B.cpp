#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int n;
    cin >> n;
    int g;
    cin >> g;
    rep(i,n - 1){
        int x;
        cin >> x;
        g = gcd(g,x);
    }
    cout << g << endl;
    return 0;
}
