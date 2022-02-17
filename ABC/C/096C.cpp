#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int h, w;
    cin >> h >> w;
    vector<vector<char>> s(h,vector<char>(w));
    rep(i,h){
        rep(j,w){
            cin >> s[i][j];
        }
    }
    bool n = 0;
    rep(i,h){
        rep(j,w){
            if(s[i][j] == '#'){
                if(((i==0)||(s[i-1][j]=='.'))&&((i==h-1)||(s[i+1][j]=='.'))){
                    if(((j==0)||(s[i][j-1]=='.'))&&((j==w-1)||(s[i][j+1]=='.'))){
                        n = 1;
                        break;
                    }
                }
            }
        }
        if(n){
            break;
        }
    }
    if(n){
        cout << "No" << endl;
    }else {
        cout << "Yes" << endl;
    }
    return 0;
}
