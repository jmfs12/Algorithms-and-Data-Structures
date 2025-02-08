#include <iostream>
#include <vector>

using namespace std;

class Dictionary{
    public:
        int m;
        int cnt;
        vector<vector<int>> hash;

        int hashFunc(int key){
            return key % 10;
        }

        Dictionary(int m){
            this->m = m;
            this->cnt = 0;
            this->hash = vector<vector<int>>(10);
        }
        
        bool find(int key){
            int index = hashFunc(key);
            for(int i = 0; i < hash[index].size(); i++){
                if(hash[index][i] == key){
                    return true;
                }
            }
            return false;
        }

        void insert(int key){
            if(find(key) == false){
                int index = hashFunc(key);
                hash[index].push_back(key);
                cnt++;
            }
        }


};

void print_hash(Dictionary d){
    for(int i = 0; i < d.hash.size(); i++){
        cout << i << " ";
        for(int j = 0; j < d.hash[i].size(); j++){
            cout << d.hash[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{

    int n;
    cin >> n;
    Dictionary d(n); 
    for(int i = 0; i < n; i++){
        int key;
        cin >> key;
        d.insert(key);
    }

    print_hash(d);


    return 0;
}
