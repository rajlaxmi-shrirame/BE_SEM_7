#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
using namespace std;

class NQueens
{
    int n;

public:
    NQueens(int n)
    {
        this->n = n;
    }
    bool isSafe(vector<string> board, int row, int col);
    void solve(vector<string> &board, vector<vector<string>> &ans, int col);
};

bool NQueens::isSafe(vector<string> board, int row, int col)
{
    // Check the row
    rep(i, 0, n)
    {
        if (board[row][i] == 'Q')
            return false;
    }

    // Check the column
    rep(i, 0, n)
    {
        if (board[i][col] == 'Q')
            return false;
    }

    // Check upper right diagonal
    int r = row, c = col;
    while (r >= 0 && c < n)
    {
        if (board[r][c] == 'Q')
            return false;
        r--;
        c++;
    }

    // Check upper left diagonal
    r = row, c = col;
    while (r >= 0 && c >= 0)
    {
        if (board[r][c] == 'Q')
            return false;
        r--;
        c--;
    }

    // Check lower right diagonal
    r = row, c = col;
    while (r < n && c < n)
    {
        if (board[r][c] == 'Q')
            return false;
        r++;
        c++;
    }

    // Check lower left diagonal
    r = row, c = col;
    while (r < n && c >= 0)
    {
        if (board[r][c] == 'Q')
            return false;
        r++;
        c--;
    }

    return true;
}

void NQueens::solve(vector<string> &board, vector<vector<string>> &ans, int col)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }

    rep(row, 0, n)
    {
        if (isSafe(board, row, col))
        {
            board[row][col] = 'Q';
            solve(board, ans, col + 1);
            board[row][col] = '.';
        }
    }
}

int main()
{
    int n;
    cout << "Enter the value of N (number of queens and size of board): " << endl;
    cin >> n;

    if (n < 1)
    {
        cout << "N must be a positive integer." << endl;
        return 0;
    }

    NQueens nq(n);
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));

    nq.solve(board, ans, 0); // Start from column 0

    if (ans.size() == 0)
    {
        cout << "No solutions found." << endl;
    }
    else
    {
        cout << "Number of solutions: " << ans.size() << endl;
        rep(i, 0, ans.size())
        {
            cout << "Solution " << i + 1 << ":" << endl;
            rep(j, 0, ans[0].size())
            {
                cout << ans[i][j] << endl;
            }
            cout << endl;
        }
    }

    return 0;
}
