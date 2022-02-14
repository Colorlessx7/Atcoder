#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
using mint = modint998244353;
const int mod = 998244353;
int main(){
    ll x;
    cin >> x;
    unordered_map<ll,ll> memo;
    auto f = [&](auto self, ll x) -> ll{
        if(memo.count(x)){
            return memo[x];
        }
        auto& res = memo[x];
        if(x <= 4){
            return (res = x);
        }
        ll x1 = x / 2;
        ll x2 = (x + 1) / 2;
        return (res = self(self,x1) * self(self,x2) % mod);
    }; 
    cout << f(f,x) << endl;
    return 0;
}
