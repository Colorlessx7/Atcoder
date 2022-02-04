#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i,n){
        cin >> h[i];
    }
    int cnt = 1;
    rep(i,n){
        if(h[i] != cnt){
            if(h[i] - cnt > 0){
                if(h[i] - cnt > 1){
                    cnt = h[i] - 1;
                }
            }else {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}
