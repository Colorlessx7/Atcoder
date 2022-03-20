#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep3(i,N) for(int i = N - 1; i >= 0; i--)
#define rep4(i,N) for(int i = N; i > 0; i--)
#define replr(i,l,r) for(int i = l; i < r; i++)
#define reprl(i,l,r) for(int i = l; i > r; i--)
#define all(x) x.begin(),x.end() 
#define allr(x) x.rbegin(),x.rend() 
typedef long long ll;
using P = pair<int,int>;
int main(){
    ll a, b, x, y;
    cin >> a >> b >> x >> y;
    ll diff = a - b;
    ll ch = abs(diff);
    ll xch = 0;
    ll ych = 0;
    xch = 2 * x * ch;
    ych = y * ch;
    if(diff > 0){
        xch -= x;
        if(x <= y){
            ych -= y;
        }
        ych += x;
    }else {
        xch += x;
        ych += x;
    }
    if(xch >= ych){
        cout << ych << endl;
    }else {
        cout << xch << endl;
    }
    return 0;
}
