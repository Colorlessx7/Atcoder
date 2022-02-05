#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    ll n;
    cin >> n;
    string b;
    while(n > 0){
        if(n % 2 == 0){
            b += '0';
        }else {
            b += '2';
        }
        n /= 2;
    }
    reverse(b.begin(),b.end());
    cout << b << endl;
    return 0;
}
