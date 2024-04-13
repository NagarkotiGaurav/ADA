

#include <iostream>
#include <limits.h>
using namespace std;

int findMin(int dist[],int V,bool visited[])
{
	int min_i = INT_MAX;
	int min_dist = INT_MAX;
	for(int i=0;i<V;i++)
	{
		if(visited[i]==false && dist[i]<min_dist)
		{
			min_i = i;
			min_dist = dist[i];
		}
	}
	return min_i;
}

void dijkstra(int graph[20][20],int V,int source)
{
	int dist[V];
	bool visited[V];
	for(int i=0;i<V;i++)
	{
		dist[i] = INT_MAX;
		visited[i] = false;
	}
	dist[source] = 0;
	
	for(int i=0;i<V-1;i++)
	{
		int u = findMin(dist,V,visited);
		visited[u] = true;
		
		for(int v=0;v<V;v++)
		{
			if(visited[v]!=true && graph[u][v] && dist[v] > dist[u] + graph[u][v])
			{
				dist[v] = dist[u] + graph[u][v];
			}
			
		}
	}
	cout<<"\nVertex \t Distance from source"<<endl;
	for(int v=0;v<V;v++)
	{
		cout<<v<<" \t\t "<<dist[v]<<endl;
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
	int src;
	cout<<"\nEnter the source vertex: ";
	cin>>src;
	dijkstra(graph,v,src);
	
	return 0;
}