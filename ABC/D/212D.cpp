#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep3(i,N) for(int i = N - 1; i >= 0; i--)
#define rep4(i,N) for(int i = N; i > 0; i--)
#define all(x) x.begin(),x.end() 
typedef long long ll;
using P = pair<int,int>;
int main(){
    int n;
    cin >> n;
    ll x;
    ll sum = 0;
    priority_queue<ll,vector<ll>,greater<ll>> q; 
    rep(i,n){
        int t;
        cin >> t;
        if(t == 1){
            cin >> x;
            x -= sum;
            q.push(x);
        }
        if(t == 2){
            cin >> x;
            sum += x;
        }
        if(t == 3){
            ll ans = q.top() + sum;
            q.pop();
            cout << ans << endl;
        }
    }
    return 0;
}
