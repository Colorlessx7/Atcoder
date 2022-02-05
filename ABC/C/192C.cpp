#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int n, k;
    cin >> n >> k;
    rep(i,k){
        string s = to_string(n);
        sort(s.begin(),s.end());
        int mn = stoi(s);
        reverse(s.begin(),s.end());
        int mx = stoi(s);
        n = mx - mn;
    }
    cout << n << endl;
    return 0;
}
