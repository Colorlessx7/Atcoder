#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 1;
    rep(i,n - 1){
        if(s[i] != s[i + 1]){
            cnt++;
        } 
    }
    cout << cnt << endl;
    return 0;
}
