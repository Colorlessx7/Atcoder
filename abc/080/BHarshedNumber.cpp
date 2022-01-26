#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    string str;
    str = to_string(N);
    int n;
    n = str.size();
    vector<int> y(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        y.at(i) = str.at(i) - '0';
    }
    for (int i = 0; i < n; i++)
    {
        sum += y.at(i);
    }
    if (N % sum == 0){
        cout << "Yes" << endl;
    }else {
        cout << "No" << endl;
    }
    
    
}
