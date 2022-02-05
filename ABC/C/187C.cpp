#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    set<string> st;
    rep(i,n){
        cin >> s[i];
        st.insert(s[i]);
    }
    rep(i,n){
        string t = "!";
        t += s[i];
        if(st.count(t)){
            cout << s[i] << endl;
            return 0;
        }
    }
    cout << "satisfiable" << endl;
    return 0;
}
