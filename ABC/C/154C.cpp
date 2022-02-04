#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
    }
    set<int> Set;
    rep(i,n){
        Set.insert(a[i]);
    }
    if(a.size() == Set.size()){
        cout << "YES" << endl;
    }else {
        cout << "NO" << endl;
    }
    return 0;
}
