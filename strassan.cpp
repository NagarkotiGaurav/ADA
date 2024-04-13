

#include <iostream>
using namespace std;

void strassenMultiply(int A[2][2], int B[2][2], int C[2][2]) 
{
    if (A[0][0] == 0 || B[0][0] == 0)
    {
        C[0][0] = 0;
        C[0][1] = 0;
        C[1][0] = 0;
        C[1][1] = 0;
        return;
    }

    int P1 = A[0][0] * (B[0][1] - B[1][1]);
    int P2 = (A[0][0] + A[0][1]) * B[1][1];
    int P3 = (A[1][0] + A[1][1]) * B[0][0];
    int P4 = A[1][1] * (B[1][0] - B[0][0]);
    int P5 = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
    int P6 = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);
    int P7 = (A[0][0] - A[1][0]) * (B[0][0] + B[0][1]);

    C[0][0] = P5 + P4 - P2 + P6;
    C[0][1] = P1 + P2;
    C[1][0] = P3 + P4;
    C[1][1] = P5 + P1 - P3 - P7;
}

int main() 
{
    int A[2][2], B[2][2], C[2][2];

    cout << "\nEnter the elements of matrix A (2x2):" << endl;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            cin >> A[i][j];

    cout << "\nEnter the elements of matrix B (2x2):" << endl;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            cin >> B[i][j];

    strassenMultiply(A, B, C);

    cout << "\nMatrix C (Result of Strassen's Multiplication):" << endl;
    for (int i = 0; i < 2; i++) 
    {
        for (int j = 0; j < 2; j++) 
        {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}