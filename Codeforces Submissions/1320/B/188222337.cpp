#include <bits/stdc++.h>

using namespace std;

#define MAX (int) 2e5
#define INF INT_MAX

int distanceTo[MAX];

map<int, vector<int>> bertown1;
map<int, vector<int>> bertown2;

void BFS(int source)
{
	int parent;
	
	set<int> visited;
	queue<int> toVisit;
	
	toVisit.push(source);
	visited.insert(source);
	
	while(!toVisit.empty())
	{
		parent = toVisit.front();
		
		for(int child : bertown2[parent])
		{
			if(visited.count(child) == 0)
			{
				distanceTo[child] = distanceTo[parent] + 1;
				
				toVisit.push(child);
				visited.insert(child);
			}
		}
		
		toVisit.pop();
	}
}

int main()
{
	int n;
	int m;
	
	int a;
	int b;
	int k;
	int p;
	
	cin >> n;
	cin >> m;
	
	for(int i = 0; i < m; i++)
	{
		cin >> a;
		cin >> b;
		
		a--;
		b--;
		
		bertown1[a].push_back(b);
		bertown2[b].push_back(a);
	}
	
	int minCount = 0;
	int maxCount = 0;
	
	vector<int> actions;
	
	cin >> k;
	
	for(int i = 0; i < k; i++)
	{
		cin >> p;
		
		actions.push_back(--p);
	}
	
	BFS(actions[k - 1]);
	
	int prev;
	int curr;
	
	for(int i = 1; i < k; i++)
	{
		prev = actions[i - 1];
		curr = actions[i];
		
		if(distanceTo[curr] >= distanceTo[prev])
		{
			minCount++;
			maxCount++;
		}
		
		else
		{
			for(int child : bertown1[prev])
			{
				if((child != curr) && (distanceTo[child] == distanceTo[curr]))
				{
					maxCount++;
					
					break;
				}
			}
		}
	}
	
	cout << minCount << " " << maxCount << "\n";
}
	       			 	 	 	 	   	    	 		