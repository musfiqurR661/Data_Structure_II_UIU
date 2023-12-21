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

    // write code here
    void makeSet(vector<int> const &universe)
    {
        for (int i = 0; i < universe.size(); ++i)
        {
            int value = universe[i];
            parent[value] = value;
            rank[value] = 0;
        }
        //cout << makeSet(universe);
    }
      
    // Find the root of the set in which element `k` belongs
    int Find(int k)
    {
        // write code here
        if (parent[k] != k)
        {
            parent[k] = Find(parent[k]); 
        }

        return parent[k];
    }

    // Perform Union of two subsets
    void Union(int a, int b)
    {
        // code here
        int rootA = Find(a);
        int rootB = Find(b);

        if (rootA == rootB)
            return;

        if (rank[rootA] < rank[rootB])
        {
            parent[rootA] = rootB;
        }
        else if (rank[rootA] > rank[rootB])
        {
            parent[rootB] = rootA;
        }
        else
        {
            parent[rootB] = rootA;
            rank[rootA]++;
        }
        
   
    }
};

void printSets(vector<int> const &universe, DisjointSet &ds)
{
    for (int i : universe)
    {
        cout << ds.Find(i) << ' ';
    }
    cout << endl;
}

// Disjoint–Set data structure (Union–Find algorithm)
int main()
{
    int size;
    cout << "Enter the size of the universe vector: ";
    cin >> size;

    vector<int> universe(size);
    cout << "Enter " << size << " elements for the universe vector: ";
    for (int i = 0; i < size; ++i)
    {
        cin >> universe[i];
    }
    // initialize `DisjointSet` class
    DisjointSet ds;

    // create a singleton set for each element of the universe
    ds.makeSet(universe);
    printSets(universe, ds);

    ds.Union(4, 3); // 4 and 3 are in the same set
    printSets(universe, ds);

    ds.Union(2, 1); // 1 and 2 are in the same set
    printSets(universe, ds);

    ds.Union(1, 3); // 1, 2, 3, 4 are in the same set
    printSets(universe, ds);

    return 0;
}