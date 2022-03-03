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
    ll n, m;
    cin >> n >> m;
    if(n != 1){
        n -= 2;
    }
    if(m != 1){
        m -= 2;
    }
    cout << n * m << endl;
    return 0;
}
//数学的考察
//でかい四角形は頂点4点が4回、それを除く外枠が6回
//内側(n-2)*(m-2)の空間が9回裏返るため、奇数回裏返る部分だけ考えると
//でかい四角形は(n-2)*(m-2)で求められる
//例外は1*7や5*1といった辺1本の場合
//1だけは-2処理を行わないことで計算できる
