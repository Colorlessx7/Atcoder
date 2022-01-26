#include<bits/stdc++.h>
using namespace std;
int main(){
    string N;
    cin >> N;
    vector<char> c(4);
    bool b = 0;
    for (int i = 0; i < 4; i++)
    {
        c.at(i) = N.at(i);
    }
    for (int i = 0; i < 2; i++)
    {
        if (c.at(i) == c.at(i + 1)){
            if (c.at(i) == c.at(i + 2)){
                cout << "Yes" << endl;
                b = 1;
            }
            if (b == 1){
                break;
            }
        }
        if (i == 1){
            cout << "No" << endl;
        }
    }
    return 0; 
}
