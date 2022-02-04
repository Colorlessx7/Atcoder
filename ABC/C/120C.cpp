#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
int main(){
    string s;
    cin >> s;
    int cnt0 = 0, cnt1 = 0; 
    rep(i,s.size()){
        if(s.at(i) == '0'){
            cnt0++;
        }else if(s.at(i) == '1'){
            cnt1++;
        }
    }
    cout << s.size() - abs(cnt1 - cnt0) << endl;
    return 0;
}
