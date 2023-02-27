/*
 * @Author: jklash
 * @Description: 剑指 Offer 30. 包含min函数的栈
 * @Date: 2021-11-19 17:41:43
 * @LastEditors: jklash
 * @LastEditTime: 2021-11-21 13:14:29
 */
#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> s1, s2;
public:
    MinStack() {
       s2.push(INT32_MAX); 
    }
    
    void push(int x) {
        s1.push(x);
        s2.push(std::min(s2.top(), x));
    }
    
    void pop() {
        s1.pop();
        s2.pop();
    }
    
    int top() {
        return  s1.top();
    }
    
    int min() {
        return s2.top();
    }
};

int main(int argc, char const *argv[])
{
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.min() << endl;
    minStack.pop();
    cout << minStack.top() << endl;
    cout << minStack.min() << endl;

    return 0;
}
 