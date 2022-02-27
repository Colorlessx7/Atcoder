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
    int n, cnt;
    cin >> n;
    bool ans = false;
    vector<vector<char>> s(n,vector<char>(n));
    rep(i,n){
        rep(j,n){
            cin >> s[i][j];
        }
    }
    //基準点を決めるための二重ループ
    rep(i,n){
		rep(j,n){
			//縦の判定
            //基準点(i,j)から縦6マス分検証できる範囲のiなら処理
            //(n=7ならi=0,1の範囲)
            if((i + 5) < n){
				//6つの範囲内に#が何個あるか都度計上
                cnt = 0;
                //基準点から6マス分を検証(#が検出されたら+1)
                //(i,j)=(0,0)なら(0,0),(1,0),(2,0),(3,0),(4,0),(5,0)
				rep(k,6){
                    if(s[i + k][j] == '#'){
                        cnt++;
                    } 
                } 
				//見ている6つの範囲で#が4つ以上検出されたなら
                //2つ.を#で埋めて6連結した#ができるのでフラグを立てる
                //以下のも全部一緒
                if(cnt >= 4){
                    ans = true;
                } 
			}
            //横の判定
            //基準点(i,j)から横6マス分検証できる範囲のjなら処理
            //(n=7ならj=0,1の範囲)
			if((j + 5) < n){
				cnt = 0;
				//基準点から6マス分を検証(#が検出されたら+1)
                //(i,j)=(0,0)なら(0,0),(0,1),(0,2),(0,3),(0,4),(0,5)
                rep(k,6){
                    if(s[i][j + k] == '#'){
                        cnt++;
                    } 
                } 
				if(cnt >= 4){
                    ans = true;
                } 
			}
            //左上から右下への対角線上の判定
            //基準点(i,j)から右下方向6マス分検証できる範囲のi,jなら処理
            //(n=7なら(0,0),(0,1),(1,0)の範囲)
			if(((i + 5) < n) && ((j + 5) < n)){
				cnt = 0;
                //基準点から6マス分を検証(#が検出されたら+1)
                //(i,j)=(0,0)なら(0,0),(1,1),(2,2),(3,3),(4,4),(5,5)
				rep(k,6){
                    if(s[i + k][j + k] == '#'){
                        cnt++;
                    }
                } 
				if(cnt >= 4){
                    ans = true;
                } 
			}
            //右上から左下への対角線上の判定
            //基準点(i,j)から左下方向6マス分検証できる範囲のi,jなら処理
            //(n=7なら(5,0),(5,1),(6,0)の範囲)
			if((0 <= (i - 5)) && ((j + 5) < n)){
				cnt = 0;
                //基準点から6マス分を検証(#が検出されたら+1)
                //(i,j)=(6,0)なら(6,0),(5,1),(4,2),(3,3),(2,4),(1,5)
				rep(k,6){
                    if(s[i - k][j + k] == '#'){
                        cnt++;
                    } 
                } 
				if(cnt >= 4){
                    ans = true;
                }
			}
		}
	}
    //ansが1ならyes,0ならno
    cout << (ans ? "Yes" : "No") << endl;
    return 0;
}
//配列の処理能力を見る問題
//二つ.を#に変えて縦、横、斜めの#6連結ができるか判定する問題
//制約が小さいため2重ループでいちいち指定の範囲の6つを取り出して判定が可能
//(O(N^2))といちいち範囲を指定した時の6回分
