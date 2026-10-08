
// this is for non directed graphs 
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
bool helper(int scr , int par , vector<bool> &vis){
    vis[scr] = true;
    list<int> neighbour = adj[scr];
    for(int v : neighbour){
        if (vis[v] != true)
        {
            if (helper(v, scr, vis))
            {
                return true;
            }
            
        }
        else {
            if (v != par )
            {
                return true;
            }
            
        }
        
    }

}
    bool isCycle(){
        vector<bool> vis(v , false);
        return helper(0, -1, vis);

    };

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



    

    g.isCycle();
 return 0;   
}