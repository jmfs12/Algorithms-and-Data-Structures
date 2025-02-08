#include <iostream>
#include <vector>

using namespace std;

class node{
    public:
        int key;
        int height;
        node *left;
        node *right;
        int rank;

        node(int key){
            this->key = key;
            left = right = NULL;
            height = -1;
            rank = 1;
        }
};

class bst{
    public:
        int len;
        node *root;
    
    bst(){
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
        if (balance > 1 && key >= rt->left->key) { 
            rt->left = leftRotate(rt->left); 
            return rightRotate(rt); 
        }
        if(balance < -1 && key < rt->right->key){
            rt->right = rightRotate(rt->right);
            return leftRotate(rt);
        }
        return rt;
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

    bst tree;
    int n; cin >> n;
    for (int i = 0;i < n; i++){
        int f; cin >> f;
        if(f == 1){
            int key; cin >> key;
            tree.insert(key);
        }
        else if (f == 2){
            int key; cin >> key;
            int count = 1;
            int index = tree.countIdx(tree.root, key);
            if(index != -1)
                cout << index << endl;
            else
                cout << "Data tidak ada" << endl;
        }
    }
    return 0;
}