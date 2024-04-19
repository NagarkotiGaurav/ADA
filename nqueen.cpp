#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>> &board, int N, int row, int col)
{

  int i, j;
  for (i = 0; i < col; i++)
  {
    if (board[row][i])
    {
      return false;
    }
  }

  for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
  {
    if (board[i][j])
    {
      return false;
    }
  }
  for (i = row, j = col; i < N && j >= 0; i++, j--)
  {
    if (board[i][j])
    {
      return false;
    }
  }

  return true;
}



bool solveNqueen(vector<vector<int>> &board, int col, int N)
{
  if (col >= N)
  {
    return true;
  }

  for (int row = 0; row < N; row++)
  {
    if (isSafe(board, N, row, col))
    {
      board[row][col] = 1;

      if (solveNqueen(board, col + 1, N))
      {
        return true;
      }
      board[row][col] = 0;
    }
  }
  return false;
}


void print(vector<vector<int>> board, int N)
{
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
}
void Nqueen(int N)
{
  vector<vector<int>> board(N, vector<int>(N, 0));

  if (solveNqueen(board, 0, N))
  {
    print(board, N);
  }
  else
  {
    cout << "no solution...";
  }
}
int main()
{
  Nqueen(8);
}