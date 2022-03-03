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
    vector<int> x(n);
    rep(i,n){
        cin >> x[i];
    }
    vector<int> y = x;
    sort(all(y));
    int hi = y[n/2];
    int low = y[n/2-1];
    rep(i,n){
        if(x[i] <= low){
            cout << hi << endl;
        }else {
            cout << low << endl;
        }
    }
    return 0;
}
