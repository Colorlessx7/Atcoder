#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> score(N);
    int i;
    for ( i = 0; i < N; i++)
    {
        cin >> score.at(i);
    }
    int y = 0;
    for ( i = 0; i < N; i++)
    {
        y += score.at(i);
    }
    y = y / N;
    for ( i = 0; i < N; i++)
    {
        if (y == score.at(i)){
            cout << 0 << endl;
        }else if (y < score.at(i)){
            cout << score.at(i) - y << endl;
        }else if (y > score.at(i)){
            cout << y - score.at(i) << endl;
        }
    }
    

}

