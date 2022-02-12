#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int n;
    cin >> n;
    vector<bool> p(200001);
    int ans = 0;
    rep(i,n){
        int x;
        cin >> x;
        p[x] = 1;
        if(p[ans] == 1){
            for(int j = ans; j <= 200000; j++){
                if(p[j] == 0){
                    ans = j;
                    break;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
