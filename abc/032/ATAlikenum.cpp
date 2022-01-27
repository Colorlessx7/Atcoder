#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, n;
    cin >> a >> b >> n;
    int lcm = a / gcd(a,b) * b;
    int y = lcm * ((n + lcm - 1) / lcm);
    cout << y << endl;
    return 0;
}
