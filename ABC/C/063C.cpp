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
void dfs(int i,int sum,int n,int& ans,vector<int>& s){
    //cout << i << " " << sum << endl;
    if(i == n){
        if(sum % 10 != 0){
            ans = max(sum,ans);
        }
        return;
    }
    int l = i + 1;
    int k = sum;
    rep(j,2){
        if(j == 0){
            k += s[i];
            dfs(l,k,n,ans,s);
        }else {
            k -= s[i];
            dfs(l,k,n,ans,s);
        }
    }
    return;
}
int main(){
    int n;
    cin >> n;
    vector<int> s(n);
    rep(i,n){
        cin >> s[i];
    }
    int ans = 0;
    dfs(0,0,n,ans,s);
    cout << ans << endl;
    return 0;
}
//tleしたdfs解
