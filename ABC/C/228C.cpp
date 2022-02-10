#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int n,k;
    cin >> n >> k;
    vector<vector<int>> p(n,vector<int>(3));
    rep(i,n){
        rep(j,3){
            cin >> p[i][j];
        }
    }
    vector<int> sum(n);
    vector<int> sums(n);
    rep(i,n){
        rep(j,3){
            sum[i] += p[i][j];
        }
    }
    copy(sum.begin(),sum.end(),sums.begin());
    sort(sums.rbegin(),sums.rend());
    int c = sums[k - 1];
    vector<bool> ans(n);
    rep(i,n){
        if(c <= sum[i] + 300){
            ans[i] = 1;
        }
    }
    rep(i,n){
        if(ans[i] == 1){
            cout << "Yes" << endl;
        }else {
            cout << "No" << endl;
        }
    }
    return 0;
}
