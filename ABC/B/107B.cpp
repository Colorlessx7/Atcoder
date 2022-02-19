#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int h, w;
    cin >> h >> w;
    vector<vector<char>> a(h,vector<char>(w));
    rep(i,h){
        rep(j,w){
            cin >> a[i][j];
        }
    }
    vector<bool> hc(h),wc(w);
    bool c;
    rep(i,h){
        rep(j,w){
            c = 1;
            if(a[i][j] == '#'){
                c = 0;
                break;
            }
        }
        if(c){
            hc[i] = 1;
        }
    }
    rep(j,w){
        rep(i,h){
            c = 1;
            if(a[i][j] == '#'){
                c = 0;
                break;
            }
        }
        if(c){
            wc[j] = 1;
        }
    }
    rep(i,h){
        if(hc[i]){
            continue;
        }
        rep(j,w){
            if(wc[j]){
                continue;
            }
            cout << a[i][j];
        }
        if(!hc[i]){
            cout << endl;
        }
    }
    return 0;
}
