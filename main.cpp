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
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <stdlib.h>
#include <assert.h>


using namespace std;
static const int NoN=6;
int graph[NoN][NoN];

void addEdge(int src,int des,double weight)
{
    graph[src][des]=weight;
    graph[des][src]=weight;
}

int minimumDist(const double dist[], const bool IsVisited[])
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

double Dijkstra(int src,int des = -1)
{
    double DistFromSrc[NoN];
    bool IsVisited[NoN];
    
    for(int i = 0; i < NoN; i++)
    {
        DistFromSrc[i] = INT_MAX;
        IsVisited[i] = false;
    }

    DistFromSrc[src] = 0;          

    for(int i = 0; i < NoN; i++)
    {
        int m = minimumDist(DistFromSrc, IsVisited);
        IsVisited[m]=true;
        for(int j = 0; j < NoN; j++)
        {

            if(!IsVisited[j] && graph[m][j] && DistFromSrc[m] != INT_MAX && DistFromSrc[m] + graph[m][j] < DistFromSrc[j])
                DistFromSrc[j]= DistFromSrc[m] + graph[m][j];
        }
    }

    if(des!=-1) {
        return DistFromSrc[des];
    }
    else {
        return 0.0;
    }
}
//---------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------------------
int main() {
    char src[30];
    //Initialting Map done
    addEdge(0,18,2.5);
    addEdge(0,19,4.0);
    addEdge(0,16,6.6);
    addEdge(0,1,1.6);
    addEdge(16,1,6.8);
    addEdge(1,2,2.8);
    addEdge(2,3,0.65);
    addEdge(3,7,2.1);
    addEdge(3,4,2.9);
    addEdge(4,5,0.3);
    addEdge(4,6,2.9);
    addEdge(6,12,0.75);
    addEdge(12,13,2.5);
    addEdge(13,14,1.2);
    addEdge(13,15,3.1);
    addEdge(7,8,3.3);
    addEdge(8,9,1.3);
    addEdge(9,10,3.6);
    addEdge(10,7,1.4);
    addEdge(7,11,2.2);
    addEdge(11,10,2.3);
    addEdge(9,20,2.3);
    addEdge(20,18,3.5);
    addEdge(20,21,4.4);
    addEdge(21,22,5.3);
    addEdge(18,19,2.8);
    addEdge(19,17,4.3);
    cout<<"Initialting Map";
    //
    char Locations[23][30] = {"Gandhipuram", "VOC Park","Lakshmi mills", "Kidney Centre", "PSG Tech", "PSG Hospital",
                            "Hopes College", "Gem Hospital", "GH", "Railway Station", "Olympus", "Central Studio",
                            "CMC", "Sitra", "KMCH", "Nehru Nagar", "Uppilipalayam", "Cheran Nagar", "RS Puram",
                            "Saibaba Colony", "Ukkadam", "Kuniamuthur", "Kovaipudur"};
    for (int i = 0; i < 23; i++) {
        CodeToName.insert({i, Locations[i]});
    }
    for(int i = 0; i < 23;i++) {
        NameToCode.insert({Locations[i], i});
    }
    cout<<"Enter source:"<<endl;
    cin>>src;
    cout<<src;
    int CodeSrc=NameToCode[src];

    Dijkstra(CodeSrc);
    //vector<map<char*,double>> hospitaldistance(4);
    map<char*,double> hospitalsrc;

    hospitalsrc.insert(pair<char*,double>("CMC", Dijkstra(Kmch,Cmc)));
    hospitalsrc.insert(pair<char*,double>("GEM", Dijkstra(Kmch,Gem)));
    hospitalsrc.insert(pair<char*,double>("GH", Dijkstra(Kmch,Gh)));
    hospitalsrc.insert(pair<char*,double>("PSG", Dijkstra(Kmch,Psg)));
    map<char*,double>::iterator it;
    cout<<endl;
    for(it = hospitalsrc.begin(); it != hospitalsrc.end();++it)
        cout <<it ->second << endl;

    queue<Patient> gem_hospital,kmch_hospital,gh_hospital,psg_hospital;
    Patient p[20];






    return 0;
}
