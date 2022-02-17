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
        if(mp[a] == 0){
            mp[a]++;
        }else {
            mp[a] = 0;
        }
    }
    int ans = 0;
    for(auto p : mp){
        if(p.second == 1){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
