#include<bits/stdc++.h>

using namespace std;

int n_edge, n_vertex, p[100],set_size[100];

void input(vector<pair<int, pair<int,int> > >* graph)
{
    int i,u,v,w;
    cout<<"Enter Number of Vertices : \n";
    cin >> n_vertex;
    cout<<"Enter Number of Edges : \n";
    cin >> n_edge;
    cout<<"Enter the graph : \n";
    for(i=0;i<n_edge;i++)
    {
        cin>>u>>v>>w;
        (*graph).push_back(make_pair(w,make_pair(u,v)));
    }
}

void make_set()
{
    int i;
    for (i=0; i<n_vertex; i++)
    {
        p[i] = i;
        set_size[i] = 1;
    }
}

int find_set(int x)
{
    if (p[x] == x)
        return(x);
    else
        return(find_set(p[x]));
}


void sort_E(vector<pair<int, pair<int,int> > >* graph)
{
    int i;
    sort((*graph).begin(),(*graph).end());
    cout << "Sorted Graph according to the Edges : \n";
    for(i=0;i<n_edge;i++)
    {
        cout<<"<"<<(*graph)[i].second.first<<","<<(*graph)[i].second.second<<"> --> "<<(*graph)[i].first<<'\n';
    }
    cout<<'\n';
}

int union_sets(int s1, int s2)
{
    int r1, r2;
    r1 = find_set(s1);
    r2 = find_set(s2);
    if (r1 == r2)
        return 0; /* already in same set */
    if (set_size[r1] >= set_size[r2])
    {
        set_size[r1] = set_size[r1] + set_size[r2];
        p[r2] = r1;
    }
    else {
        p[r1] = r2;
    }
    return 1;
}

int main()
{

    vector<pair<int, pair<int,int> > > graph1;

    input(&graph1);
    sort_E(&graph1);
    make_set();

    int i,u,v;
    cout<<"Minimum Spanning Tree : \n";
    for(i=0;i<n_edge;i++)
    {
        u = graph1[i].second.first;
        v = graph1[i].second.second;
        if(union_sets(u,v) != 0)
            cout<<"<"<<u<<","<<v<<"> --> "<<graph1[i].first<<'\n';

    }
    return 0;
}


// Pseudocode ok Kruskal :
/*
for each vertex v ∈ V
    Make-Set(v)
sort E into nondecreasing order by weight w for each (u, v) taken from the sorted list
if Find-Set(u)
    Find-Set(v) A ← A ∪ (u, v)
Union(u, v)
*/

/* Sample input 1:
vertex = 10
edge = 14
0 1 10
0 2 12
1 2 9
1 3 8
2 4 3
2 5 1
3 4 7
3 6 8
3 7 5
4 5 3
5 7 6
6 7 9
6 8 2
7 8 11
*/
/* Sample input 2:
vertex = 4
edge = 5
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4
*/

