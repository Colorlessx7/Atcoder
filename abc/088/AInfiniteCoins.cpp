#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    int A;
    cin >> N >> A;
    while (N >= 500)
    {
        N -=500;
    }
    if (N <= A){
        cout << "Yes" << endl;
    }else {
        cout << "No" << endl;
    }
}
