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
    map<int,int> mp;
    rep(i,n){
        int a;
        cin >> a;
        mp[a]++;
    }
    int ans = 0;
    for(auto p : mp){
        if(p.first <= p.second){
            ans += p.second - p.first;
        }else {
            ans += p.second;
        }
    }
    cout << ans << endl;
    return 0;
}
//mapで解く問題
