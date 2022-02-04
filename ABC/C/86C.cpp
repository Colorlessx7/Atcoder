#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
int main(){
    int n;
    cin >> n;
    vector<int> t(n + 1,0),x(n + 1,0),y(n + 1,0);
    for(int i = 1; i <= n; i++){
        cin >> t[i] >> x[i] >> y[i];
    }
    int sum;
    for(int i = 0; i < n; i++){
        int dx = abs(x[i+1]-x[i]);
        int dy = abs(y[i+1]-y[i]);
        int dt = t[i+1]-t[i];
        sum = dx + dy;
        if(sum > dt){
            cout << "No" << endl;
            return 0;
        }else if((dt-sum) % 2 != 0){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
/*20行(dt-sum) % 2 != 0で判定もRE*/
/*dt % 2 != sum % 2に治すもRE*/
/*t,x,nの配列の格納範囲が一個少なく修正後AC*/
