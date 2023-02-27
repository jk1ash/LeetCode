/*
 * @Author: jklash
 * @Description: 剑指 Offer 09. 用两个栈实现队列
 * @Date: 2021-11-19 16:57:22
 * @LastEditors: jklash
 * @LastEditTime: 2021-11-19 17:38:54
 */
#include <iostream>
#include <stack>
using namespace std;

class CQueue {
private:
    stack<int> in, out;

public:

    CQueue() {
        while (!in.empty())
            in.pop();
        while (!out.empty())
            out.pop();
    }
    
    void appendTail(int value) {
        in.push(value);
    }
    
    int deleteHead() {
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }

        if (out.empty())
            return -1;
        int d = out.top();
        out.pop();
        return d;
    }
};

int main(int argc, char const *argv[])
{
    CQueue q;
    q.appendTail(5);
    q.appendTail(2);
    cout << q.deleteHead() << endl;
    cout << q.deleteHead() << endl;

    return 0;
}
