#include<bits/stdc++.h>
using namespace std;

#define N 8

bool isSafe(int sol[N][N],int x,int y) {
    if(x<N and y<N and x>=0 and y>=0 and sol[x][y] == -1)
    return 1;
    else
    return 0;
}

void print(int sol[N][N]) {
    for(int i = 0;i<N;i++) {
        for(int j = 0;j<N;j++) {
            cout<<sol[i][j]<<" ";
        }
        cout<<endl;
    }
}

    int dx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 }; 
    int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 }; 

int solve(int sol[N][N],int x,int y,int move) {

    if(move == N*N)
    return 1;

    int k;
    int next_x;
    int next_y;

    for(k = 0;k<8;k++) {
        next_x = x+dx[k];
        next_y = y+dy[k];

        if(isSafe(sol,next_x,next_y)) 
        {
            sol[next_x][next_y] = move;
            if (solve(sol,next_x, next_y, move + 1) == 1)
                return 1;
            else 
                sol[next_x][next_y] = -1; 
        }
        
    }
    return 0;
}

int main() {
    int sol[N][N]; 
    for (int x = 0; x < N; x++) 
        for (int y = 0; y < N; y++) 
            sol[x][y] = -1; 
    sol[0][0] = 0; 
    solve(sol,0,0,1); 
    print(sol);
    return 0; 
}