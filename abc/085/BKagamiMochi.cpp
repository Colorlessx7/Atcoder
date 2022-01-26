#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
int main(){
    int N;
    cin >> N;
    vector<int> d(N);
    rep(i,N) {
        cin >> d.at(i);
    }
    int cnt = 1;
    sort(d.begin(), d.end());
    for(int i = 1; i < N; i++){
        if(d.at(i - 1) != d.at(i)){
            cnt++;
        }
    }
    cout << cnt << endl;  
}    





