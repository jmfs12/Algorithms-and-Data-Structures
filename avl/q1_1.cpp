#include <iostream>

using namespace std;

struct node{ 
    int key;
    int height;
    int rank;
    node *left;
    node *right;

    node(int key){
        this->key = key;
        height = -1;
        rank = 1;
        left = right = NULL;
    }
};

class avl{
    public:
        int len;
        node *root;
    
    avl(){
        len = 0;
        root = NULL;
    }

    int h(node *rt){
        if(rt == NULL) return -1;
        return rt->height;
    }
    
    int getBalance(node *rt){
        if(rt == NULL) return 0;
        return h(rt->left) - h(rt->right);
    }

    int find(int key){
        return findHelp(root, key);
    }

    int findHelp(node *rt, int key){
        if(rt == NULL){
            return -1;
        }
        if(rt->key == key){
            return rt->key;
        }
        else if(rt->key > key){
            return findHelp(rt->left, key);
        }
        else{
            return findHelp(rt->right, key);
        }
    }

    node *rightRotate(node *rt){
        rt->rank -= rt->left->rank;

        node *l = rt->left;
        node *lr = l->right;

        l->right = rt;
        rt->left = lr;

        rt->height = max(h(rt->left), h(rt->right)) + 1;
        l->height = max(h(l->left), h(l->right)) + 1;
        return l;
    }

    node *leftRotate(node *rt){
        rt->right->rank++;

        node *r = rt->right;
        node *rl = r->left;

        r->left = rt;
        rt->right = rl;
          
        rt->height = max(h(rt->left), h(rt->right)) + 1;
        r->height = max(h(r->left), h(r->right)) + 1;
        return r;
    }

    void insert(int key){
        root = inserthelp(root, key);
        len++;
    }

    node *inserthelp(node *rt, int key){
        if(rt == NULL) return rt = new node(key);
        if(rt->key > key) {
            rt->rank++;
            rt->left = inserthelp(rt->left, key);
        }
        else rt->right = inserthelp(rt->right, key);

        rt->height = 1 + max(h(rt->left), h(rt->right));

        int balance = getBalance(rt);
        if (balance < -1 && key >= rt->right->key) return leftRotate(rt);
        if (balance > 1 && key < rt->left->key) return rightRotate(rt);
        if (balance > 1 && key >= rt->left->key){ 
            rt->left = leftRotate(rt->left); 
            return rightRotate(rt); 
        }
        if(balance < -1 && key < rt->right->key){
            rt->right = rightRotate(rt->right);
            return leftRotate(rt);
        }
        return rt;
    }

    int countIdx(node *rt, int key){
        if(rt == NULL || find(key) == -1) return -1;
        int idx = 0;
        while(rt != NULL){
            if(rt->key == key){
                idx += rt->rank;
                break;
            }
            else if(rt->key > key){
                rt = rt->left;
            }
            else{
                idx += rt->rank;
                rt = rt->right;
            }
        }
        return idx;
    }


};

int main(){

    int Q; cin >> Q;
    avl tree;
    while(Q--){
        int f; cin >> f;
        if(f == 1){
            int x; cin >> x;
            tree.insert(x);
        }
        else if(f == 2){

            int x; cin >> x;
            int idx = tree.countIdx(tree.root, x);
            if(idx == -1) cout << "Data tidak ada" << endl;
            else cout << idx << endl;
        }
    }

    return 0;
}