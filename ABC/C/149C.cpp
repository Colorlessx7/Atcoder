#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int Primecheckup(int x){
    vector<bool> prime(100004,1);
    prime[0] = 0;
    prime[1] = 0;
    for(int i = 2; i * i < 100004; ++i){
        if(prime[i]){
            for(int j = 2; i * j < 100004; ++j){
                prime[i * j] = 0;
            }
        }
    }
    for(int i = x; i < 100004; i++){
        if(prime[i]){
            return i;
        }
    }
    return 0;
}
int main(){
    int x;
    cin >> x;
    int ans = Primecheckup(x);
    cout << ans << endl;
    return 0;
}
