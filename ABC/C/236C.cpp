#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int n, m;
    cin >> n >> m;
    vector<string> s(n),t(m);
    rep(i,n){
        cin >> s[i];//全駅入力
    }
    set<string> st;//急行駅をsetに格納
    rep(i,m){
        string t;
        cin >> t;
        st.insert(t);//急行駅をsetに格納
    }
    rep(i,n){
        if(st.count(s[i])){//急行駅がsetに存在するならyesしないならno
            cout << "Yes" << endl;
        }else {
            cout << "No" << endl;
        }
    }
    return 0;
}
