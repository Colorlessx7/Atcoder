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
    int n, x;
    cin >> n >> x;
    x *= 100;
    vector<int> vp;
    vp.push_back(0);
    int sum = 0;
    rep(i,n){
        int v, p;
        cin >> v >> p;
        sum += v * p;
        vp.push_back(sum);
    }
    int ans = -1;
    rep(i,n+1){
        if(x < vp[i]){
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
