// Class02_02_19520208_HuynhPhuongNhu_BT_BST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>
using namespace std;
struct TNode
{
    float key;
    TNode* left;
    TNode* right;
};
struct TREE
{
    TNode* ROOT;
};
struct Node
{
    TNode* key;
    Node* next;
};
struct Stack
{
    Node* head;
    Node* tail;
};
void CreateEmptyStack(Stack& s)
{
    s.head = s.tail = NULL;
}
Node* CreateNode(TNode* p)
{
    Node* q = new Node;
    if (q == NULL)
        exit(1);
    q->key = p;
    q->next = NULL;
    return q;
}
void Push(Stack& s, TNode* p)
{
    Node* q = CreateNode(p);
    if (s.head == NULL)
        s.head = s.tail = q;
    else
    {
        q->next = s.head;
        s.head = q;
    }
}
Node* Pop(Stack& s)
{
    if (s.head == NULL)
        return 0;
    Node* p = s.head;
    s.head = s.head->next;
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
void CreateTree(TREE& t)
{
    t.ROOT = NULL;
}
int InsertNode1(TREE& t, float x)
{

    TNode* p = CreateNode(x);
    if (t.ROOT!=NULL)
    {
        if (t.ROOT->key > x)
        {
            TREE a;
            a.ROOT = t.ROOT->left;
            if (t.ROOT->left == NULL)
                t.ROOT->left = p;
            return InsertNode1(a, x);
        }
        else
        {
            TREE a;
            a.ROOT = t.ROOT->right;
            if (t.ROOT->right == NULL)
                t.ROOT->right = p;
            return InsertNode1(a, x);
        }
        cout << "\tValue " << x << "\tAdd " << p  << endl;
        return 1;
    }
    else
    {
        t.ROOT = p;
        cout << "\tValue " << x << "\tAdd " << p << endl;
    }
    return 1;
}
void Input(TREE& t)
{
    float tam;
    do
    {   
        cout << "Enter your number (Enter 0 to stop): ";
        cin >> tam;
        if (tam == 0)
            break;
        InsertNode1(t, tam);
    }while (tam != 0);
}
void AutoInput(TREE& t)
{
    srand(time(NULL));
    int n = 10 + rand() % 11;
    for (int i = 0; i < n; i++)
    {
        float tam = -358 + rand() % 1359;
        InsertNode1(t, tam);
    }
}
TNode* Peek(Stack s)
{
    if (s.head == NULL)
        return 0;
    return s.head->key;
}
TNode* FindX1(TREE t, float x)
{
    TNode* tam = t.ROOT;
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

int InsertNode2(TREE& t, float x)
{
    TNode* p = CreateNode(x);
    if (t.ROOT == NULL)
    {
        t.ROOT = p;
    }
    else
    {
        TNode* run = t.ROOT;
        TNode* yes = 0;
        while (run != NULL)
        {
            yes = run;
            if (x <= run->key)
                run = run->left;
            else
                run = run->right;
        }
        if (x > yes->key)
            yes->right = p;
        else
            yes->left = p;
    }
    return 1;
}
void NLR1(TREE t)
{
    if (t.ROOT)
    {
        TREE a, b;
        a.ROOT = t.ROOT->left;
        b.ROOT = t.ROOT->right;
        cout << t.ROOT->key << "\t";
        NLR1(a);
        NLR1(b);
    }
}
void NLR2(TREE t)
{
    cout << "\nDuyet NLR: \n";
    Stack pre;
    CreateEmptyStack(pre);
    TNode* current = t.ROOT;
    while (current != NULL)
    {
        cout << current->key << "\tleft: " << current->left << "\tright: " << current->right << endl;
        if (current->right != NULL)
            Push(pre, current);
        current = current->left;
        if (current == NULL && Peek(pre)!=NULL)
        {
            Node* q = Pop(pre);
            current = q->key->right;
        }
    }
    cout << endl;
}
void NRL2(TREE t)
{
    cout << "\nDuyet NRL: \n";
    Stack pre;
    CreateEmptyStack(pre);
    TNode* current = t.ROOT;
    while (current != NULL)
    {
        cout << current->key << "\tleft: " << current->left << "\tright: " << current->right << endl;
        if (current->left != NULL)
            Push(pre, current);
        current = current->right;
        if (current == NULL && Peek(pre)!=NULL)
        {
            Node* q = Pop(pre);
            current = q->key->left;
        }
    }
    cout << endl;
}
void LNR2(TREE t) 
{
    /*Stack pre;
    CreateEmptyStack(pre);
    TNode* current = t.ROOT;
    while (current != NULL)
    {
        if (current->left)
        {
            Push(pre, current);
            current = current->left;
        }
        else
        {
            cout << current->key << "\t";
            if (current->right)
                current = current->right;
            else
            {
                TNode* q = Pop(pre)->key;
                cout << q->key << "\t";
                if (q->right)
                    current = q->right;
                else
                {
                    TNode* k = Pop(pre)->key;
                    if (t.ROOT->right == k && k->right == NULL)
                    {
                        cout << k->key << "\t";
                        break;
                    }
                    else
                        current = k->right;
                }
            }
        }
    }*/
}
void LNR1(TREE t)
{
    if (t.ROOT)
    {
        TREE a, b;
        a.ROOT = t.ROOT->left;
        b.ROOT = t.ROOT->right;
        LNR1(a);
        cout << t.ROOT->key << "\t" << t.ROOT << "\tleft: " << t.ROOT->left << "\tright: " << t.ROOT->right << endl;
        LNR1(b);
    }
}
void LRN1(TREE t)
{
    if (t.ROOT)
    {
        TREE a, b;
        a.ROOT = t.ROOT->left;
        b.ROOT = t.ROOT->right;
        LRN1(a);
        LRN1(b);
        cout << t.ROOT->key << "\t" << t.ROOT << "\tleft: " << t.ROOT->left << "\tright: " << t.ROOT->right << endl;
    }
}

bool IsLeaf(TNode* p)
{
    if (p->right == NULL && p->left == NULL)
        return 1;
    return 0;
}
void LRN2(TREE t)
{
    //Hoan thanh sau
}
void NRL1(TREE t)
{
    if (t.ROOT)
    {
        TREE a, b;
        a.ROOT = t.ROOT->left;
        b.ROOT = t.ROOT->right;
        cout << t.ROOT->key << "\t" << t.ROOT << "\tleft: " << t.ROOT->left << "\tright: " << t.ROOT->right << endl;
        NRL1(b);
        NRL1(a);
    }
}
void RNL1(TREE t)
{
    if (t.ROOT)
    {
        TREE a, b;
        a.ROOT = t.ROOT->left;
        b.ROOT = t.ROOT->right;
        RNL1(b);
        cout << t.ROOT->key << "\t" << t.ROOT << "\tleft: " << t.ROOT->left << "\tright: " << t.ROOT->right << endl;
        RNL1(a);
    }
}
void RLN1(TREE t)
{
    if (t.ROOT)
    {
        TREE a, b;
        a.ROOT = t.ROOT->left;
        b.ROOT = t.ROOT->right;
        RLN1(b);
        RLN1(a);
        cout << t.ROOT->key << "\t" << t.ROOT << "\tleft: " << t.ROOT->left << "\tright: " << t.ROOT->right << endl;
    }
}
bool FindX2(TREE t)
{
    float x;
    cout << "Choose to enter value or random it: \n\t1 for entering value\n\t2 for random\n";
    int tam;
    cin >> tam;
    switch (tam)
    {
    case 1:
        cout << "Enter value: ";
        cin >> x;
        break;
    case 2:
        cout << "Random...\n";
        srand(time(NULL));
        x = rand() % 501 + 300;
        break;
    default:
        break;
    }
    TNode* current = t.ROOT;
    if (current->key == x)
        return 1;
    while (x > current->key)
    {
        current = current->right;
        if (current == NULL)
            break;
        if (x == current->key)
            return 1;
    }
    if (current)
    {
        while (x <= current->key)
        {
            current = current->left;
            if (current == NULL)
                break;
            if (x == current->key)
                return 1;
        }
    }
    return 0;
}
int NodeStatus(TREE t, TNode* p)
{
    if (p->right && p->left)
        return 2;
    if (p->right || p->left)
        return 1;
    return 0;
}
TNode* MinRight(TNode* t, float& dem)
{
    TNode* run = t->right;
    TNode* minr = new TNode;
    while (run != NULL)
    {
        dem++;
        minr = run;
        run = run->left;
    }
    return minr;
}
TNode* MaxLeft(TNode* t, float& dem)
{
    TNode* run = t->left;
    TNode* maxl = new TNode;
    while (run != NULL)
    {
        dem++;
        maxl = run;
        run = run->right;
    }
    return maxl;
}
TNode* FindPre(TREE t,TNode* p)
{
    TNode* current = t.ROOT;
    TNode* pre = 0;
    while (current->key != p->key)
    {
        pre = current;
        if (current->key < p->key)
            current = current->left;
        else
            current = current->right;
    }
    return pre;
}
//Cau 5
TNode* ThayThe(TNode* x)
{
    float demmaxl = 0, demminr = 0;
    TNode* thaythe = new TNode;
    MaxLeft(x, demmaxl);
    MinRight(x, demminr);
    if (demmaxl > demminr)
        thaythe = MinRight(x, demminr);
    else
        thaythe = MaxLeft(x, demmaxl);
    return thaythe;
}

TNode* FindX(TREE T, int x)
{
    TNode* run = T.ROOT;
    while (run != NULL)
    {
        if (run->key == x)
            return run;
        else if (run->key > x)
            run = run->left;
        else if (run->key < x)
            run = run->right;
    }
    return NULL;
}
void RemoveX(TREE& t, float x)
{
    TNode* b4 = t.ROOT;
    TNode* dc = FindX(t, x);
    if (dc)
    {
        TNode* thaythe = ThayThe(dc);
        if (dc->left == NULL && dc->right == NULL)
        {
            while (b4->left != dc && b4->right != dc)
            {
                if (b4->key > x)
                    b4 = b4->left;
                else if (b4->key < x)
                    b4 = b4->right;
            }
            if (b4->left == dc)
                b4->left = NULL;
            else if (b4->right == dc)
                b4->right = NULL;
            delete dc;
            cout << "\nDa xoa X!\n";
        }
        else if (dc->left && dc->right)
        {
            dc->key = thaythe->key;
            if (thaythe == dc->left)
                dc->left = NULL;
            else if (thaythe == dc->right)
                dc->right = NULL;
            delete thaythe;
            cout << "\nDa xoa X!\n";
        }
        else if (dc->left)
        {
            dc->key = dc->left->key;
            dc->left = NULL;
            delete dc->left;
            cout << "\nDa xoa X!\n";
        }
        else if (dc->right)
        {
            dc->key = dc->right->key;
            dc->right = NULL;
            delete dc->right;
            cout << "\nDa xoa X!\n";
        }
    }
    else
        cout << "Khong tim thay X!";
}
void DeleteL(TNode* t)
{
    TNode* temp = t;
    if (t)
    {
        DeleteL(t->left);
        DeleteL(t->right);
        delete temp;
    }
}

void DeleteAll(TREE t)
{
    DeleteL(t.ROOT);
    t.ROOT->key = NULL;
    t.ROOT->left = NULL;
    t.ROOT->right = NULL;
}
//Cau 8
void Leaf(TREE t, int& x)
{
    if (t.ROOT)
    {
        TREE a, b;
        a.ROOT = t.ROOT->left;
        b.ROOT = t.ROOT->right;
        if (IsLeaf(t.ROOT))
            ++x;
        Leaf(a, x);
        Leaf(b, x);
    }
}
int CountLeaf(TREE t,int& x)
{
    x = 0;
    Leaf(t, x);
    return x;
}
//Cau 6
void NumNode(TREE t, int& x)
{
    if (t.ROOT)
    {
        TREE a, b;
        a.ROOT = t.ROOT->right;
        b.ROOT = t.ROOT->left;
        ++x;
        NumNode(a, x);
        NumNode(b, x);
    }
}
int CountNode(TREE t, int& x)
{
    x = 0;
    NumNode(t, x);
    return x;
}
//Cau 9
void PrintSubTree(TREE t, float x)
{
    if (t.ROOT)
    {
        TNode* current = t.ROOT;
        if (x > t.ROOT->key)
        {
            TREE a;
            a.ROOT = t.ROOT;
            NLR2(a);
            t.ROOT = NULL;
            
        }
        else
        {
            if (t.ROOT->key == x)
            {
                TREE a;
                a.ROOT = t.ROOT->right;
                PrintSubTree(a, x);
            }
            else
            {
                TREE a;
                a.ROOT = t.ROOT->left;
                PrintSubTree(a, x);
            }
        }
   }
}
//Cau 10
void SmallerNode(TREE t, float x,int& k)
{
    if (t.ROOT)
    {
        TREE a, b;
        a.ROOT = t.ROOT->right;
        b.ROOT = t.ROOT->left;
        if (t.ROOT->key < x)
            ++k;
        SmallerNode(a, x, k);
        SmallerNode(b, x, k);
    }
}
int CountSmallerNode(TREE t, float x)
{
    int k = 0;
    SmallerNode(t, x, k);
    return k;
}
//Cau 11
void BiggerNode(TREE t, float& x, int& k)
{
    if (t.ROOT)
    {
        TREE a, b;
        a.ROOT = t.ROOT->right;
        b.ROOT = t.ROOT->left;
        if (t.ROOT->key > x)
            ++k;
        BiggerNode(a, x, k);
        BiggerNode(b, x, k);
    }
}
int CountBiggerNode(TREE t, float x)
{
    int k = 0;
    BiggerNode(t, x, k);
    return k;
}
//Cau 12
void BetweenXandY(TREE t, float x, float y, int& k)
{
    if (t.ROOT)
    {
        TREE a, b;
        a.ROOT = t.ROOT->right;
        b.ROOT = t.ROOT->left;
        if (t.ROOT->key > x && t.ROOT->key < y)
            ++k;
        BetweenXandY(a, x, y, k);
        BetweenXandY(b, x, y, k);
    }
}
int CBetweenXandY(TREE t, float x, float y)
{
    int k = 0;
    BetweenXandY(t, x, y, k);
    return k;
}
//Cau 13
void Compare10vs11(TREE t, float x)
{
    int k1 = 0, k2 = 0;
    SmallerNode(t, x, k1);
    BiggerNode(t, x, k2);
    cout << "So node nho hon x: " << k1 << endl;
    cout << "So node lon hon x: " << k2 << endl;
}
//Cau 14
void OddNode(TREE t, int& x)
{
    if (t.ROOT)
    {
        TREE a, b;
        a.ROOT = t.ROOT->right;
        b.ROOT = t.ROOT->left;
        if (int(t.ROOT->key) % 2 != 0)
            ++x;
        OddNode(a, x);
        OddNode(b, x);
    }
}
void EvenNode(TREE t, int& x)
{
    if (t.ROOT)
    {
        TREE a, b;
        a.ROOT = t.ROOT->right;
        b.ROOT = t.ROOT->left;
        if (int(t.ROOT->key) % 2 == 0)
            ++x;
        EvenNode(a, x);
        EvenNode(b, x);
    }
}
void CountOddEven(TREE t, int& o,int& e)
{
    o = 0;
    e = 0;
    OddNode(t, o);
    EvenNode(t, e);
    cout << "\nNumber of even node: " << e << "\n";
    cout << "\nNumber of odd node: " << o << "\n";
}
//Cau 15
void TotalNode(TREE t, float& x)
{
    if (t.ROOT)
    {
        TREE a, b;
        a.ROOT = t.ROOT->right;
        b.ROOT = t.ROOT->left;
        x += t.ROOT->key;
        TotalNode(a, x);
        TotalNode(b, x);
    }
}
void CalAllNode(TREE t, float& x)
{
    x = 0;
    TotalNode(t, x);
    cout << "Total: " << x << "\n";
}
//Cau 16
void TotalOddNode(TREE t, float& x)
{
    if (t.ROOT)
    {
        TREE a, b;
        a.ROOT = t.ROOT->right;
        b.ROOT = t.ROOT->left;
        if (int(t.ROOT->key) % 2 != 0)
            x += t.ROOT->key;
        TotalOddNode(a, x);
        TotalOddNode(b, x);
    }
}
void CalAllOdd(TREE t)
{
    float x = 0;
    TotalOddNode(t, x);
    cout << "Total Odd Node: " << x << endl;
}
//Cau 17
void TotalEvenNode(TREE t, float& x)
{
    if (t.ROOT)
    {
        TREE a, b;
        a.ROOT = t.ROOT->right;
        b.ROOT = t.ROOT->left;
        if (int(t.ROOT->key) % 2 == 0)
            x += t.ROOT->key;
        TotalEvenNode(a, x);
        TotalEvenNode(b, x);
    }
}
void CalEvenNode(TREE t)
{
    float x = 0;
    TotalEvenNode(t, x);
    cout << "Total even node: " << x << endl;
}
//Cau 18
void CountTotalOddEven(TREE t, float& o, float& e)
{
    o = 0;
    e = 0;
    TotalOddNode(t, o);
    TotalEvenNode(t, e);
    cout << "\nTotal of even node: " << e << "\n";
    cout << "\nTotal of odd node: " << o << "\n";
}
//Cau 19
TNode* Max(TREE t)
{
    float Max = 0;
    TNode* NMax = new TNode;
    Stack pre;
    CreateEmptyStack(pre);
    TNode* current = t.ROOT;
    while (current != NULL)
    {
        if (current->key > Max)
        {
            Max = current->key;
            NMax = current;
        }
        if (current->right != NULL)
            Push(pre, current);
        current = current->left;
        if (current == NULL && Peek(pre) != NULL)
        {
            Node* q = Pop(pre);
            current = q->key->right;
        }
    }
    cout << endl;
    return NMax;
}
TNode* Min(TREE t)
{
    float Min = 0;
    TNode* NMin = new TNode;
    Stack pre;
    CreateEmptyStack(pre);
    TNode* current = t.ROOT;
    while (current != NULL)
    {
        if (current->key < Min)
        {
            Min = current->key;
            NMin = current;
        }
        if (current->right != NULL)
            Push(pre, current);
        current = current->left;
        if (current == NULL && Peek(pre) != NULL)
        {
            Node* q = Pop(pre);
            current = q->key->right;
        }
    }
    cout << endl;
    return NMin;
}

int main()
{
    TREE t;
    float x;
    int o, e;
    int k;
    CreateTree(t);
    do {
        cout << "+++++++++++++++++++++MENU+++++++++++++++++++++\n";
        cout << "1.Cau #1\n";
        cout << "2.Cau #2\n";
        cout << "3.Cau #3\n";
        cout << "4.Cau #4\n";
        cout << "5.Cau #5\n";
        cout << "6.Cau #6\n";
        cout << "7.Cau #7\n";
        cout << "8.Cau #8\n";
        cout << "9.Cau #9\n";
        cout << "10.Cau #10\n";
        cout << "11.Cau #11\n";
        cout << "12.Cau #12\n";
        cout << "13.Cau #13\n";
        cout << "14.Cau #14\n";
        cout << "15.Cau #15\n";
        cout << "16.Cau #16\n";
        cout << "17.Cau #17\n";
        cout << "18.Cau #18\n";
        cout << "19.Cau #19\n";
        cout << "+++++++++++++++++++++THE END+++++++++++++++++++++";
        cout << "\n\tChon chuc nang: ";
        int tam;
        cin >> tam;
        switch (tam)
        {
        case 1:
            Input(t);
            break;
        case 2:
            AutoInput(t);
            break;
        case 3:
            cout << "\nNLR\n";
            NLR1(t);
            cout << "\nLNR\n";
            LNR1(t);
            cout << "\nLRN\n";
            LRN1(t);
            cout << "\nNRL\n";
            NRL1(t);
            cout << "\nRNL\n";
            RNL1(t);
            cout << "\nRLN\n";
            RLN1(t);
            break;
        case 4:
            if (FindX2(t) == 1)
                cout << "\nTim thay\n";
            else
                cout << "\nKhong tim thay\n";
            break;
        case 5:
            cout << "Enter node's value want to delete: ";
            cin >> x;
            RemoveX(t, x);
            break;
        case 6:
            DeleteAll(t);
            break;
        case 7:
            
            cout << "Tong so node tren cay: ";
            cout << CountNode(t, k)<<endl;
            break;
        case 8:
            cout << "Tong so la la: " << CountLeaf(t, k) << endl;
            break;
        case 9:
            cout << "Nhap gia tri x muon in node nhanh: ";
            cin >> x;
            PrintSubTree(t, x);
            break;
        case 10:
            cout << "Nhap x muon dem so node co gia tri nho hon: ";
            cin >> x;
            cout << "So node nho hon x la: ";
            cout << CountSmallerNode(t, x)<<endl;
            break;
        case 11:
            cout << "Nhap x muon dem so node co gia tri lon hon: ";
            cin >> x;
            cout << "So node lon hon x la: ";
            cout << CountBiggerNode(t, x)<<endl;
            break;
        case 12:
            cout << "Nhap x: ";
            cin >> x;
            float y;
            cout << "Nhap y: ";
            cin >> y;
            cout << "So node nam giua X va Y la: ";
            cout << CBetweenXandY(t, x, y) << endl;
            break;
        case 13:
            cout << "Nhap x muon dem so node co gia tri nho hon: ";
            cin >> x;
            cout << "So node nho hon x la: ";
            cout << CountSmallerNode(t, x) << endl;
            cout << "So node lon hon x la: ";
            cout << CountBiggerNode(t, x) << endl;
            break;
        case 14:
            CountOddEven(t, o, e);
            break;
        case 15:
            CalAllNode(t, x);
            break;
        case 16:
            CalAllOdd(t);
            break;
        case 17:
            CalEvenNode(t);
            break;
        case 18:
            CalAllOdd(t);
            CalEvenNode(t);
            break;
        case 19:
            cout << "Node co gia tri lon nhat: "  << "\tValue " << Max(t)->key << endl;
            cout << "Node co gia tri be nhat: " << "\tValue " << Min(t)->key << endl;
            break;
        default:
            cout << "Please enter from 1 to 19. \n";
            break;
        }
    } while (1);
    return 0;
}
