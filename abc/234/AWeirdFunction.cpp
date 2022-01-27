#include<bits/stdc++.h>
using namespace std;
int calc(int x){
    x = x * x + 2 * x + 3;
    return x; 
}
int main(){
    int N;
    cin >> N;
    int a1 = calc(N);
    int a3 = calc(a1 + N);
    int a4 = calc(a1);
    int ans = calc(a3 + a4);
    cout << ans << endl;    
    return 0;
}
