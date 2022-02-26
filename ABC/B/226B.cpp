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
    int n;
    cin >> n;
    set<vector<int>> st; 
    rep(i,n){
        int l;
        cin >> l;
        vector<int> a(l);
        rep(j,l){
            cin >> a[j]; 
        }
        st.insert(a);
    }
    cout << st.size() << endl;
    return 0;
}
