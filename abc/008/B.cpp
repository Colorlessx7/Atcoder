#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 0; i <= N; i++)
int main(){
    int N;
    cin >> N;
    vector<string> S(N);
    rep(i,N) {
        cin >> S.at(i);
    }
    int cnt = 1;
    string ans = S[0];
    int cnt2 = 0;
    sort(S.begin(),S.end());
    rep2(i,N){
        if(S[i] == S[i + 1]){
            cnt++;
        }else {
            if(i == N - 1){
                cnt++;
            }
            if(cnt > cnt2){
                cnt2 = cnt;
                cnt = 0;
                ans = S[i];
            }else {
                cnt = 0;
            }
        }
    }
    cout << ans << endl;
    
    return 0;
}
