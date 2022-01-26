#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
int main(){
    int a;
    cin >> a;
    bitset<4> bs1(a);
    int cnt = 0;
    rep(i,4){
        if(bs1.test(i) == 1){
            cnt++;
        } 
    }
    cout << cnt << endl;
    rep(i,4){
        if(bs1.test(i) == 1){
            cout << exp2(i) << endl;
        }
    }
    return 0;
}
