#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep3(i,N) for(int i = N - 1; i >= 0; i--)
#define rep4(i,N) for(int i = N; i > 0; i--)
#define replr(i,l,r) for(int i = l; i < r; i++)
#define reprl(i,l,r) for(int i = l; i > r; i--)
#define all(x) x.begin(),x.end() 
#define allr(x) x.rbegin(),x.rend() 
typedef long long ll;
using P = pair<int,int>;
int main(){
    int h,w,k;
    cin >> h >> w >> k;
    vector<string> s(h);
    rep(i,h){
        cin >> s[i];
    }
    int ans = 0;
    rep(is,1 << h){
        rep(js,1 << w){
            int cnt = 0;
            rep(i,h){
                rep(j,w){
                    if(is >> i & 1) continue;
                    if(js >> i & 1) continue;
                    if(s[i][j] == '#') cnt++;
                }
            }
        }
        if(cnt == k) ans++;
    }
    cout << ans << endl;
    return 0;
}
