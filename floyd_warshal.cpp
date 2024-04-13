#include <iostream>
#include <limits.h>

using namespace std;

void floydWarshall(int V,int dist[][20])
{
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
		{
			if(dist[i][j]==0)
			{
				dist[i][j] = INT_MAX;
			}
			if(i==j)
			{
				dist[i][j]=0;
			}
		}
	}
	
	for (int k = 0; k < V; k++) 
	{
		for (int i = 0; i < V; i++) 
		{
			for (int j = 0; j < V; j++) 
			{		
				if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != INT_MAX && dist[i][k] != INT_MAX))
				{
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	cout<<"\nAll pair shortest path matrix: \n";
	for (int i = 0; i < V; i++) 
	{
        for (int j = 0; j < V; j++) 
		{
            if (dist[i][j] == INT_MAX)
            {
                cout << "INF"<< " ";
            }
            else{
                cout << dist[i][j] << "   ";
            }
        }
        cout << endl;
    }
	
}

int main()
{
	int v;
	cout<<"\nEnter the no. of vertices: ";
	cin>>v;
	int graph[20][20];
	cout<<"\nEnter the adjacency matrix: "<<endl;
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			cin>>graph[i][j];
		}
	}
	floydWarshall(v,graph);
	return 0;
}


