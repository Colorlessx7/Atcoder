#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(4 * N - 1);
    for (int i = 0; i < 4 * N - 1; i++)
    {
        cin >> A.at(i);
    }
    int sum = 0;
    for (int i = 0; i < 4 * N - 1; i++)
    {
        sum += A.at(i);
    }
    int y;
    int sum2 = 0;
    for (int i = 1; i <= N; i++)
    {
        sum2 += i;
    }
    y = sum2 * 4 - sum;
    cout << y << endl;
}

