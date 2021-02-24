/* ------------------------------------------------------------------|
给定一个二进制矩阵 A，我们想先水平翻转图像，然后反转图像并返回结果。

水平翻转图片就是将图片的每一行都进行翻转，即逆序。例如，水平翻转 [1, 1, 0] 的结果是 [0, 1, 1]。

反转图片的意思是图片中的 0 全部被 1 替换， 1 全部被 0 替换。例如，反转 [0, 1, 1] 的结果是 [1, 0, 0]。

 

示例 1：

输入：[[1,1,0],[1,0,1],[0,0,0]]
输出：[[1,0,0],[0,1,0],[1,1,1]]
解释：首先翻转每一行: [[0,1,1],[1,0,1],[0,0,0]]；
     然后反转图片: [[1,0,0],[0,1,0],[1,1,1]]
示例 2：

输入：[[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
输出：[[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
解释：首先翻转每一行: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]]；
     然后反转图片: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
 

提示：

1 <= A.length = A[0].length <= 20
0 <= A[i][j] <= 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/flipping-an-image
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*
*
*	执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
*	内存消耗：8.2 MB, 在所有 C++ 提交中击败了92.06%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
    int n = A.size();
    for (int i = 0; i < n; i++) {
        for (int l = 0, r = n - 1; l <= r; l++, r--) {
            if (l == r) {
                A[i][l] = !A[i][l];
            }
            else {
                if (A[i][l] == A[i][r]) {
                    A[i][l] = !A[i][l];
                    A[i][r] = !A[i][r];
                }
            }
        }
    }
    return A;
}

//vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
//    int n = A.size();
//    for (int i = 0; i < n; i++) {
//        //reverse()为O(n)
//        reverse(A[i].begin(), A[i].end());
//        for (int j = 0; j < n; j++) {
//            A[i][j] = !A[i][j];
//        }
//    }
//    return A;
//}

int main() {
    vector<vector<int>> A = { {1,1,0},{1,0,1},{0,0,0} };
    flipAndInvertImage(A);
}