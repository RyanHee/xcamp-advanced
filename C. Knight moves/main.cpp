#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int n;

struct knight{
    int x;
    int y;
    int moves;

    knight(int x1, int y1, int m) :
            x(x1), y(y1), moves(m) {
    }
};


bool inside(knight k){
    if (k.x>=0 && k.x<n){
        if (k.y>=0 && k.y<n){
            return true;
        }
    }
    return false;
}


int solve(knight curr, knight dest){
    vector<vector<bool>>visited(n+1, vector<bool>(n+1));

    int x_shift[]={-2, -1, 1, 2, 2, 1, -1, -2};
    int y_shift[]={1, 2, 2, 1, -1, -2, -2, -1};
    queue<knight>q;
    q.push(curr);

    while (!q.empty()){
        knight k = q.front();
        int x=k.x;
        int y=k.y;
        q.pop();
        if (x==dest.x && y==dest.y){
            return k.moves;
        }
        for (int i=0;i<8;i++){
            knight moved = knight(x+x_shift[i], y+y_shift[i], k.moves+1);

            if (inside(moved)&&!visited[x+x_shift[i]][y+y_shift[i]]){
                visited[x+x_shift[i]][y+y_shift[i]]=true;
                q.push(moved);
            }
        }
    }


}





int main() {

    cin>>n;
    int x,y;
    cin>>x>>y;
    knight k = knight(x,y,0);
    cin>>x>>y;
    knight dest = knight(x,y,0);



    cout<<solve(k, dest)<<endl;




}
