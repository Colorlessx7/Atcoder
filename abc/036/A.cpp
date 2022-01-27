#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    int i = 0;
    while(a * i < b){
        i++;
    }
    cout << i << endl;
    return 0;
}
