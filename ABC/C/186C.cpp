#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        bool ok = true;
        for(int base : {8,10}){//range baseのfor
            int x = i;
            while(x > 0){
                if(x % base == 7){//あまり一桁が7か
                   ok = false;
                }
                x /= base;//一桁削る
            }
        }
        if(ok){
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}

