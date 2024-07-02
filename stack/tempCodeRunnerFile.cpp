class CustomStack {
    private:
        stack<int> numStack;
        stack<int> minStack;

    public: 
        void push(int value){
            if(numStack.empty() || value < minStack.top()) minStack.push(value);
            numStack.push(value);
        }

        int pop(){
            if(numStack.empty()) return -1;
            int value = numStack.top();
            if(value == minStack.top()) minStack.pop();
            numStack.pop();
            return value;
        }

        int getMin(){
            if(minStack.empty()) return -1;
            else return minStack.top();
        }
};