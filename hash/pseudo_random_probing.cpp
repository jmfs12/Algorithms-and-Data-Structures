#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class hashing {
    public:
        int m;
        int cnt;
        vector <pair<string,string>> hash;
        int *perm;

        hashing(int m) {
            this->m = m;
            this->cnt = 0;
            this->hash = vector <pair<string,string>>(m);
            perm = new int[m-1];
        }

        int hash_function(string k) {
            int sum = 0;
            for(int i = 0; i < k.size(); i++) {
                sum += k[i] - '0';
            }
            return abs(sum) % m;
        }

        int find(string key){
            int pos = hash_function(key);
            if(hash[pos].second == key){
                return pos;
            }
            int i = 0, new_pos;
            do{
                int offset = perm[i];
                new_pos = (pos + offset)%m;
                if(hash[new_pos].second == key){
                    return new_pos;
                }
                i++;
            }while(i < m-1);

            return -1;
        }

        void insert(pair<string,string> key){
            if(cnt < m && find(key.second) == -1){
                int pos = hash_function(key.second);
                if(hash[pos].second.empty() != true){
                    int i = 0;
                    int new_pos;
                    do{
                        int offset = perm[i];
                        new_pos = (pos + offset) % m;
                        i++;
                    }while(hash[new_pos].second.empty() != true && i < m-1);
                    pos = new_pos;
                }
                if(hash[pos].second.empty() == true){
                    hash[pos] = key;
                    cnt++;
                }
            }
        }
};

int main() {
    int n; cin >> n;
    hashing h(n);
    for(int i = 0; i < n-1; i++){
        cin >> h.perm[i];
    }
    int cnum; cin >> cnum;

    for(int i = 0; i < cnum; i++){
        string f; cin >> f;
        if(f == "add"){
            pair<string,string> p;
            cin >> p.first >> p.second;
            h.insert(p);
        }
        else if(f == "find"){
            string key; cin >> key;
            int pos = h.find(key);
            if(pos != -1) cout << h.hash[pos].first << " " << pos << endl;
            else cout << pos << endl;
        }
    }

    delete [] h.perm;

    return 0;
}