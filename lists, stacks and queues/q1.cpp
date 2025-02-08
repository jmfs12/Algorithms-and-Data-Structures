#include <iostream>
using namespace std;

struct Link {
    string data;
    Link* next;

    Link(){
    }

    Link(Link *nextval){
        next = nextval;
    }

    Link(string value, Link *nextval){
        data = value;
        next = nextval;
    }
};

class List {

    public:

        Link* tail;
        Link* head;
        Link* curr;
        
        List() {
            head = tail = curr = new Link(NULL);
        }

        void insert(string value) {
            curr->next = new Link(value, curr->next);
            if(tail == curr)
                tail = curr->next;
        }

        void moveToStart() {
            curr = head;
        }

        void moveToEnd() {
            curr = tail;
        }

        void print() {
            Link* temp = head;
            while (temp != NULL) {
                cout << temp->data;
                temp = temp->next;
            }
            cout << endl;
        }
};

void ans(string s){
    List list;
    string s2;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '['){
            if (!s2.empty()) {
                list.insert(s2);
                s2.clear();
            }
            list.moveToStart();
        }else if(s[i] == ']'){
            if (!s2.empty()) {
                list.insert(s2);
                s2.clear();
                list.moveToEnd();
            }
        }else{
            s2 += s[i];
        }
    }
    if (!s2.empty()) 
        list.insert(s2);
        
    list.print();   
}

int main(){

    string s;
    while(!cin.eof()){
        cin >> s;
        ans(s);
    }

    return 0;
}

