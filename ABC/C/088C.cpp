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
    vector<vector<int>> c(3,vector<int>(3));
    int m = 1001001001;
    int qi = 0;
    int qj = 0;
    rep(i,3){
        rep(j,3){
            cin >> c[i][j];
            if(m > c[i][j]){
                qi = i;
                qj = j;
            }
            m = min(m,c[i][j]);
        }
    }
    vector<int> a(3),b(3);
    rep(i,3){
        a[i] = c[i][qj];
    }
    rep(j,3){
        b[j] = c[qi][j];
    }
    bool check = 0;
    rep(i,3){
        int f = c[i][0] - b[0];
        rep(j,3){
            if(f != c[i][j] - b[j]){
                check = 1;
                break;
            }
        }
        if(check){
            break;
        }
    }
    if(!check){
        rep(j,3){
            int f = c[0][j] - a[0]; 
            rep(i,3){
                if(f != c[i][j] - a[i]){
                    check = 1;
                    break;
                }
            }
            if(check){
                break;
            }
        }
    }
    if(check){
        cout << "No" << endl;
    }else {
        cout << "Yes" << endl;
    }
    return 0;
}
