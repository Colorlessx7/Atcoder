#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 0; i <= N; i++)
typedef long long ll;
int main(){
    int n;
    cin >> n;
    vector<int> p(n + 1);
    rep(i,n){
        cin >> p[i];
    }
    int low = min(INT_MAX,p[0]);
    int ans = 0;
    rep(i,n){
        if(p[i] <= low){
            ans++;
            low = min(low,p[i]);
        }
    }
    cout << ans << endl;
    return 0;
}
