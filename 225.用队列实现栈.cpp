/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */
#include <iostream>
#include <queue>
using namespace std;
// @lc code=start
class MyStack {
private:
    queue<int> q1, q2;

public:
    MyStack() {

    }
    
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    
    int pop() {
        int ans = q1.front();
        q1.pop();
        return ans;
    }
    
    int top() {
        return  q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

int main(int argc, char const *argv[])
{
    MyStack myStack;
    myStack.push(1);
    myStack.push(2);
    cout << myStack.top() <<endl; // 返回 2
    cout << myStack.pop() << endl; // 返回 2
    cout << myStack.empty() << endl; // 返回 False

    return 0;
}
