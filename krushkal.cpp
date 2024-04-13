


#include <iostream>
#include <limits.h>
using namespace std;

int findVertix(int i,int parent[])
{
    while(parent[i] != 0) 
	{
        i = parent[i];
    }
    return i;
}

int unionVertices(int i, int j,int parent[])
{
    if (i != j) 
	{
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main()
{
    int V;
	cout<<"\nEnter the no. of vertices: ";
	cin>>V;
	int cost[V][V];
	int parent[V]={0};
	cout<<"\nEnter the adjacency matrix: "<<endl;
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
		{
			cin>>cost[i][j];
		}
	}
    for (int i = 0; i < V; i++) 
	{
        for (int j = 0; j < V; j++) 
		{
            if (cost[i][j] == 0) 
			{
                cost[i][j] = INT_MAX;
            }
        }
    }
    cout << "\nMinimum Cost Spanning Tree:\n";
    cout<<"\nSource Vertex \t  Destination Vertex \t Cost"<<endl;
    int k=1;
    int a,b,u,v;
    while (k < V) 
	{
        int min_edge = INT_MAX;
        for (int i=0; i<V; i++) 
		{
            for (int j = 0; j < V; j++) 
			{
                if (cost[i][j] < min_edge) 
				{
                    min_edge = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = findVertix(u,parent);
        v = findVertix(v,parent);
        if(unionVertices(u, v,parent) != 0) 
		{
            cout<<"\t"<<a<<" \t\t "<<b<<" \t\t  "<<min_edge<<endl;
        }
        cost[a][b] = cost[b][a] = INT_MAX;
        k++;
    }
    return 0;
}