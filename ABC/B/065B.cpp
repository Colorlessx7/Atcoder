#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
        a[i]--;
    }
    vector<bool> c(n);
    int cnt = 1;
    int x = 0;
    while(a[x] != 1){
        cnt++;
        if(!c[x]){
            c[x] = 1;
            x = a[x];
        }else {
            cnt = -1;
            break;
        }
    }
    cout << cnt << endl;
    return 0;
}
