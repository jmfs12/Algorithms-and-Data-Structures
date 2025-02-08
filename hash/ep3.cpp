#include <iostream>
#include <utility>
#include <math.h>
#include <vector>

using namespace std;

class Dictionary{
    public:
        int m;
        int cnt;
        vector<pair<int, int>> table;
        int *perm;
    
    Dictionary(int m){
        this->m = m;
        this->cnt = 0;
        this->table.resize(m);
        for(int i = 0; i < m; i++)
            this->table[i].first = -1;
        this->perm = new int[m];
    }

    ~Dictionary(){
        delete[] perm;
    }

    int hash_function(int key){
        int temp = (int)floor(double(key)/double(this->m));
        return key - (this->m * temp);
    }

    int find(int key){
        int pos = hash_function(key);
        if(this->table[pos].first == key)
            return pos;
        else{
            int i = 0, newPos;
            do{
                newPos = (pos + this->perm[i]) % this->m; 
                i++;
                if(this->table[newPos].first == key)
                    return newPos; 
            }while(i < this->m-1);
            return -1;
        }
    }

    void insert(int key, int value){
        if(this->cnt < this->m && find(key) == -1){
            int pos = hash_function(key);
            if(this->table[pos].first != -1){
                int i = 0, newPos;
                do{
                    newPos = (pos + this->perm[i]) % this->m;
                    i++;
                }while(table[newPos].first != -1 && i < this->m-1);
                pos = newPos;
            }
            if(pos < this->m){
                table[pos].first = key;
                table[pos].second = value;
                cnt++;
            }
        }
        
    }
};


int main() {
    int n; cin >> n;
    do{
        Dictionary table(n);
        for(int i = 0; i < n-1; i++)
            cin >> table.perm[i];
        int clen; cin >> clen;

        for(int i = 0; i < clen; i++){
            string f; cin >> f;
            if(f == "add"){
                int key, num;
                cin >> key >> num;
                table.insert(key, num);
            }
            else if(f == "find"){
                int key; 
                cin >> key;
                int idx = table.find(key);
                if(idx != -1)
                    cout << idx << " " << table.table[idx].second << "\n";
                else cout << idx << "\n";

            }
        }
        cin >> n;
    }while(n > 0);
    
    return 0;
}