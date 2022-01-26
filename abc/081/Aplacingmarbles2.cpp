#include<bits/stdc++.h>
using namespace std;
int main(){
    int count = 0;
    int N = 3;
    string test;
        cin >> test;
    for (int i = 0; i < N; i++)
    {
        if (test.at(i) == '1'){
            count++;
        }
    }
    cout << count << endl;
}
