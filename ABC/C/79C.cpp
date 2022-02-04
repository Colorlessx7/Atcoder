#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
int main(){
    int x;
    cin >> x;
    vector<int> keta(4);
    rep(i,4){
        keta[i] = x % 10;
        x /= 10; 
    }
    string s;
    reverse(keta.begin(),keta.end());
    int sum;
    for(int x = 0; x < 8; x++){
        sum = keta[0];
        s = char('0' + keta[0]);
        for(int i = 0; i < 3; i++){
            if(x & (1<<i)){
                sum += keta[i+1];
                s += '+';
                s += char(keta[i+1] + '0');
            }else {
                sum -= keta[i+1];
                s += '-';
                s += char(keta[i+1] + '0');
            }
        }
        if(sum == 7){
            break;
        }
    }
    if(sum == 7){
        cout << s << "=7" << endl;
    }
    return 0;
}
