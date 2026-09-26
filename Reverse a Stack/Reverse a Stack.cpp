class Solution {
  public:
    void insert(stack<int> &st, int x){
        if(st.empty()){
            st.push(x);
            return;
        }

        int topElement = st.top();
        st.pop();

        insert(st, x);

        st.push(topElement);
    }
    void reverseStack(stack<int> &st) {
        if(st.empty()) 
            return;

        int x = st.top();
        st.pop();

        reverseStack(st);

        insert(st, x);
        
    }
};
