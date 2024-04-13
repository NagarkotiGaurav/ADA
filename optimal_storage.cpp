#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	int sum=0;
	double MRT = 0;
	cout<<"Enter the number of programs: ";
	cin>>n;
	int plength[n];
	cout<<"Enter the length of programs: "<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"P"<<i+1<<" : ";
		cin>>plength[i];
	}
	sort(plength,plength+n);
	for(int i=0;i<n;i++)
	{
		sum = sum + plength[i];
		MRT = MRT + sum;
	}
	MRT = MRT/n;
	cout<<"Mean Retrieval Time: "<<MRT;
	return 0;
}

