#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b,c,d,e,f;
    cin >> a >> b>>c>>d>>e>>f;
    int y =0;
    y = a*e + b*f;
    if(e+f >= d){
        y -= c*(e+f);
    }
    cout << y << endl;
    return 0;
}
