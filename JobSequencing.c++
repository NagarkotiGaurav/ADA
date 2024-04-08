#include <bits/stdc++.h>
using namespace std;

typedef struct Job
{
    char id;
    int profit;
    int deadline;

} Job;

bool compare(Job a, Job b)
{
    return (a.profit - b.profit);
}

void jobSequence(Job jobs[], int n)
{

    sort(jobs, jobs + n, compare);

    int result[n]; // To store result (Sequence of jobs)
    bool time[n];  // To keep track of free time

    for (int i = 0; i < n; i++)
        time[i] = false;

    for (int i = 0; i < n; i++)
    {

        for (int j = min(n, jobs[i].deadline) - 1; j >= 0; j--)
        {

            if (time[j] == false)
            {
                result[j] = i;
                time[j] = true;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (time[i])
        {
            cout << jobs[result[i]].id << ' ';
        }
    }
}
int main()
{
    Job jobs[] = {{'A', 70, 4},
                  {'B', 20, 1},
                  {'C', 30, 2},
                  {'D', 40, 1},
                  {'E', 60, 3}};
    int n = 5;
    cout << "The maximum profit can be achieved by doing the following jobs in sequence.\n";
    jobSequence(jobs, n);
    return 0;
}