#include<bits/stdc++.h>
using namespace std;
void ans2(int a, int b, vector<vector<char>>  &bomb, vector<vector<char>> &ans){
    int y = 0;
    for (int i = a; i <= a + 2; i++)
    {
        for (int j = b; j <= b + 2; j++)
        {
            if(i == a + 1 && j == b + 1){
                continue;
            }else if(bomb.at(i).at(j) == '#'){
                y++;
            }
        }
        
    }
    
    char c = '0' + y;
    ans.at(a).at(b) = c;
}

int main(){
    int H, W;
    cin >> H >> W;
    vector<vector<char>> bomb(H + 2, vector<char>(W + 2, '.'));
    int i=0; int j =0;
    for (i = 1; i <= H; i++)
    {
        for (j = 1; j <= W; j++)
        {
            cin >> bomb.at(i).at(j);
        }    
    }

    vector<vector<char>> ans(H, vector<char>(W));
    for (i = 0; i < H; i++)
    {
        for (j = 0; j < W; j++)
        {
            if (bomb.at(i + 1).at(j + 1) == '#'){
                ans.at(i).at(j) = '#';

            }else {
                ans2(i, j, bomb, ans);
                
            }
        }
    }
    for (i = 0; i < H; i++)
    {
        for (j = 0; j < W; j++)
        {
            cout << ans.at(i).at(j);
            if (j == W - 1)
            {
                cout << endl;
            }
        }
    }
}
