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
#include "Patient.h"
#include "Covid.h"
#include<bits/stdc++.h>

using namespace std;

static const int NoN=23;
double graph[NoN][NoN];
const int Kmch=14;
const int Gem=7;
const int Cmc=12;
const int Psg=5;
const int Gh=8;
vector<pair<char*, double> > A;

void addEdge(int src,int des,double weight)
{
    graph[src][des]=weight;
    graph[des][src]=weight;

}

int minKeyVal(const double dist[], const bool IsVisited[])
{int min=INT_MAX,index;
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
//

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
        int m = minKeyVal(DistFromSrc, IsVisited);
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







bool cmp(pair<char*, double>& a,
         pair<char*, double>& b)
{
    return a.second < b.second;
}


void sort(map<char*, double>& M)
{





    for (auto& it : M) {
        A.push_back(it);
    }


    sort(A.begin(), A.end(), cmp);




}
//---------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------------------
int main() {
    map<int, char *> CodeToName;
    map<char *, int> NameToCode;
    char src[30];
    //Initialising Map done
    addEdge(0, 18, 2.5);
    addEdge(0, 19, 4.0);
    addEdge(0, 16, 6.6);
    addEdge(0, 1, 1.6);
    addEdge(16, 1, 6.8);
    addEdge(1, 2, 2.8);
    addEdge(2, 3, 0.65);
    addEdge(3, 7, 2.1);
    addEdge(3, 4, 2.9);
    addEdge(4, 5, 0.3);
    addEdge(4, 6, 2.9);
    addEdge(6, 12, 0.75);
    addEdge(12, 13, 2.5);
    addEdge(13, 14, 1.2);
    addEdge(13, 15, 3.1);
    addEdge(7, 8, 3.3);
    addEdge(8, 9, 1.3);
    addEdge(9, 10, 3.6);
    addEdge(10, 7, 1.4);
    addEdge(7, 11, 2.2);
    addEdge(11, 10, 2.3);
    addEdge(9, 20, 2.3);
    addEdge(20, 18, 3.5);
    addEdge(20, 21, 4.4);
    addEdge(21, 22, 5.3);
    addEdge(18, 19, 2.8);
    addEdge(19, 17, 4.3);
    cout << "Initialting Map";
    //
    char Locations[23][30] = {"Gandhipuram", "VOC Park", "Lakshmi mills", "Kidney Centre", "PSG Tech", "PSG Hospital",
                              "Hopes College", "Gem Hospital", "GH", "Railway Station", "Olympus", "Central Studio",
                              "CMC", "Sitra", "KMCH", "Nehru Nagar", "Uppilipalayam", "Cheran Nagar", "RS Puram",
                              "Saibaba Colony", "Ukkadam", "Kuniamuthur", "Kovaipudur"};
    for (int i = 0; i < 23; i++) {
        CodeToName.insert(pair<int, char *>(i, Locations[i]));
    }
    for (int i = 0; i < 23; i++) {
        NameToCode.insert(pair<char *, int>(Locations[i], i));
    }

    cout << "Enter source:" << endl;
    cin >> src;
    cout << src;
    int CodeSrc = NameToCode[src];

    Dijkstra(CodeSrc);

    map<char *, double> hospitalsrc;

    hospitalsrc.insert(pair<char *, double>("CMC", Dijkstra(Kmch, Cmc)));
    hospitalsrc.insert(pair<char *, double>("GEM", Dijkstra(Kmch, Gem)));
    hospitalsrc.insert(pair<char *, double>("GH", Dijkstra(Kmch, Gh)));
    hospitalsrc.insert(pair<char *, double>("PSG", Dijkstra(Kmch, Psg)));

    cout << endl;
    sort(hospitalsrc);
    for (auto &i: A) {
        cout << i.first << " " << i.second << endl;
    }

    queue<Patient> gem_hospital, kmch_hospital, gh_hospital, psg_hospital, cmc_hospital;
    Patient p[20];
    Covid h[20];
    char pname[20][30] = {"Juras", "Lakshmi Ramesh", "Sahesh Mai", "Saran", "Amirab", "Hairsh",
                          "Akhilesh", "Janom", "Nohan Sair", "Pairam Sandu", "Chintu",
                          "Jengarar", "Tharash", "lithim", "Neghamarshan", "avoorpa",
                          "Murthick", "Selvan Thiru", "Metanya Chiglani", "Dutkarsh Ved"};

    double score[20][3] = {{9.5,   8.12,  9.1},
                           {9.5,   9.6,   9.8},
                           {8.3,   2.5,   4.8},
                           {7,     4.2,   8.4},
                           {9.6,   8.2,   4.7},
                           {0.7,   7.3,   9.1},
                           {9.87,  8.9,   2.1},
                           {0.0,   2.230, 2.0},
                           {15.0,  6.5,   11.0},
                           {2.0,   9.0,   1.0},
                           {9.0,   3.0,   7.0},
                           {7.0,   7.0,   8.0},
                           {9.50,  10.0,  13.40},
                           {9.5,   12.7,  10.2},
                           {7.3,   0.5,   3.5},
                           {1.003, 2.002, 3.54},
                           {12.5,  10.5,  13.3},
                           {1.019, 2.451, 13.8},
                           {1.9,   2.7,   3.47},
                           {1.4,   2.1,   3.9}};

    for (int i = 0; i < 20; i++) {
        h[i].setsymp(score[i]);
        h[i].calcavg();
        h[i].findSeverity();
    }

    for (int i = 0; i < 20; i++) {
        p[i] = Patient(pname[i], h[i]);
    }
    for (int i = 0; i < 20; i++) {
        if (i < 5)
            kmch_hospital.push(p[i]);
        else {
            if (i >= 5 && i <= 9) {
                if (A.at(1).first == "CMC")
                    cmc_hospital.push(p[i]);
                else if (A.at(1).first == "GEM")
                    gem_hospital.push(p[i]);
                else if (A.at(1).first == "GH")
                    gh_hospital.push(p[i]);
                else if (A.at(1).first == "PSG")
                    psg_hospital.push(p[i]);
            } else if (i >= 10 && i <= 14) {
                if (A.at(2).first == "CMC")
                    cmc_hospital.push(p[i]);
                else if (A.at(2).first == "GEM")
                    gem_hospital.push(p[i]);
                else if (A.at(2).first == "GH")
                    gh_hospital.push(p[i]);
                else if (A.at(2).first == "PSG")
                    psg_hospital.push(p[i]);
            } else {
                if (A.at(3).first == "CMC")
                    cmc_hospital.push(p[i]);
                else if (A.at(3).first == "GEM")
                    gem_hospital.push(p[i]);
                else if (A.at(3).first == "GH")
                    gh_hospital.push(p[i]);
                else if (A.at(3).first == "PSG")
                    psg_hospital.push(p[i]);
            }
        }
    }

    cout << "\n" << score[0][0] << endl;
    cout << "\n" << h[1].getSymptomavg();
    cout << "\n" << h[1].getSeverity();
    cout << "\n" << p[1].getPname() << p[1].getcovid().getSymptomavg();

    char covidLocations[5][30] = {"Ukkadam", "Gem Hospital", "Hopes College", "Cheran Nagar", "VOC Park"};
    fflush(stdin);
    cout << "\n\nEnter a location in Coimbatore";
    char testLocation[30];
    gets(testLocation);
    map<char*,int>::iterator it;
    int testIndex;
    vector<int> covidIndices;
    for(it = NameToCode.begin();it != NameToCode.end();++it)
    {
        if(!strcmpi(it->first,testLocation))
            testIndex = it -> second;
        else if(!strcmp(it -> first,"Ukkadam"))
            covidIndices.push_back(it->second);
        else if(!strcmp(it->first,"Gem Hospital"))
            covidIndices.push_back(it -> second);
        else if(!strcmp(it -> first,"Hopes College"))
            covidIndices.push_back(it -> second);
        else if(!strcmp(it -> first,"Cheran Nagar"))
            covidIndices.push_back(it -> second);
        else if(!strcmp(it -> first,"VOC Park"))
            covidIndices.push_back(it -> second);

    }

    const double redzone = 5.0;
    int count = 0;
    for(int i = 0; i < covidIndices.size();i++) {
        if (Dijkstra(testIndex, covidIndices.at(i)) < redzone)
            count++;

    }


    if(count > 0)
        cout << "\nCOVID RISK AREA";
    else
        cout << "\nSAFE AREA";



  return 0;
}