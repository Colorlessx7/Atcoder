#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int n;
    cin >> n;
    vector<int> a(n - 1);
    rep(i,n - 1){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    int sub = 1;
    vector<int> ans(n,0);
    rep(i,n - 1){
        if(a[i] == sub){
            ans[sub - 1]++;
        }else {
            sub = a[i];
            ans[sub - 1]++;
        }
    }
    rep(i,n){
        cout << ans[i] << endl;
    }
    return 0;
}
