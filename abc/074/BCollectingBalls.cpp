#include<bits/stdc++.h>
using namespace std;
int main(){
    int N, K;
    cin >> N >> K;
    vector<int> vec(N);
    for (int i = 0; i < N; i++)
    {
        cin >> vec.at(i); 
    }
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        if (vec.at(i) <= K - vec.at(i)){
            sum += vec.at(i) * 2;
        } else {
            sum += (K - vec.at(i)) * 2;
        }
    }
    cout << sum << endl;
}
