#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int n;
    cin >> s >> n;
    n--;
    cout << s.at(n/5) << s.at(n%5) << endl;
    return 0;
}
