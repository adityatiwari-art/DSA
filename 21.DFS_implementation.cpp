#include <iostream>
using namespace std;
int visited[7] = {0, 0, 0, 0, 0, 0, 0}; // visited nodes will set to 1
int a[7][7] = {
    // adjacency matrix
    {0, 1, 1, 1, 0, 0, 0}, // 0 node
    {1, 1, 0, 0, 0, 0, 0}, // 1 node
    {1, 1, 0, 1, 1, 0, 0}, // 2 node
    {1, 0, 1, 0, 0, 0, 0}, // 3 node
    {0, 0, 1, 1, 0, 1, 1}, // 4 node
    {0, 0, 0, 0, 1, 0, 0}, // 5 node
    {0, 0, 0, 0, 1, 0, 0}  // 6 node

};

void DFS(int i){
    cout<<i<<"\t";
    visited[i]=1;
    for(int j=0;j<7;j++){
        if(a[i][j]==1 && !visited[j]){    //checking for connceted edges && not visited are visited and if it fails then funtion return to old stack frame 
            DFS(j);
        }
    }
}

int main()
{
    int i = 3; // node to start with
    DFS(i);
}