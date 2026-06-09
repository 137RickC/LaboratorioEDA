#include <iostream>
#include <vector>

using namespace std;

class BTreeNode {
    vector<int> keys;
    vector<BTreeNode*> C;
    int t;
    bool leaf;

public:
    BTreeNode(int _t, bool _leaf) {
        t = _t;
        leaf = _leaf;
    }

    void traverse(int level = 0) {
        cout << "Nivel " << level << ": ";

        for (int k : keys)
            cout << k << " ";

        cout << endl;

        if (!leaf) {
            for (BTreeNode* child : C)
                child->traverse(level + 1);
        }
    }

    BTreeNode* search(int k) {
        int i = 0;

        while (i < keys.size() && k > keys[i])
            i++;

        if (i < keys.size() && keys[i] == k)
            return this;

        if (leaf)
            return nullptr;

        return C[i]->search(k);
    }

    void insertNonFull(int k);

    void splitChild(int i, BTreeNode* y);

    int findKey(int k) {
        int idx = 0;

        while (idx < keys.size() && keys[idx] < k)
            ++idx;

        return idx;
    }

    void remove(int k);

    void removeFromLeaf(int idx);

    void removeFromNonLeaf(int idx);

    int getPred(int idx);

    int getSucc(int idx);

    void fill(int idx);

    void borrowFromPrev(int idx);

    void borrowFromNext(int idx);

    void merge(int idx);

    friend class BTree;
};

class BTree {
    BTreeNode* root;
    int t;

public:
    BTree(int _t) {
        root = nullptr;
        t = _t;
    }

    void traverse() {
        if (root)
            root->traverse();
    }

    BTreeNode* search(int k) {
        return (root == nullptr)
                   ? nullptr
                   : root->search(k);
    }

    void insert(int k);

    void remove(int k);
};

void BTreeNode::insertNonFull(int k) {

    int i = keys.size() - 1;

    if (leaf) {

        keys.push_back(0);

        while (i >= 0 && keys[i] > k) {
            keys[i + 1] = keys[i];
            i--;
        }

        keys[i + 1] = k;
    }
    else {

        while (i >= 0 && keys[i] > k)
            i--;

        if (C[i + 1]->keys.size() == 2 * t - 1) {

            splitChild(i + 1, C[i + 1]);

            if (keys[i + 1] < k)
                i++;
        }

        C[i + 1]->insertNonFull(k);
    }
}

void BTreeNode::splitChild(int i,
                           BTreeNode* y) {

    BTreeNode* z =
        new BTreeNode(y->t, y->leaf);

    for (int j = 0; j < t - 1; j++)
        z->keys.push_back(
            y->keys[j + t]);

    if (!y->leaf) {

        for (int j = 0; j < t; j++)
            z->C.push_back(
                y->C[j + t]);
    }

    int middle = y->keys[t - 1];

    y->keys.resize(t - 1);

    if (!y->leaf)
        y->C.resize(t);

    C.insert(C.begin() + i + 1, z);

    keys.insert(keys.begin() + i,
                middle);
}

void BTree::insert(int k) {

    if (root == nullptr) {

        root = new BTreeNode(t, true);

        root->keys.push_back(k);
        return;
    }

    if (root->keys.size() ==
        2 * t - 1) {

        BTreeNode* s =
            new BTreeNode(t, false);

        s->C.push_back(root);

        s->splitChild(0, root);

        int i = 0;

        if (s->keys[0] < k)
            i++;

        s->C[i]->insertNonFull(k);

        root = s;
    }
    else {

        root->insertNonFull(k);
    }
}

void BTreeNode::remove(int k) {

    int idx = findKey(k);

    if (idx < keys.size() &&
        keys[idx] == k) {

        if (leaf)
            removeFromLeaf(idx);
        else
            removeFromNonLeaf(idx);
    }
    else {

        if (leaf) {
            cout << "La clave "
                 << k
                 << " no existe\n";
            return;
        }

        bool flag =
            (idx == keys.size());

        if (C[idx]->keys.size() < t)
            fill(idx);

        if (flag &&
            idx > keys.size())
            C[idx - 1]->remove(k);
        else
            C[idx]->remove(k);
    }
}

