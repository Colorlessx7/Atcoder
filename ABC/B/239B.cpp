#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep3(i,N) for(int i = n - 1; i >= 0; i--)
#define rep4(i,N) for(int i = n; i > 0; i--)
#define all(x) x.begin(),x.end() 
typedef long long ll;
using P = pair<int,int>;
int main(){
    ll x;
    cin >> x;
    if(x == 0){
        cout << 0 << endl;
        return 0;
    }
    int cnt = 0;
    int nx = x;
    while(nx != 0){
        cnt++;
        nx /= 10;
    }
    if(cnt == 1 && x > 0){
        cout << 0 << endl;
        return 0;
    }
    bool c = 0;
    if(x % 10 == 0){
        c = 1;
    }
    x /= 10;
    if(x <= 0 && c == 0){
        x -= 1;
    }
    cout << x << endl;
    return 0;
}
