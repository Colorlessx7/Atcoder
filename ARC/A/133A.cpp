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
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
    }
    int x = a[0];
    rep(i,n){
        if(x > a[i]){
            break;
        }
        x = a[i];
    }
    rep(i,n){
        if(x == a[i]){
            continue;
        }
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
