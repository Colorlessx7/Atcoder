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
    int n, m;
    cin >> n >> m;
    ll odd = 0, even = 0;
    rep(i,n){
        string s;
        cin >> s;
        int cnt = 0;
        rep(j,m){
            if(s[j] == '1'){
                cnt++;
            }
        }
        if(cnt % 2 == 0){
            even++;
        }else {
            odd++;
        }
    }
    cout << even * odd << endl;
    return 0;
}
//adhocな考察解
//
