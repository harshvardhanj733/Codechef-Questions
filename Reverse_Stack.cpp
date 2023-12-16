void insertAtBottom(stack<int>& stack, int el){
    if(stack.empty()){
        stack.push(el);
        return;
    }

    int top = stack.top();
    stack.pop();
    insertAtBottom(stack, el);
    stack.push(top);
}

void reverseStack(stack<int> &stack) {
    // Write your code here
    if(stack.empty()){
        return;
    }

    int top = stack.top();
    stack.pop();
    reverseStack(stack);
    insertAtBottom(stack, top);
}

//TC: O(n^2);
//SC: O(n);