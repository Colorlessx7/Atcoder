#include<bits/stdc++.h>
using namespace std;

int main(){
    long long x,y;
    cin >> x >> y;
    int ans = 1;
    while(x*2 <= y){
        x *= 2;
        ans++;
    }
    cout << ans << endl;
    return 0;
}
