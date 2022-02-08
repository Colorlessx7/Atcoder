#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    ll a, b, c;
    cin >> a >> b >> c;
    if(c % 2 == 0){
        a = abs(a);
        b = abs(b);
    }
    if(a > b){
        cout << '>' << endl; 
    }
    if(a == b){
        cout << '=' << endl;
    }
    if(a < b){
        cout << '<' << endl;
    }
    return 0;
}
