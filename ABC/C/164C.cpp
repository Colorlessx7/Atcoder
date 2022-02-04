#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i,n){
        cin >> s[i];
    }
    set<string> Set;
    rep(i,n){
        Set.insert(s[i]);
    }
    cout << Set.size() << endl;
    return 0;
}
