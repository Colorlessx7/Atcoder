#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<char> S(N);
    for (int i = 0; i < N; i++)
    {
        cin >> S.at(i);
    }
    for (int i = 0; i < N; i++)
    {
        if (S.at(i) == 'Y'){
            cout << "Four" << endl;
            break;
        }else if (i == N - 1){
            cout << "Three" << endl;
        }
    }
    
     
}
