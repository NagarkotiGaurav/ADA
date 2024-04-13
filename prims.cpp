

#include <iostream>
#include <limits.h>
using namespace std;

int findMin(int key[],int V,bool visited[])
{
	int min_i = INT_MAX;
	int min_key = INT_MAX;
	for(int i=0;i<V;i++)
	{
		if(visited[i]==false && key[i]<min_key)
		{
			min_i = i;
			min_key = key[i];
		}
	}
	return min_i;
}

void primMST(int graph[20][20],int V)
{
	int key[V];
	int parent[V];
	bool visited[V];
	
	for(int i=0;i<V;i++)
	{
		key[i] = INT_MAX;
		visited[i] = false;
	}
	
	key[0] = 0;
	parent[0] = -1;
	
	for(int i=0;i<V-1;i++)
	{
		int u = findMin(key,V,visited);
		visited[u] = true;
		
		for(int v=0;v<V;v++)
		{
			if(visited[v]!=true && graph[u][v] && graph[u][v] < key[v])
			{
				parent[v] = u;
				key[v] = graph[u][v];
			}
			
		}
	}
	cout<<"\nSource Vertex \t  Destination Vertex \t Distance"<<endl;
	for(int v=0;v<V;v++)
	{
		cout<<"\t"<<parent[v]<<" \t\t "<<v<<" \t\t\t"<<key[v]<<endl;
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
	primMST(graph,v);
	
	return 0;
}