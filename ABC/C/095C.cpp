#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    long long ans = 0;
    long long ans1 = 0;
    long long ans2 = 0;
    if((a + b) <= c * 2){
        ans = a * x + b * y; 
    }else if(x >= y){
        ans = min(x,y) * c * 2;
        ans1 = max(x,y) * c * 2 - ans; 
        ans2 = (x - y) * a;
        if(ans1 >= ans2){
            ans += ans2;
        }else {
            ans += ans1;
        }        
    }else {
        ans = min(x,y) * c * 2;
        ans1 = max(x,y) * c * 2 - ans;
        ans2 = (y - x) * b;
        if(ans1 >= ans2){
            ans += ans2;
        }else {
            ans += ans1;
        }   
    }
    cout << ans << endl;
    return 0;
}
