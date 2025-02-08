#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class graph{
    public:
        vector<vector<int>> matrix;
        vector<int>marks;
        int numEdges;
        int n;

        graph(int n){
            numEdges = 0;
            matrix.resize(n);
            for(int i = 0; i < n; i++){
                matrix[i].resize(n);
            }
            marks.resize(n, 0);
            this->n = n;
        }

        int first(int v){
            for(int i = 0; i < n; i++){
                if(matrix[v][i] != 0){
                    return i;
                }
            }
            return n;
        }

        int next(int v, int w){
            for(int i = w + 1; i < n; i++){
                if(matrix[v][i] != 0){
                    return i;
                }
            }
            return n;
        }

        void setEdgeDirected(int i, int j, int wt){
            if(wt <= 0){
                std::cout << "Illegal weight value" << std::endl;
                return;
            }
            if(matrix[i][j] == 0){
                numEdges++;
            }
            matrix[i][j] = wt;
        }

        void setEdgeUnDirected(int i, int j, int wt){
            if(wt <= 0){
                std::cout << "Illegal weight value" << std::endl;
                return;
            }
            if(matrix[i][j] == 0){
                numEdges++;
            }
            matrix[i][j] = wt;
            matrix[j][i] = wt;
        }

        void delEdgeDirected(int i, int j){
            if(matrix[i][j] != 0){
                numEdges--;
            }
            matrix[i][j] = 0;
        }

        void delEdgeUnDirected(int i, int j){
            if(matrix[i][j] != 0){
                numEdges--;
            }
            matrix[i][j] = 0;
            matrix[j][i] = 0;
        }

        int e(){
            return numEdges;
        }
        bool isEdge(int i, int j){
            return matrix[i][j] != 0;
        }
        int weight(int i, int j){
            return matrix[i][j];
        }
        void setMark(int i, int val){
            marks[i] = val;
        }
        int getMark(int i){
            return marks[i];
        }

        void dfs(int v){
            cout << v << " ";
            setMark(v, 1);
            int w = first(v);
            while(w < n){
                if(getMark(w) == 0){
                    dfs(w);
                }
                w = next(v, w);
            }
        }
        
        void bfs(int start){
            queue <int> q;
            q.push(start);
            setMark(start, 1);
            while(q.size() > 0){
                int v = q.front(); q.pop();
                cout << v << " ";
                int w = first(v);
                while(w < n){
                    if(getMark(w) == 0){
                        setMark(w, 1);
                        q.push(w);
                    }
                    w = next(v, w);
                }
            }
        }

        void graphTraverse(vector<int> *stack){
            for(int v = 0; v < n; v++){
                setMark(v, 0);
            }
            for(int v = 0; v < n; v++){
                if(getMark(v) == 0){
                    toposort(v, stack);
                }
            }
        }

        void toposort(int v, vector<int> *stack){
            setMark(v, 1);
            int w = first(v);
            while(w < this->n){
                if(getMark(w) == 0)
                    toposort(w, stack);
                w = next(v, w);
            }
            stack->push_back(v);
        }
};

int main(){

    int n, q;
    cin >> n >> q;
    graph grafo(n+1);
    for(int i = 0; i < q; i++){
        int a, b; cin >> a >> b;
        grafo.setEdgeDirected(a, b, 1);
    }
    vector<int> stack;
    grafo.toposort(0, &stack);
    while(stack.empty() == false){
        cout << stack.back() << " ";
        stack.pop_back();
    }
    cout << endl;

    return 0;
}