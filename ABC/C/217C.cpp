#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 1; i <= N; i++)
#define rep2(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int n;
    cin >> n;
    vector<int> q(n);
    rep(i,n){
        int p;
        cin >> p;
        --p;
        q[p] = i;
    }
    rep2(i,n){
        cout << q[i] << " ";
    }
    cout << endl;
    return 0;
}
