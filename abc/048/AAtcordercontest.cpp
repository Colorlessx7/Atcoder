#include<bits/stdc++.h>
using namespace std;
int main(){
    string str1;
    string str2;
    string str3;
    cin >> str1 >> str2 >> str3;
    vector<char> c(3);
    c.at(0) = str1.at(0);
    c.at(1) = str2.at(0);
    c.at(2) = str3.at(0);
    for (int i = 0; i < 3; i++)
    {
        cout << c.at(i);
    }
    cout << endl;
    
}
