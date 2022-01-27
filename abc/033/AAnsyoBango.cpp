#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
int main(){
    string s;
    cin >> s;
    bool check = 1;
    rep(i,s.size() - 1){
        if(s.at(i) != s.at(i + 1)){
            check = 0;
            break;
        }
    }
    if(check == 0){
        cout << "DIFFERENT" << endl;
    } else {
        cout << "SAME" << endl;
    }
    return 0;
}
