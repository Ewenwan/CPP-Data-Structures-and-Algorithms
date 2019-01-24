// Project: Binary_Tree.cbp
// File   : Binary_Tree.cpp 二叉树 Binary Tree 左/右子节点 存储具有等级层级关系的数据

/*   A simple binary tree
 *        A ---------> A is root node---根节点
 *       / \
 *      /   \
 *     B     C
 *    /     / \
 *   /     /   \
 *   D     E    F ---> leaves: D, E, F---叶子leaf节点
 *
 *       (1)      ---> Height: 3
 *    B节点只有一个子节点D，这是非完全二叉树
 *    常用来存储具有等级层级关系的数据，例如计算机的文件系统数据，以及家族谱


    二叉树（Binary Tree）是最简单的树形数据结构，然而却十分精妙。
    其衍生出各种算法，以致于占据了数据结构的半壁江山。
    STL中大名顶顶的关联容器——集合（set）、映射（map）便是使用二叉树实现。
    二叉树的根节点入度为0，叶子节点出度为0。
    
    与楼房一样，一般会对二叉树分层，并且通常将根节点视为第一层。
    接下来B与C同属第二层，D, E, F同属第三层。注意，并不是所有的叶子都在同一层。
    通常将二叉树节点的最高层数作为其树的高度，上例中二叉树高度为3。
    显然，一个二叉树的节点总数必然小于2的树高幂，
    转化成公式表示为：N<2^H，其中N为节点总数，H为二叉树高度；对于第k层，最多有2^(k-1)个节点。
 * */

#include <iostream>

using namespace std;

class TreeNode  // 树节点
{
public:
    int Key;// 节点存储的信息数据
    TreeNode * Left;  // 左子节点 指针
    TreeNode * Right; // 右子节点 指针
};

// 创建一个新节点，传入一个节点信息数据
TreeNode * NewTreeNode(int key)
{
    // 创建一个新节点Create a new node
    TreeNode * node = new TreeNode;

    // 更新节点信息数据
    node->Key = key;

    // 左右子节点指针初始化为 NULL
    node->Left = NULL;
    node->Right = NULL;

    return node;
}

// 按顺序打印二叉树，递归实现 遍历 二叉树，递归遍历 左/右子树
void PrintTreeInOrder(TreeNode * node)
{
	if(node == NULL) return;// 递归停止
	
        // 打印左子树
	PrintTreeInOrder(node->Left);
	
	cout << node->Key << " ";// 打印当前节点信息数据
	
	// 打印右子树
	PrintTreeInOrder(node->Right);
}

// 递归打印 二叉树，带有标记信息
void Print (TreeNode * x, int & id)
{
    if (!x) return;// 节点指针不为空，递归结束情况

    Print (x->Left,id);// 递归打印左子树

    id++;// 标记 id信息，在树中的 排行，家族谱中的地位
    cout << id << ' ' << x->Key << endl;// 打印节点信息

    Print (x->Right,id);// 递归打印右子树
}

int main()
{
    cout << "Binary Tree" << endl;

    // 创建一个树根节点 Creating root element
    TreeNode * root = NewTreeNode(1);

    /*
        为根节点添加 左/右 两个孩子节点。Add children to root element
          1
         / \
        2   3
    */
    root->Left = NewTreeNode(2);
    root->Right = NewTreeNode(3);

    /*
        为节点2添加两个孩子节点 Add children to element 2
             1
           /   \
          2     3
         / \
        4   5
    */
    root->Left->Left = NewTreeNode(4);
    root->Left->Right = NewTreeNode(5);

    /*
        为节点3添加两个节点 Add children to element 3
             1
           /   \
          2     3
         / \   / \
        4   5 6   7
    */
    root->Right->Left = NewTreeNode(6);
    root->Right->Right = NewTreeNode(7);

    int id = 0;
    Print(root, id);// 按照地位信息，打印树的各个节点信息数据

    return 0;
}
