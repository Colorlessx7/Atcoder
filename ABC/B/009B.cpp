#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int n;
    cin >> n;
    set<int> st;
    rep(i,n){
        int x;
        cin >> x;
        st.insert(x);
    }
    auto y = st.begin();
    int f = st.size() - 2;
    rep(i,f){
        y++;
    }
    cout << (*y) << endl;
    return 0;
}
