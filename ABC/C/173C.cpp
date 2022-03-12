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
    int h, w, k;
    cin >> h >> w >> k;
    vector<vector<char>> c(h,vector<char>(w));
    int cnt = 0;
    rep(i,h){
        rep(j,w){
            cin >> c[i][j];
            if(c[i][j] == '#'){
                cnt++;
            }
        }
    }
    cnt -= k;
    map<char,int> mp;
    vector<vector<bool>> looked(h,vector<bool>(w));
    int f = pow(2,(h + w)); 
    int ans = 0;
    for(int x = 0; x < f; x++){
        for(int i = 0; i < (h + w); i++){
            if(x & (1 << i)){
                if(i < h){
                    rep(j,w){
                        if(!looked[i][j] && c[i][j] == '#'){
                            mp['#']++;
                            looked[i][j] = true;
                        }
                    }
                }else {
                    int d = i - h;
                    rep(j,h){
                        if(!looked[j][d] && c[j][d] == '#'){
                            mp['#']++;
                            looked[j][d] = true;
                        }
                    }
                }
            }else {
                continue;
            }
        }
        if(mp['#'] == cnt){
            ans++;
        }
        mp['#'] = 0;
        rep(j,h){
            rep(k,w){
                looked[j][k] = false;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
//bit全探索問題
