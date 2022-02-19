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
int main(){
    int n;
    cin >> n;
    vector<char> c(n);
    int cnt = 0;
    rep(i,n){
        cin >> c[i];
        if(c[i] == 'R'){
            cnt++;
        }
    }
    int ans = 0;
    rep(i,cnt){
        if(c[i] == 'W'){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
