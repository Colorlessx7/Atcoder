#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
int main(){
    int count = 0;
    int N = 3;
    string test;
    cin >> test;
    rep(i,N)
    {
        if (test.at(i) == '1'){
            count++;
        }
    }
    cout << count << endl;
}
