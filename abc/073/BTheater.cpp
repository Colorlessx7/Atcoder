#include<bits/stdc++.h>
using namespace std;
int sum(vector<vector<int>> lr, int N); 
int main()
{
    int N;
    cin >> N;
    vector<vector<int>> lr(N, vector<int>(2));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> lr.at(i).at(j);
        }   
    }
    int y = 0;
    y = sum(lr, N);
    cout << y << endl;
}
int sum(vector<vector<int>> lr, int N)
{
    int y;
    for (int i = 0; i < N; i++)
    {
        y += lr.at(i).at(1) - lr.at(i).at(0) + 1;
    }
    return y;
}
