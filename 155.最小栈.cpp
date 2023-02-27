/*
 * @Author: jklash
 * @Description: 最小栈
 * @Date: 2021-11-19 17:53:01
 * @LastEditors: jklash
 * @LastEditTime: 2021-11-19 18:06:52
 */
/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */
#include <iostream>
#include <stack>
using namespace std;
// @lc code=start
class MinStack {
private:
    stack<int> stk ,minStk;

public:
    MinStack() {
        minStk.push(INT32_MAX);
    }
    
    void push(int val) {
        stk.push(val);
        minStk.push(min(minStk.top(), val));
    }
    
    void pop() {
        stk.pop();
        minStk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minStk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

int main(int argc, char const *argv[])
{
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << endl;; 
    minStack.pop();
    cout << minStack.top() << endl; 
    cout << minStack.getMin() << endl;

    return 0;
}
