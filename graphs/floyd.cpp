#include <iostream>
#include <vector>
#include <list>

#define MAX (10000*50000)+1

using namespace std;

class graph{
    public:
        vector<list<pair<int,int>>> adjList;
        vector<int>marks;
        int numEdges;
        int n;

        graph(int n){
            numEdges = 0;
            adjList.resize(n);
            marks.resize(n, 0);
            this->n = n;
        }

        void setEdgeUnDirected(int i, int j, int wt){
            if(wt < 0){
                return;
            }
            adjList[i].push_back(make_pair(j,wt));
            adjList[j].push_back(make_pair(i,wt));
            numEdges++;

        }

        int weight(int i, int j){
            for(auto it = adjList[i].begin(); it != adjList[i].end(); it++){
                if(it->first == j){
                    return it->second;
                }
            }
            return 0;
        }

        void setMark(int i, int val){
            marks[i] = val;
        }
        int getMark(int i){
            return marks[i];
        }

        void floyd(vector<vector<int>> &D){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    int w = weight(i,j);
                    if(i == j) D[i][j] = 0;
                    else if(w != 0) D[i][j] = w;
                    else D[i][j] = MAX;
                }
            }
            for(int k = 0; k < n; k++){
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < n; j++){
                        if(D[i][k] != MAX && D[k][j] != MAX && D[i][j] > D[i][k] + D[k][j]){
                            D[i][j] = D[i][k] + D[k][j];
                        }
                    }
                }
            }
        }
};

int main(){
    int c; cin >> c;
    for(int i = 0; i < c; i++){
        int n,m,s,t; cin >> n >> m >> s >> t;
        graph g(n);
        for(int i = 0; i < m; i++){
            int v1,v2,w; cin >> v1 >> v2 >> w;
            g.setEdgeUnDirected(v1,v2,w);
        }
        vector<vector<int>> D(n);
        for(int i = 0; i < n; i++)
            D[i].resize(n);
        g.floyd(D);
        cout << "Case #" << i+1 << ": ";
        if(D[s][t] == MAX) cout << "unreachable"<< endl;
        else cout << D[s][t] << endl;
    }
    return 0;
}