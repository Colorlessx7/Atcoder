#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> p(n,k - q);
    rep(i,q){
        int a;
        cin >> a;
        a--;
        p[a]++;
    }
    rep(i,n){
        if(p[i] > 0){
            puts("Yes");
        }else {
            puts("No");
        }
    }
    return 0;
}
/*9~14行目のように直接的に関係がないaのベクトルは宣言しなくていい
putsを使うとendl分の処理時間短縮になる
9~14行目の考え方はこれからも使う可能性があるため注意*/
