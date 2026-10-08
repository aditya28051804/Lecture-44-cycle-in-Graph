#include<iostream>
 #include<string>
 #include<list>
 #include<queue>
 #include<vector>
using namespace std;
 
 class graph{
      
    int v;
    list<int>* adj;

    public:
    graph(int v){
        this->v = v;
        adj = new list<int> [v];
    }

    void addEdge(int v, int u){
         adj[u].push_back(v);
         adj[v].push_back(u);
    }

    void print(){
        for ( int i = 0; i < v; i++)
        {
              cout << i << "->";
              for(int neigh : adj[i]){
                cout << neigh <<" ";
              };
              cout << " " << endl;
        }
        
    }

    void helper(int u, vector<bool> &visited){
        visited[u] = true;
        cout << u << " ";
        list<int> neighbour = adj[u];

        for(int curr : neighbour )
             if (visited[curr] != true)
             {
                helper(curr, visited);

             }
             

    };
    void dfs(){
        vector<bool> visited(v ,false);
         helper(1 , visited);

    }

 };
 
 int main() {
             
    graph g(11);
g.addEdge(1, 2);
g.addEdge(1, 3);
g.addEdge(2, 4);
g.addEdge(2, 5);
g.addEdge(3, 6);
g.addEdge(3, 7);
g.addEdge(4, 8);
g.addEdge(5, 8);
g.addEdge(6, 9);
g.addEdge(7, 10);


    

    g.dfs();
 return 0;   
}