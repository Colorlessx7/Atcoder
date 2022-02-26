#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep3(i,N) for(int i = n - 1; i >= 0; i--)
#define rep4(i,N) for(int i = n; i > 0; i--)
#define all(x) x.begin(),x.end() 
typedef long long ll;
using P = pair<int,int>;
int main(){
    vector<int> a(2);
    rep(i,2){
        cin >> a[i];
    }
    sort(a.rbegin(),a.rend());
    if(a[0] - a[1] == 1 || a[0] - a[1] == 9){
        cout << "Yes" << endl;
    }else {
        cout << "No" << endl;
    }
    return 0;
}
