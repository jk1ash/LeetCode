#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <limits.h>
using namespace std;

#define null INT_MAX //把力扣给定的null节点定义为int的最大值，用于识别空结点

//二叉树的结构体定义
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *CreatTree(vector<int> &layerorder);       //根据给定的层序序列建树的函数
int LayerOfTree(TreeNode *root);                    //计算树的层数，用于绘制树形
void PrintTreeMatrix(vector<vector<int>> &matrix);  //用于打印树形结构专用的二维数组输出函数
void PrintTree(TreeNode *root);                     //打印树的函数
void PrintMatrix(vector<vector<int>> matrix);      //打印一般二维数组的函数