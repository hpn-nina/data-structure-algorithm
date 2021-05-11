// 02_19520208_HuynhPhuongNhu_THBST_02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>
using namespace std;
struct tNode
{
    int key;
    tNode* left;
    tNode* right;
};
struct TNode
{
    float key;
    TNode* left;
    TNode* right;
};
struct Tree
{
    tNode* root; 
};
struct TREE
{
    TNode* ROOT;
};
tNode* CreateNode(int x)
{
    tNode* p = new tNode;
    if (p == NULL)
        exit(1);
    p->key = x;
    p->left = p->right = NULL;
    return p;
}
TNode* CreateNode(float x)
{
    TNode* p = new TNode;
    if (p == NULL)
        exit(1);
    p->key = x;
    p->left = p->right = NULL;
    return p;
}
void CreateTree(Tree& t)
{
    t.root = NULL;
}
void CreateTree(TREE& t)
{
    t.ROOT = NULL;
}
tNode* FindX1(Tree t,int x)
{
    if (t.root)
    {
        if (t.root->key > x)
        {
            Tree a;
            a.root = t.root->right;
            if (a.root->key == x)
                return a.root;
            else
                return FindX1(a, x);
        }
        else
        {
            Tree a;
            a.root = t.root->left;
            if (a.root->key == x)
                return a.root;
            else
                return FindX1(a, x);
        }
    }
    return 0;
}
TNode* FindX1(TREE t,float x)
{
    TNode* t = t.ROOT;
    if (t.ROOT)
    {
        if (x > t.ROOT->key)
        {
            TREE a;
            a.ROOT = t.ROOT->right;
            if (a.ROOT->key == x)
                return a.ROOT;
            else
                return FindX1(a, x);
        }
        else
        {
            TREE a;
            a.ROOT = t.ROOT->left;
            if (a.ROOT->key == x)
                return a.ROOT;
            else
                return FindX1(a, x);
        }
    }
    return 0;
}
int InsertNode1(Tree& t,int x)
{
    tNode* p = CreateNode(x);
    if (t.root)
    {
        if (t.root->key < x)
        {
            Tree a;
            a.root = t.root->right;
            if (t.root->right == NULL)
                t.root->right = p;
            return InsertNode1(a, x);
        }
        else
        {
            Tree a;
            a.root = t.root->left;
            if (t.root->left == NULL)
                t.root->left = p;
            return InsertNode1(a, x);
        }
        cout << "\tValue " << x << "\tAdd " << &p << "left " << &p->left << "right " << &p->right << endl;
        return 1;
    }
    t.root = p;
    return 1;
}
int InsertNode1(TREE& t,float x)
{
    TNode* p = CreateNode(x);
    if (t.ROOT)
    {
        if (t.ROOT->key > x)
        {
            TREE a;
            a.ROOT = t.ROOT->right;
            if (t.ROOT->right == NULL)
                t.ROOT->right = p;
            return InsertNode1(a, x);
        }
        else
        {
            TREE a;
            a.ROOT = t.ROOT->left;
            if (t.ROOT->left == NULL)
                t.ROOT->left = p;
            return InsertNode1(a, x);
        }
        cout << "\tValue " << x << "\tAdd " << &p << "left " << &p->left << "right " << &p->right << endl;
        return 1;
    }
    t.ROOT = p;
    cout << "\tValue " << x << "\tAdd " << &p << "left " << &p->left << "right " << &p->right << endl;
    return 1;
}
void NLR1(Tree t)
{
    Tree a, b;
    a.root = t.root->left;
    b.root = t.root->right;
    cout << t.root->key << "\t" << &t.root << "\tleft: " << &t.root->left << "\tright: " << &t.root->right << endl;
    NLR1(a);
    NLR1(b);
}
void NLR1(TREE t)
{
    TREE a, b;
    a.ROOT = t.ROOT->left;
    b.ROOT = t.ROOT->right;
    cout << t.ROOT->key << "\t" << &t.ROOT << "\tleft: " << &t.ROOT->left << "\tright: " << &t.ROOT->right << endl;
    NLR1(a);
    NLR1(b);
}
void LNR1(Tree t)
{
    Tree a, b;
    a.root = t.root->left;
    b.root = t.root->right;
    LNR1(a);
    cout << t.root->key << "\t" << &t.root << "\tleft: " << &t.root->left << "\tright: " << &t.root->right << endl;
    LNR1(b);
}
void LNR1(TREE t)
{
    TREE a, b;
    a.ROOT = t.ROOT->left;
    b.ROOT = t.ROOT->right;
    LNR1(a);
    cout << t.ROOT->key << "\t" << &t.ROOT << "\tleft: " << &t.ROOT->left << "\tright: " << &t.ROOT->right << endl;
    LNR1(b);
}
void LRN1(Tree t)
{
    Tree a, b;
    a.root = t.root->left;
    b.root = t.root->right;
    LRN1(a);
    LRN1(b);
    cout << t.root->key << "\t" << &t.root << "\tleft: " << &t.root->left << "\tright: " << &t.root->right << endl;
}
void LRN1(TREE t)
{
    TREE a, b;
    a.ROOT = t.ROOT->left;
    b.ROOT = t.ROOT->right;
    LRN1(a);
    LRN1(b);
    cout << t.ROOT->key << "\t" << &t.ROOT << "\tleft: " << &t.ROOT->left << "\tright: " << &t.ROOT->right << endl;
}
void NRL1(Tree t)
{
    Tree a, b;
    a.root = t.root->left;
    b.root = t.root->right;
    cout << t.root->key << "\t" << &t.root << "\tleft: " << &t.root->left << "\tright: " << &t.root->right << endl;
    NLR1(b);
    NLR1(a);
}
void NRL1(TREE t)
{
    TREE a, b;
    a.ROOT = t.ROOT->left;
    b.ROOT = t.ROOT->right;
    cout << t.ROOT->key << "\t" << &t.ROOT << "\tleft: " << &t.ROOT->left << "\tright: " << &t.ROOT->right << endl;
    NRL1(b);
    NRL1(a);
}
void RNL1(Tree t)
{
    Tree a, b;
    a.root = t.root->left;
    b.root = t.root->right;
    RNL1(b);
    cout << t.root->key << "\t" << &t.root << "\tleft: " << &t.root->left << "\tright: " << &t.root->right << endl;
    RNL1(a);
}
void RNL1(TREE t)
{
    TREE a, b;
    a.ROOT = t.ROOT->left;
    b.ROOT = t.ROOT->right;
    RNL1(b);
    cout << t.ROOT->key << "\t" << &t.ROOT << "\tleft: " << &t.ROOT->left << "\tright: " << &t.ROOT->right << endl;
    RNL1(a);
}
void RLN1(Tree t)
{
    Tree a, b;
    a.root = t.root->left;
    b.root = t.root->right;
    RLN1(b);
    RLN1(a);
    cout << t.root->key << "\t" << &t.root << "\tleft: " << &t.root->left << "\tright: " << &t.root->right << endl;
}
void RLN1(TREE t)
{
    TREE a, b;
    a.ROOT = t.ROOT->left;
    b.ROOT = t.ROOT->right;
    RLN1(b);
    RLN1(a);
    cout << t.ROOT->key << "\t" << &t.ROOT << "\tleft: " << &t.ROOT->left << "\tright: " << &t.ROOT->right << endl;
}
 void InsertNode2(Tree & t, int x)
{
    tNode* p = CreateNode(x);
    if (t.root == NULL)
        t.root = p;
    else
    {
        tNode* run = t.root;
        tNode* yes = 0;
        while (run != NULL)
        {
            yes = run;
            if (x < run->key)
                run = run->left;
            else if (x > run->key)
                run = run->right;
        }
        if (x < yes->key)
            yes->left = p;
        else if (x > yes->key)
            yes->right = p;      
    }
}
 void InsertNode2(TREE& t,float x)
{

}
int main()
{
    std::cout << "Hello World!\n";
}
/*
#include <iostream>
#include <time.h>
using namespace std;
struct TNode
{
    int key;
    TNode* pLeft;
    TNode* pRight;
};
struct TREE
{
    TNode* ROOT;
};
void CreateTree(TREE& T)
{
    T.ROOT = NULL;
}
TNode *CreateTNode(int x)
{
    TNode* a = new TNode;
    if (a == NULL)
        exit(1);
    a->key = x;
    a->pLeft = a->pRight = NULL;
    return a;
}
int insertNode(TREE& T, int x)
{
    TNode* p = CreateTNode(x);
    if (T.ROOT)
    {
        if (T.ROOT->key < x)
        {
            TREE a;
            a.ROOT = T.ROOT->pRight;
            if (T.ROOT->pRight == NULL)
                T.ROOT->pRight = p;
            return insertNode(a, x);
        }
        else
        {
            TREE a;
            a.ROOT = T.ROOT->pLeft;
            if (T.ROOT->pLeft == NULL)
                T.ROOT->pLeft = p;
            return insertNode(a, x);
        }
    }
        T.ROOT = new TNode;
        if (T.ROOT == NULL)
            return -1;
        T.ROOT->key = x;
        T.ROOT->pLeft = T.ROOT->pRight = NULL;
        return 1;
}

B1: Neu cay rong thi node goc dc gan bang node chuan bi dc dua vao.
B2: Neu cay 0 rong thi di tim vi tri node can chen. Gia su node yes.
B3: So sanh, xac dinh gan vao left hoac right

//void insertNode(TREE &t, int x)
//{
//    TNode* p = CreateTNode(x);
//    if (t.ROOT == NULL)
//        t.ROOT = p;
//    else
//    {
//        TNode* run = t.ROOT;
//        TNode* yes = 0;
//        while (run != NULL)
//        {
//            yes = run;
//            if (x < run->key)
//                run = run->pLeft;
//            else if (x > run->key)
//                run = run->pRight;
//        }
//        if (x < yes->key)
//            yes->pLeft = p;
//        else if (x > yes->key)
//            yes->pRight = p;
//    }
//}
void AutoBuild_BinaryTree(TREE& T)
{
    srand(time(0));
    int sl = 10 + rand() % 11;
    int gt;
    for (int i = 0; i < sl; ++i)
    {
        gt = -358 + rand() % 1717;
        insertNode(T, gt);
    }
}
void LNR(TREE t)
{
    if (t.ROOT != NULL)
    {
        TREE a, b;
        a.ROOT = t.ROOT->pLeft;
        b.ROOT = t.ROOT->pRight;
        LNR(a);
        cout << "Value: " << t.ROOT->key << "\tAddress: " << t.ROOT << "\tpLeft: " << t.ROOT->pLeft << "\tpRight: " << t.ROOT->pRight << "\n";
        LNR(b);
    }
}
void NLR(TREE t)
{
    if (t.ROOT != NULL)
    {
        TREE a, b;
        a.ROOT = t.ROOT->pLeft;
        b.ROOT = t.ROOT->pRight;
        cout << "Value: " << t.ROOT->key << "\tAddress: " << t.ROOT << "\tpLeft: " << t.ROOT->pLeft << "\tpRight: " << t.ROOT->pRight << "\n";
        NLR(a);
        NLR(b);
    }
}
void LRN(TREE t)
{
    if (t.ROOT != NULL)
    {
        TREE a, b;
        a.ROOT = t.ROOT->pLeft;
        b.ROOT = t.ROOT->pRight;
        NLR(a);
        NLR(b);
        cout << "Value: " << t.ROOT->key << "\tAddress: " << t.ROOT << "\tpLeft: " << t.ROOT->pLeft << "\tpRight: " << t.ROOT->pRight << "\n";
    }
}
TNode* FindX(TREE t, int x)
{
    TREE a;
    if (t.ROOT)
    {
        if (t.ROOT->key == x)
            return t.ROOT;
        else if (t.ROOT->key > x)
        {
            a.ROOT = t.ROOT->pLeft;
            FindX(a, x);
        }
        else if (t.ROOT->key < x)
        {
            a.ROOT = t.ROOT->pRight;
            FindX(a, x);
        }
    }
    else
        return NULL;
}
void ThayThe(TREE t, TNode la)
{
}
void DeleteX(TREE t, int x)
{
    TNode* b4dc = FindX(t, x);
    TNode* dc = FindX(t, x);
    if (dc)
    {
        if (dc->pLeft == NULL && dc->pRight == NULL)
            delete dc;
        else if (dc->pLeft && dc->pRight)
        {
        }
        else if (dc->pLeft)
        {
        }
        else if (dc->pRight)
        {
        }
    }
}
int main()
{
    TREE tree;
    int x;
    CreateTree(tree);
    //tree.ROOT = CreateTNode(3);
    AutoBuild_BinaryTree(tree);
    LNR(tree);
    cout << "\nNhap gia tri x can tim: ";
    cin >> x;
    cout << FindX(tree, x);
}
*/