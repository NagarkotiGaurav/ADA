#include <iostream>
using namespace std;
#include <cstdlib>

void printarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void Sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        for (; j >= 0; j--)
        {
            if (arr[j] > temp)
            {
                // shift
                arr[j + 1] = arr[j];
            }
            else
            {
                // ruk jao
                break;
            }
        }
        arr[j + 1] = temp;
    }
}

void ContainerLoading(int containerList[], int capacity, int size, int x[])
{
    Sort(containerList, size);
    printarray(containerList, size);
    // initilize x
    for (int i = 0; i <= size; i++)
    {
        x[i] = 0;
    }
    // select container in order of weight
    int i = 0;
    while (i < size)
    {
        if (containerList[i] <= capacity)
        {
            x[i]=1;
            capacity-=containerList[i];
        }
        i++;
    }
    printarray(x,size);
}

int main()
{
    int capacity = 400;
    int containerList[] = {100, 200, 50, 90, 150, 50, 20, 80};
    int size = sizeof(containerList) / sizeof(containerList[0]);
    int x[size];
    ContainerLoading(containerList,capacity,size,x);
    return 0;
}
