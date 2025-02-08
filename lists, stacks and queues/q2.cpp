#include <iostream>
using namespace std;

class link{
    public:
        char elem;
        link* next;
    
    link(){
        next = NULL;
    }

};

class stack{
    public: 
        link *top;
        int cnt;
    
        stack(){
            top = NULL;
            cnt = 0;
        }

        ~stack(){
            delete top;
        }

        void push(char c){
            link *temp = new link;
            temp->elem = c;
            temp->next = top;
            top = temp;
            cnt++;
        }

        char pop(){
            if(top == NULL)
                return '\0';
            char c = top->elem;
            link *temp = top;
            top = top->next;

            delete temp;

            cnt--;
            return c;
        }
        
};

int main(){
    string s; cin >> s;
    stack st;

    for(int i = 0; i < s.length(); i++){
        st.push(s[i]);
        if(st.cnt >= 3){
            char c = st.pop();
            char b = st.pop();
            char a = st.pop();
            if(a != 'A' || b != 'B' || c != 'C'){
                st.push(a);
                st.push(b);
                st.push(c);
            }
        }
    }
    stack st2;
    while(st.cnt > 0)
        st2.push(st.pop());
    while(st2.cnt > 0)
        cout << st2.pop();

    return 0;
}