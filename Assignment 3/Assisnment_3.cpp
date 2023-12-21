#include<bits/stdc++.h>

using namespace std;

int n_edge, n_vertex, p[100],set_size[100];

void input(vector<pair<int, pair<int,int> > >* graph)
{
    int i,u,v,w;
   
    cin >> n_vertex;

    cin >> n_edge;
   
    for(i=0;i<n_edge;i++)
    {
        cin>>u>>v>>w;
       
        (*graph).push_back(make_pair(w,make_pair(u,v)));
    } 
    cout<<endl;
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
   
}

int union_sets(int s1, int s2)
{
    int r1, r2;
    r1 = find_set(s1);
    r2 = find_set(s2);
    if (r1 == r2)
        return 0; 
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
    int totalWeight=1;
   
    
    cout<<"Edges: \n";
    cout<<endl;
    for(i=0;i<n_edge;i++)
    {
        u = graph1[i].second.first;
        v = graph1[i].second.second;
        if(union_sets(u,v) != 0){
            cout<<u<<"--"<<v<<" "<<endl;
            totalWeight*=graph1[i].first;
           
        }  
    }
   cout<<"Minimum product: "<<totalWeight<<endl;
 
    return 0;
}

//input
/*
5 7
0 1 2
0 3 6
1 2 3
1 3 8
1 4 5
2 4 7
3 4 9
*/
//output
/*
Edges:
0—1
1—2
0—3
1—4
Minimum product: 180
*/