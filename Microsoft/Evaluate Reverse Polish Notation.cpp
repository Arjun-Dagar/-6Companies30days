class Solution {
public:
    
    inline bool operate(string s)
    {
        return (s == "+" || s == "-" || s == "*" || s == "/") ? true : false;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        for(int i=0; i<tokens.size(); i++)
        {
            if(operate(tokens[i]))
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                
                int c;
                if(tokens[i] == "+")
                    c = a+b;
                else if(tokens[i] == "-")
                    c = b-a;
                else if(tokens[i] == "*")
                    c = a*b;
                else
                    c = b/a;
                
                st.push(c);
            }
            else
            {
                st.push(stoi(tokens[i]));
            }
        }
        
        return st.top();
    }
};