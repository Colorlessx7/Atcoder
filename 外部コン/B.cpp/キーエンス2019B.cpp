#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep3(i,N) for(int i = n - 1; i >= 0; i--)
#define rep4(i,N) for(int i = n; i > 0; i--)
#define all(x) x.begin(),x.end() 
typedef long long ll;
int main(){
    string s;
    cin >> s;
    int n = s.size();
    string head = "keyence";
    string tail = head;
    reverse(all(tail));
    int cnth = 0;
    int cntt = 0;
    rep(i,n){
        if(s[i] == head[i]){
            cnth++;
        }else {
            break;
        }
        if(i == 6){
            break;
        }
    }
    rep3(i,n){
        if(s[i] == tail[cntt]){
            cntt++;
        }else {
            break;
        }
        if(i == n - 7){
            break;
        }
    }
    if(cnth + cntt >= 7){
        cout << "YES" << endl;
    }else {
        cout << "NO" << endl;
    }
    return 0;
}
