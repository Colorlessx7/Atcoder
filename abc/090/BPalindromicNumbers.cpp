#include<bits/stdc++.h>
using namespace std;
int main(){
    string A, B;
    cin >> A >> B;
    string A2 = "00";
    string B2 = "00";
    for (int i = 0; i < 2; i++)
    {
        A2.at(i) = A.at(i);
    }
    for (int i = 0; i < 2; i++)
    {
        B2.at(i) = B.at(i);
    }
    int x = stoi(B2) - stoi(A2);
    char A3, B3;
    A3 = A.at(2);
    B3 = B.at(2);
    int y = (B3 - '0') - (A3 - '0');
    reverse(A2.begin(), A2.end());
    reverse(B2.begin(), B2.end());
    string AA = A;
    string BB = B;
    for (int i = 0; i < 2; i++)
    {
        AA.at(i + 3) = A2.at(i);
    }
    for (int i = 0; i < 2; i++)
    {
        BB.at(i + 3) = B2.at(i);
    }
    if(stoi(AA) >= stoi(A)){
        y++;
    }
    if (stoi(BB) > stoi(B)){    
        y--;
    }
    cout << x * 10 + y << endl;
}
