

#include <iostream>
#include<limits.h>
using namespace std;

void BellmanFord(int graph[][3], int V, int E, int src)
{
	int dist[V];
	for (int i = 0; i < V; i++)
	{
		dist[i] = INT_MAX;
	}
	dist[src] = 0;
	
	for (int i = 0; i < V - 1; i++) 
	{
		for (int j = 0; j < E; j++) 
		{
			if (dist[graph[j][0]] != INT_MAX && dist[graph[j][0]] + graph[j][2] <dist[graph[j][1]])
			{
				dist[graph[j][1]] = dist[graph[j][0]] + graph[j][2];
			}	
		}
	}
	
	for (int i = 0; i < E; i++) 
	{
		int x = graph[i][0];
		int y = graph[i][1];
		int weight = graph[i][2];
		
		if (dist[x] != INT_MAX && dist[x] + weight < dist[y])
		{
			cout << "\nGraph contains negative weight cycle"<< endl;
		}
	}

	cout << "\nVertex \tDistance from Source" << endl;
	for (int i = 0; i < V; i++)
	{
		cout << i << "\t\t " << dist[i] << endl;
	}
	
}

int main()
{
	int V,E;
	cout<<"\nEnter the number of vertices and edges: ";
	cin>>V>>E;
	cout<<"\nEnter the source, destination vertix and weight: "<<endl;
	int graph[E][3];
	for(int i=0;i<E;i++)
	{
		cin>>graph[i][0];
		cin>>graph[i][1];
		cin>>graph[i][2];
	}
	BellmanFord(graph, V, E, 0);
	
	return 0;
}