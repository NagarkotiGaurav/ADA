#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
	int cost = 0;
	int mergedCost=0;
	cout<<"Enter the number of files: ";
	cin>>n;
	int files[n];
	cout<<"Enter the size of files: "<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"F"<<i+1<<" : ";
		cin>>files[i];
	}
	sort(files,files+n);
	while(n>1)
	{
		mergedCost = files[0] + files[1];
		cost = cost + mergedCost;
		files[0] = mergedCost;
		for (int i = 1; i < n - 1; i++) 
		{
            files[i] = files[i + 1];
        }
        n--;
        sort(files,files+n);
	}
	cout<<"Minimum cost for merging the files: "<<cost;
	return 0;
}
