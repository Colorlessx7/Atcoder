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
    ll n;
    cin >> n;
    ll x = n + 1;
    int ch = 1;
    ll cnt = 0;
    while(x){
        if(x >= ch){
            cnt++;
            x -= ch;
            ch++;
        }else {
            break;
        }
    }
    ll ans = n;
    ans -= cnt;
    ans++;
    cout << ans << endl;
    return 0;
}
