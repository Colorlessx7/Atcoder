#include<bits/stdc++.h>
using namespace std;

int main(){
    int m;
    cin >> m;
    int ans;
    if(m < 100){
        cout << "00" << endl;
    }else if(m >= 100 && m <= 5000){
        ans = m * 10 /1000;
        printf("%02d\n",ans);
    }else if(m >= 6000 && m <= 30000){
        ans = m / 1000 +50;
        printf("%2d\n",ans);
    }else if(m >= 35000 && m <= 70000){
        ans = (m / 1000 - 30) / 5 + 80;
        printf("%2d\n",ans);
    } else if(m > 70000){
        cout << "89" << endl;
    }
    return 0;
}
