/*
 * @Author: jklash
 * @Description: 用栈实现队列
 * @Date: 2021-11-19 10:47:40
 * @LastEditors: jklash
 * @LastEditTime: 2021-11-22 15:51:10
 */
/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */
#include <iostream>
#include <stack>
using namespace std;
// @lc code=start
class MyQueue {
private:
    stack<int> in, out;
    void in2out() {
        while (!in.empty()) {
            out.push(in.top());
            in.pop();
        }
    }

public:

    MyQueue() {
        
    }
    
    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        if (out.empty()) {
            in2out();
        }
        int p = out.top();
        out.pop();
        return p;
    }
    
    int peek() {
        if (out.empty()) {
            in2out();
        }
        return out.top();
    }
    
    bool empty() {
        return in.empty() && out.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

int main(int argc, char const *argv[])
{
    MyQueue q;
    q.push(1); // queue is: [1]
    q.push(2); // queue is: [1, 2] (leftmost is front of the queue)
    cout << q.peek() << endl; // return 1
    cout << q.pop() << endl; // return 1, queue is [2]
    cout << q.empty() << endl; // return false

    return 0;
}
