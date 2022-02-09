#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    ll n;
    cin >> n;
    string ans;
    bitset<60> a(n);
    int x = a.count();
    while(x > 0){
        if(a[0] == 1){
            ans += "A";
            a.reset(0);
        }
        a = a >> 1;
        ans += "B";
        x = a.count();
    }
    ans.pop_back();
    reverse(ans.begin(),ans.end());
    cout << ans << endl;
    return 0;
}
