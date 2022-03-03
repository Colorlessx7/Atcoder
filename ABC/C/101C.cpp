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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
    }
    int ans = (n-1 + k-1 -1) / (k-1);
    cout << ans << endl;
    return 0;
}
//数学的考察問題
//操作を繰り返し、全ての要素を網羅する必要がある
//操作回数の下限は、n要素を長さkの区間で被覆するための最小個数
//ただし操作は必ず1要素を被らせる必要があるため(n-1)/(k-1)の切り上げ
//が最小個数となる
