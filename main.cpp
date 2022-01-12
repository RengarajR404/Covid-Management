#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>


using namespace std;
static const int NoN=6;
int graph[NoN][NoN];

void addEdge(int src,int des,int weight)
{
    graph[src][des]=weight;
    graph[des][src]=weight;
}

int minimumDist(const int dist[], const bool IsVisited[])
{
    int min=INT_MAX,index;

    for(int i=0; i < NoN; i++)
    {
        if(!IsVisited[i] && dist[i] <= min)
        {
            min=dist[i];
            index=i;
        }
    }
    return index;
}

void Dijkstra(int src)
{
    int DistFromSrc[NoN];
    bool IsVisited[NoN];
    
    for(int i = 0; i < NoN; i++)
    {
        DistFromSrc[i] = INT_MAX;
        IsVisited[i] = false;
    }

    DistFromSrc[src] = 0;          

    for(int i = 0; i < NoN; i++)
    {
        int m=minimumDist(DistFromSrc, IsVisited);
        IsVisited[m]=true;
        for(int j = 0; j < NoN; j++)
        {

            if(!IsVisited[j] && graph[m][j] && DistFromSrc[m] != INT_MAX && DistFromSrc[m] + graph[m][j] < DistFromSrc[j])
                DistFromSrc[j]= DistFromSrc[m] + graph[m][j];
        }
    }
    cout<<"Vertex\t\tDistance from source"<<endl;
    for(int i = 0; i < NoN; i++)
    { //Printing
        char str=65+i;
        cout << str << "\t\t\t" << DistFromSrc[i] << endl;
    }
}

int main()
{


}
