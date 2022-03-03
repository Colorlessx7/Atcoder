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
    vector<int> r(n),c(n);
    rep(i,n){
        cin >> r[i];
    }
    rep(i,n){
        cin >> c[i];
    }
    int q;
    cin >> q;
    rep(i,q){
        int rq, cq;
        cin >> rq >> cq;
        rq = r[rq-1];
        cq = c[cq-1];
        cout << ((rq+cq)>n ? '#' : '.');
    }
    cout << endl;
    return 0;
}
//例1を考える 以下入力
//5
//5 2 3 4 1
//4 2 3 1 5
//これを各座標に対応させ、その後合計を取ると
//(5,4)(5,2)(5,3)(5,1)(5,5) 9 7 8 6 10
//(2,4)(2,2)(2,3)(2,1)(2,5) 6 4 5 3 7
//(3,4)(3,2)(3,3)(3,1)(3,5) 7 5 6 4 8 
//(4,4)(4,2)(4,3)(4,1)(4,5) 8 6 7 5 9
//(1,4)(1,2)(1,3)(1,1)(1,5) 5 3 4 2 6
//合計を見るとRr + Cc > n がtrueなら#
//falseなら.ということが成り立つ
//これを実装する
