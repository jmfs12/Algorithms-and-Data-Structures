#include <iostream>
#include <vector>
using namespace std;

class Dictionary{
    public:
        int m;
        int cnt;
        vector<string> hash;

        Dictionary(int m){
            this->m = m;
            this->cnt = 0;
            this->hash = vector<string>(m);
        }

        int fold(string k){
            int sum = 0;
            for(int i = 0; i < k.size(); i++)
                sum += k[i];
            return abs(sum) % m;
        }

        bool insert(string k){
            if(cnt == m) return false;
            int j = fold(k);
            while(hash[j].empty() == false){
                j = (j+1) % m;
                if(j == fold(k)){
                    return false;
                }
            }
            hash[j] = k;
            cnt++;
            return true;
        }

        int search(string k){
            int j = fold(k);
            while(hash[j] != k){
                j = (j+1) % m;
                if(j == fold(k)){
                    return -1;
                }
            }
            return j;

        }

        bool rmv(string k){
            int idx = search(k);
            if(idx == -1) return false;
            hash[idx].clear();
            return true;
        }

};


int main() {

    int m; cin >> m;
    Dictionary d(m);
    string f;
    do{
        cin >> f;
        if(f == "add"){
            string s; cin >> s;
            d.insert(s);
        }
        else if(f == "rmv"){
            string s; cin >> s;
            d.rmv(s);
        }
        else if(f == "sch"){
            string s; cin >> s;
            int idx = d.search(s);

            cout << s << " " << idx << endl;

        }   
    }while(f != "fim");

    return 0;
}
