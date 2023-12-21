#include<bits/stdc++.h>

using namespace std;

int main()
{
    return 0;
}


/*
int main()
{
    int i,u,v,w,n_edge,n_vertex;
    vector<pair<int, pair<int,int> > > graph;

    cout<<"Enter Number of Edges : \n";
    cin>>n_edge;

    cout<<"Enter Number of Vertices : \n";
    cin>>n_vertex;


    cout<<"Enter the graph : \n"; //input graph
    for(i=0;i<n_edge;i++)
    {
        cin>>u>>v>>w;
        graph.push_back(make_pair(w,make_pair(u,v)));
    }

    sort(graph.begin(),graph.end()); //sort

    cout<<"The graph\n"; //print graph
    for(i=0;i<n_edge;i++)
    {
        cout<<"<"<<graph[i].second.first<<","<<graph[i].second.second<<"> --> "<<graph[i].first<<'\n';
    }


    return 0;
}*/

/* Sample input 1:
edge = 6
vertex = 6
0 1 6
1 2 10
2 1 11
2 3 8
3 4 5
1 5 9
*/
/* Sample input 2:
edge = 5
vertex = 3
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4
*/