void BTreeNode::removeFromLeaf(int idx) {

    keys.erase(keys.begin() + idx);
}

void BTreeNode::removeFromNonLeaf(
    int idx) {

    int k = keys[idx];

    if (C[idx]->keys.size() >= t) {

        int pred = getPred(idx);

        keys[idx] = pred;

        C[idx]->remove(pred);
    }
    else if (
        C[idx + 1]->keys.size()
        >= t) {

        int succ = getSucc(idx);

        keys[idx] = succ;

        C[idx + 1]->remove(succ);
    }
    else {

        merge(idx);

        C[idx]->remove(k);
    }
}

int BTreeNode::getPred(int idx) {

    BTreeNode* cur = C[idx];

    while (!cur->leaf)
        cur = cur->C.back();

    return cur->keys.back();
}

int BTreeNode::getSucc(int idx) {

    BTreeNode* cur =
        C[idx + 1];

    while (!cur->leaf)
        cur = cur->C.front();

    return cur->keys.front();
}

void BTreeNode::fill(int idx) {

    if (idx != 0 &&
        C[idx - 1]->keys.size()
        >= t)

        borrowFromPrev(idx);

    else if (
        idx != keys.size() &&
        C[idx + 1]->keys.size()
        >= t)

        borrowFromNext(idx);

    else {

        if (idx != keys.size())
            merge(idx);
        else
            merge(idx - 1);
    }
}

void BTreeNode::borrowFromPrev(
    int idx) {

    BTreeNode* child =
        C[idx];

    BTreeNode* sibling =
        C[idx - 1];

    child->keys.insert(
        child->keys.begin(),
        keys[idx - 1]);

    if (!child->leaf) {

        child->C.insert(
            child->C.begin(),
            sibling->C.back());

        sibling->C.pop_back();
    }

    keys[idx - 1] =
        sibling->keys.back();

    sibling->keys.pop_back();
}

void BTreeNode::borrowFromNext(
    int idx) {

    BTreeNode* child =
        C[idx];

    BTreeNode* sibling =
        C[idx + 1];

    child->keys.push_back(
        keys[idx]);

    if (!child->leaf) {

        child->C.push_back(
            sibling->C.front());

        sibling->C.erase(
            sibling->C.begin());
    }

    keys[idx] =
        sibling->keys.front();

    sibling->keys.erase(
        sibling->keys.begin());
}

void BTreeNode::merge(int idx) {

    BTreeNode* child =
        C[idx];

    BTreeNode* sibling =
        C[idx + 1];

    child->keys.push_back(
        keys[idx]);

    for (int k : sibling->keys)
        child->keys.push_back(k);

    if (!child->leaf) {

        for (BTreeNode* c :
             sibling->C)

            child->C.push_back(c);
    }

    keys.erase(
        keys.begin() + idx);

    C.erase(
        C.begin() + idx + 1);

    delete sibling;
}

void BTree::remove(int k) {

    if (!root)
        return;

    root->remove(k);

    if (root->keys.size() == 0) {

        BTreeNode* tmp =
            root;

        if (root->leaf)
            root = nullptr;
        else
            root = root->C[0];

        delete tmp;
    }
}

int main() {

    BTree tree(3);
    vector<int> datos = {
        10,20,5,6,12,
        30,7,17,3,4,
        40,50,60
    };

    cout << "INSERTANDO\n";
    for (int x : datos) {

        tree.insert(x);
        cout << "\nDespues de insertar "
             << x << endl;
        tree.traverse();
    }

    vector<int> borrar = { 6,7,12,20 };

    for (int x : borrar) {
        cout << "\nEliminando "
             << x << endl;
        tree.remove(x);
        tree.traverse();
    }

    return 0;
}