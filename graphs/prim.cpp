#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
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
            numEdges++;

        }

        void setMark(int i, int val){
            marks[i] = val;
        }
        int getMark(int i){
            return marks[i];
        }

        void prim(vector<int> &D, vector<int> V){
            vector<int> P(n,-1);
            priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> H;
            for(int i = 0; i < n; i++){
                D[i] = MAX; V[i] = -1;
                setMark(i,0);
            }
            D[0] = 0;
            H.push(make_tuple(0,0,0));
            for(int i = 0; i < n; i++){
                int v,p;
                do{
                    if(H.empty()) return;
                    p = get<2>(H.top());
                    v = get<1>(H.top());
                    H.pop();   
                }while(getMark(v) == 1);
                setMark(v,1);
                V[v] = p;
                for(auto it : adjList[v]){
                    int w = it.first;
                    if(getMark(w) != 1 && D[w] > it.second){ 
                        D[w] = it.second;
                        H.push(make_tuple(D[w],w,v));
                    }
                }
            }
        }
};

int main(){
    int c; cin >> c;
    while(1){
        int n,m; cin >> n >> m;
        if(!n && !m) break;
        graph g(n);
        for(int i = 0; i < m; i++){
            int v1,v2,w; cin >> v1 >> v2 >> w;
            g.setEdgeUnDirected(v1,v2,w);
        }
        vector<int> D(n);
        vector<int> V(n);
        g.prim(D, V);
        if(D[n-1] == MAX) cout << "IMPOSSIBLE"<< endl;
        else cout << D[n-1] << endl;
    }

    return 0;
}