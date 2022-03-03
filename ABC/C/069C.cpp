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
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
        a[i] %= 4;
    }
    int x = 0, y = 0;
    rep(i,n){
        if(a[i] == 0){
            x++;
        }
        if(a[i] == 2){
            y++;
        }
    }
    if(x >= n / 2){
        cout << "Yes" << endl;
    }else if((n - 2 * x) == y){
        cout << "Yes" << endl;
    }else {
        cout << "No" << endl;
    }
    return 0;
}
//数学的考察
//Ai*Ai+1の積が4の倍数になるパターンはある3文字の中間に4の倍数があるパターンと
//4の倍数に隣接した位置に2が並んで2*2しているパターンの2種類
//全ての隣り合うAの積が4の倍数にならないといけないので
//A%4が2のものと0(割り切れる)ものをカウントして
//if文の条件を満たすかどうかで判定
