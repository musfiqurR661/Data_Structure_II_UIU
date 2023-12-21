/*
#include<bits/stdc++.h>

using namespace std;

int n_edge; // total edges
int n_vertex; // total vertices
int p[100],set_size[100];

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


int union_sets(int s1, int s2)
{
    int r1, r2;
    r1 = find_set(s1);
    r2 = find_set(s2);
    if (r1 == r2)
        return 0; /* already in same set */
/*    if (set_size[r1] >= set_size[r2])
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
    int i;
    //take the graph as input from the user
    //store the graph
    //sort the graph according to edge
    //make set

    for(i=0;i<n_edge;i++)
    {
        //union set if vertices not in same set
    }
    return 0;
}
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
 
// A class to represent a disjoint set
class DisjointSet
{
    unordered_map<int, int> parent;
 
    // stores the depth of trees
    unordered_map<int, int> rank;
 
public:
    // perform MakeSet operation
    void makeSet(vector<int> const &universe)
    {
        // create `n` disjoint sets (one for each item)
        for (int i: universe)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }
 
    // Find the root of the set in which element `k` belongs
    int Find(int k)
    {
        // if `k` is not the root
        if (parent[k] != k)
        {
            // path compression
            parent[k] = Find(parent[k]);
        }
 
        return parent[k];
    }
 
    // Perform Union of two subsets
    void Union(int a, int b)
    {
        // find the root of the sets in which elements `x` and `y` belongs
        int x = Find(a);
        int y = Find(b);
 
        // if `x` and `y` are present in the same set
        if (x == y) {
            return;
        }
 
        // Always attach a smaller depth tree under the root of the deeper tree.
        if (rank[x] > rank[y]) {
            parent[y] = x;
        }
        else {
            parent[x] = y;
        }
		
		if(rank[x]==rank[y]){
			rank[y]++;
		}
    }
};
 
void printSets(vector<int> const &universe, DisjointSet &ds)
{
    for (int i: universe) {
        cout << ds.Find(i) << ' ';
    }
    cout << endl;
}
 
// Disjoint–Set data structure (Union–Find algorithm)
int main()
{
    // universe of items
    vector<int> universe = { 1, 2, 3, 4, 5 };
 
    // initialize `DisjointSet` class
    DisjointSet ds;
 
    // create a singleton set for each element of the universe
    ds.makeSet(universe);
    printSets(universe, ds);
 
    ds.Union(4, 3);        // 4 and 3 are in the same set
    printSets(universe, ds);
 
    ds.Union(2, 1);        // 1 and 2 are in the same set
    printSets(universe, ds);
 
    ds.Union(1, 3);        // 1, 2, 3, 4 are in the same set
    printSets(universe, ds);
 
    return 0;
}