#include <bits/stdc++.h>

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

        void setMark(int i, int val){
            marks[i] = val;
        }
        int getMark(int i){
            return marks[i];
        }

        void dijkstra(int s,int t, vector<int> &D){
            vector<int> P(n,-1);
            priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> H;
            for(int i = 0; i < n; i++){
                D[i] = MAX;
                setMark(i,0);
            }
            D[s] = 0;
            H.push(make_tuple(0,s,s));
            for(int i = 0; i < n; i++){
                int v,p;
                do{
                    if(H.empty()) return;
                    p = get<2>(H.top());
                    v = get<1>(H.top());
                    H.pop();   
                }while(getMark(v) == 1);
                if(v == t) return;
                setMark(v,1);
                P[v] = p;
                for(auto it : adjList[v]){
                    int w = it.first;
                    if(getMark(w) != 1 && D[w] > (D[v] + it.second)){ 
                        D[w] = D[v] + it.second;
                        P[w] = v;
                        H.push(make_tuple(D[w],w,v));
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
        vector<int> D(n);
        g.dijkstra(s,t,D);
        cout << "Case #" << i+1 << ": ";
        if(D[t] == MAX) cout << "unreachable"<< endl;
        else cout << D[t] << endl;
    }

    return 0;
}
