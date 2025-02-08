#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class graph{
    public:
        vector<vector<int>> matrix;
        vector<int>count;
        int numEdges;
        int n;

        graph(int n){
            numEdges = 0;
            matrix.resize(n);
            for(int i = 0; i < n; i++){
                matrix[i].resize(n);
            }
            count.resize(n, 0);
            this->n = n;

        }

        void setEdgeDirected(int i, int j, int wt){
            if(wt <= 0) return;
            if(matrix[i][j] == 0){
                numEdges++;
            }
            matrix[i][j] = wt;
            count[j]++;
        }

        void toposort(priority_queue<int, vector<int>, greater<int>> *q, vector<int> *stack){
            if(q->size() > 0){
                int w = q->top();
                q->pop();
                stack->push_back(w);
                for(int i = 1; i < n; i++){
                    if(matrix[w][i] == 0) continue;
                    count[i]--;
                    if(count[i] == 0)
                        q->push(i);
                }
                toposort(q, stack);
            }
        }

        void graphTraverse(vector<int> *stack){
            priority_queue<int, vector<int>, greater<int>> q;
            for(int i = 1; i < n; i++){
                if(count[i] == 0){
                    q.push(i);
                }
            }
            toposort(&q, stack);
        }
};

int main(){
    int n, m;
    cin >> n >> m;
    graph g(n+1);
    int grau;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        g.setEdgeDirected(x, y, 1);
    }
    vector<int> stack;
    g.graphTraverse(&stack);
    if(stack.size() != n){
        cout << "Sandro fails.";
    }
    else{
        for(int i = 0; i < n; i++){
            cout << stack[i] << " ";
        }
    }
    cout << endl;

    return 0;
}