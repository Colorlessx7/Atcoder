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
using P = pair<int,int>;
int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<bool> prime(201,1);
    prime[0] = 0;
    prime[1] = 0;
    for(int i = 2; i * i <= 200; ++i){
        if(prime[i]){
            for(int j = 2; i * j <= 200; ++j){
                prime[i * j] = 0;
            }
        }
    }
    for(int x = a; x <= b; x++){
        //f: フラグ
        bool f = 1;
        for(int y = c; y <= d; y++){
            //フラグはx+yが全て合成数の場合に1
            //x+yに1つ以上素数が混じっている場合は0
            f &= !prime[x+y];
        }
        //高橋のxに対し青木が何を選んでも素数にならないなら
        //高橋の勝利
        if(f){
            puts("Takahashi");
            return 0;
        }
    }
    //全てのxで青木が素数を作れないなら
    //青木の勝利
    puts("Aoki");
    return 0;
}
//15~24行目で事前にエラトステネスの篩を用いて素数の列挙を行う
//制約上abcdのそれぞれの最大は100なので素数判定は200まであれば良い
//判定部もO(100^2)で判定できるので2重ループで全探索を行う
//高橋君が勝つための必要十分条件は
//高橋君がXを選ぶと、青木君がどんな数を選んでも合成数しか作れないパターン
