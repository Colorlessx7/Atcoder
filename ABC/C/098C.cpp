#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep3(i,N) for(int i = N - 1; i >= 0; i--)
#define rep4(i,N) for(int i = N; i > 0; i--)
#define all(x) x.begin(),x.end() 
typedef long long ll;
using P = pair<int,int>;
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char,int> left;
    map<char,int> right;
    rep(i,n){
        if(i == 0){
            continue;
        }
        right[s[i]]++;
    }
    int ans = INT_MAX;
    int x = right['E'];
    ans = min(x,ans);
    for(int i = 1; i < n; i++){
        left[s[i-1]]++;
        right[s[i]]--;
        x = left['W'] + right['E'];
        ans = min(x,ans);
    }
    cout << ans << endl;
    return 0;
}
