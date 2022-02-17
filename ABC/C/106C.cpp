#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    string s;
    ll n;
    cin >> s >> n;
    if(s[0] == '1' && n != 1){
        rep(i,n){
            if(s[i] != '1'){
                cout << s[i] << endl;
                return 0;
            }
        }
        cout << s[0] << endl;
    }else {
        cout << s[0] << endl;
    }
    return 0;
}
