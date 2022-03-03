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
    int h, w;
    cin >> h >> w;
    vector<vector<char>> c(h,vector<char>(w));
    vector<bool> bh(5,0);
    rep(i,h){
        rep(j,w){
            cin >> c[i][j];
        }
    }
    int x = 0;
    rep(i,h){
        rep(j,w){
            rep(k,5){
                bh[k] = 0;
            }
            if(c[i][j] == '.'){
                if(i != 0 && c[i-1][j] != '.'){
                    x = c[i-1][j] - '1';
                    bh[x] = 1;
                }
                if(j != 0 && c[i][j-1] != '.'){
                    x = c[i][j-1] - '1';
                    bh[x] = 1;
                }
                if(i != h-1 && c[i+1][j] != '.'){
                    x = c[i+1][j] - '1';
                    bh[x] = 1;
                }
                if(j != w-1 && c[i][j+1] != '.'){
                    x = c[i][j+1] - '1';
                    bh[x] = 1;
                }
                rep(k,5){
                    if(!bh[k]){
                        c[i][j] = '1' + k;
                        break;
                    }
                }
                /*cout << i << ":" << j << endl;
                rep(k,5){
                    cout << (bh[k] ? 1 : 0) << " ";
                }
                cout << endl;*/
            }
        }
    }
    
    rep(i,h){
        rep(j,w){
            cout << c[i][j];
        }
        cout << endl;
    }
    return 0;
}
