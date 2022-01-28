#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
int main(){
    string x;
    cin >> x;
    vector<bool> check(x.size(),0);
    rep(i,x.size()){
        if(x.at(i) == 'a'||x.at(i) == 'i'||x.at(i) == 'u'||x.at(i) == 'e'||x.at(i) == 'o'){
            check.at(i) = 1;
        }
    }
    rep(i,x.size()){
        if(check.at(i) == 0){
            cout << x.at(i);
        }
    }
    cout << endl;
    return 0;
}
