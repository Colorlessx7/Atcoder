#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int n;
    cin >> n;
    map<string,int> s;
    rep(i,n){
        string si;
        cin >> si;
        s[si]++;
    }
    int m;
    cin >> m;
    map<string,int> t;
    rep(i,m){
        string ti;
        cin >> ti;
        t[ti]++;
    }
    int ans = 0;
    for(auto p : s){
        int tmp = p.second - t[p.first];
        ans = max(ans,tmp);
    }
    cout << ans << endl;
    return 0;
}
