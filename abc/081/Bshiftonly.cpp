#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
int ansA(vector<int> A, int N){
    int ans = 0;
    bool check = 0;
    while (check == 0)
    {
        rep(i, N)
        {
            if (A.at(i) % 2 != 0)
            {
                check = 1;
                break;
            }
            if (i == N - 1){
                rep(j, N)
                {
                    A.at(j) /= 2;
                }
                ans++;  
            }
        }
    }
    return ans;
}
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N)
    {
        cin >> A.at(i); 
    }
    cout << ansA(A, N) << endl;
}
