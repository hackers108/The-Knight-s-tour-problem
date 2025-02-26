#include <bits/stdc++.h>
using namespace std;

#define N 8

bool isSafe(int x, int y, int sol[N][N])
{
    return (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1);
}

void printSolution(int sol[N][N])
{
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++)
            cout << " " << setw(2) << sol[i][j] << " ";
        cout << endl;
    }
}

bool solveKTUtil(int x, int y, int movei, int sol[N][N], int xMove[], int yMove[])
{
    if (movei == N * N)
    {
        return true;
    }    
    for (int k = 0; k < 8; k++)
    {
        int next_x = x + xMove[k];
        int next_y = y + yMove[k];
        
        if (isSafe(next_x, next_y, sol))
        {
            sol[next_x][next_y] = movei;
            if (solveKTUtil(next_x, next_y, movei + 1, sol, xMove, yMove)) return true;
            sol[next_x][next_y] = -1;
        }
    }
    return false;
}

bool solveKT(int startX, int startY)
{
    int sol[N][N];
    memset(sol, -1, sizeof(sol));
    
    int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    
    sol[startX][startY] = 0;
    
    if (!solveKTUtil(startX, startY, 1, sol, xMove, yMove))
    {
        cout << "Solution does not exist";
        return false;
    }
    printSolution(sol);
    return true;
}

int main()
{
    int startX, startY;
    cout << "Enter starting X and Y coordinates (0-based index): ";
    cin >> startX >> startY;
    
    if (startX < 0 || startX >= N || startY < 0 || startY >= N) {
        cout << "Invalid starting position";
        return 0;
    }
    
    solveKT(startX, startY);
    return 0;
}
