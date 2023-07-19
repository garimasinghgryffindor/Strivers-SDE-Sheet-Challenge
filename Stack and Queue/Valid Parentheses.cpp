bool isValidParenthesis(string s)
{
    stack<char> st;
    for(auto x: s) {
        if(x=='(' || x=='{' || x=='[') {
            st.push(x);
        } else {
            if(st.empty()) {
                return false;
            }
            if(st.top()=='(' && x==')' || st.top()=='[' && x==']' || st.top()=='{' && x=='}') {
                st.pop();
            } else {
                return false;
            }
        }
    }

    return st.empty();
}
