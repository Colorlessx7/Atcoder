#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    rep(i,n){
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a.begin(),a.end());
    rep(i,n){
        cout << a[i].second << endl;
    }

    return 0;
}
