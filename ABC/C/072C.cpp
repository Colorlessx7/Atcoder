#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int n;
    cin >> n;
    map<int,int> mp;
    rep(i,n){
        int a;
        cin >> a;
        mp[a]++;
        a--;
        mp[a]++;
        a += 2;
        mp[a]++;
    }
    int ans = 0;
    for(auto p : mp){
        ans = max(p.second,ans);
    }
    cout << ans << endl;
    return 0;
}
