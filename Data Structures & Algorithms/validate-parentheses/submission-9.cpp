class Solution {
public:
    bool isValid(string s) {
        stack<char> myStack;
        
        for(char c:s){

            if(c == '(' || c == '{' || c == '['){
                myStack.push(c);
            }


            if(c == ')'){
                if (myStack.empty() || myStack.top() != '(')
                    return false;
                myStack.pop();
            }else if(c == '}'){
                if (myStack.empty() || myStack.top() != '{')
                    return false;
                myStack.pop();
            }else if(c == ']' ){
                if (myStack.empty() || myStack.top() != '[')
                    return false;
                myStack.pop();
            }

        }
        return myStack.empty();
    }
};
