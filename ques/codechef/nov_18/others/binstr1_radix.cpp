#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class PrefixTree;

class Node {
    friend PrefixTree;
    public:
        Node();
        Node(char, int);
        Node(char, int, int);
        Node(char, int, int, string&);

        char getValue() const;
        int getLevel() const;

        char getChoice(string&) const;
        Node* followChoice(char);
        Node* reverseChoice(char);
        void connect(Node*);

        vector <int>::iterator find(vector <int>::iterator, vector <int>::iterator, int, int);

        void traceNode(ostream&, Node*);
    private:
        char m_value;
        string m_tail;
        int m_level;
        vector <int> m_indices;
        Node* mptr_high;
        Node* mptr_low;

};

class PrefixTree {
    public:
        PrefixTree();
        void insert(string&, int);

        int xorMax(int, int, string&) const;

        void trace(ostream&);
    private:
        Node* mptr_root;
};

int main()
{
    srand(0);
    ios_base::sync_with_stdio(false);
    int N, Q;
    cin >> N >> Q;
    string str;
    PrefixTree tree;
    for (int i = 1; i <= N; i++) {
        cin >> str;
        int leadingZeros = 0;
        for (int j = 0; j < (int)str.length(); j++)
            if (str[j] == '0')
                leadingZeros++;
            else
                break;
        str.erase(0, leadingZeros);
        tree.insert(str, i);
    }

    int L = 1, R = 0;
    for (int i = 0; i < Q; i++) {
        cin >> L >> R >> str;
        int leadingZeros = 0;
        for (int j = 0; j < (int)str.length(); j++)
            if (str[j] == '0')
                leadingZeros++;
            else
                break;
        str.erase(0, leadingZeros);
        cout << tree.xorMax(L, R, str) << '\n';
    }
}

Node::Node() {
    mptr_high = nullptr;
    mptr_low = nullptr;
}

Node::Node(char value, int level) : Node() {
    m_value = value;
    m_level = level;
}

Node::Node(char value, int level, int index) : Node() {
    m_value = value;
    m_level = level;
    m_indices.push_back(index);
}

Node::Node(char value, int level, int index, string& tail) : Node() {
    m_value = value;
    m_level = level;
    m_indices.push_back(index);
    m_tail = tail;
}

char Node::getValue() const {
    return m_value;
}

int Node::getLevel() const {
    return m_level;
}

char Node::getChoice(string& str) const {
    if (getLevel() > (int)str.length()+1) return '0';
    else return str[str.length()+1-getLevel()];
}

Node* Node::followChoice(char choice) {
    if (choice == '0') return mptr_low;
    else return mptr_high;
}

Node* Node::reverseChoice(char choice) {
    if (choice == '1') return mptr_low;
    else return mptr_high;
}

void Node::connect(Node* target) {
    if (target->m_value == '1') mptr_high = target;
    else mptr_low = target;
}

vector <int>::iterator Node::find(vector <int>::iterator leftSearchBound, vector <int>::iterator rightSearchBound, int leftBound, int rightBound) {
    if (*leftSearchBound >= leftBound)
    {
        if (*leftSearchBound > rightBound)
            return m_indices.end();
        else
            return leftSearchBound;
    }
    if (*rightSearchBound <= rightBound)
    {
        if (*rightSearchBound < leftBound)
            return m_indices.end();
        else
            return rightSearchBound;
    }
    double guessValue = ((rightBound+leftBound)/2-*leftSearchBound)/double(*rightSearchBound-*leftSearchBound);
    vector <int>::iterator guess = leftSearchBound+int((rightSearchBound-leftSearchBound)*guessValue);
    if (guess == leftSearchBound || guess == rightSearchBound)
    {
        for (auto& term = leftSearchBound; term <= rightSearchBound; term++)
        {
            if (*term >= leftBound && *term <= rightBound)
                return term;
        }
        return m_indices.end();
    }
    if (*guess < leftBound)
    {
        return find(guess, rightSearchBound, leftBound, rightBound);
    }
    else if (*guess > rightBound)
    {
        return find(leftSearchBound, guess, leftBound, rightBound);
    }
    else
        return guess;
}

PrefixTree::PrefixTree() {
    mptr_root = new Node('0', 0);
}

void PrefixTree::insert(string& value, int index)
{
    if (mptr_root->m_level <= (int)value.length())
    {
        Node* temp = mptr_root;
        mptr_root = new Node('0', value.length()+1);
        for (auto& term: temp->m_indices)
            mptr_root->m_indices.push_back(term);
        mptr_root->m_indices.push_back(index);
        mptr_root->mptr_low = temp;
        mptr_root->mptr_high = new Node('1', value.length(), index, value);
        return;
    }
    else
    {
        Node* target = mptr_root;
        target->m_indices.push_back(index);
        while (target->getLevel() != (int)value.length()+1)
        {
            if (target->mptr_low->getLevel() <= (int)value.length())
            {
                Node* temp = target;
                target = new Node('0', value.length()+1);
                for (auto& term: temp->mptr_low->m_indices)
                    target->m_indices.push_back(term);
                target->m_indices.push_back(index);
                target->mptr_low = temp->mptr_low;
                target->mptr_high = new Node('1', value.length(), index, value);
                temp->mptr_low = target;
                return;
            }
            else
            {
                target = target->mptr_low;
                target->m_indices.push_back(index);
            }
        }
        do {
            char choice = target->getChoice(value);
            Node* next = target->followChoice(choice);
            if (next == nullptr) {
                if (target->reverseChoice(choice) != nullptr) {
                    next = new Node(choice, target->getLevel()-1, index, value);
                    target->connect(next);
                    return;
                }
                else {
                    string& tail = target->m_tail;
                    int& altIndex = target->m_indices[0];
                    while (target->getChoice(value) == target->getChoice(tail))
                    {
                        next = new Node(target->getChoice(value), target->getLevel()-1, altIndex);
                        next->m_indices.push_back(index);
                        target->connect(next);
                        target = next;
                        if (next->getLevel() == 1)
                            return;
                    }
                    next = new Node(target->getChoice(value), target->getLevel()-1, index, value);
                    target->connect(next);
                    next = new Node(target->getChoice(tail), target->getLevel()-1, altIndex, tail);
                    target->connect(next);
                    return;
                }
            }
            if (next->getLevel() == 1) {
                next->m_indices.push_back(index);
                return;
            }
            target = next;
            target->m_indices.push_back(index);
        } while (true);
    }

}

int PrefixTree::xorMax(int leftBound, int rightBound, string& key) const {
    Node* target = mptr_root;
    while (target->m_level != 1)
    {
        char choice = target->getChoice(key);
        Node* next = target->reverseChoice(choice);
        if (next == nullptr) {
            target = target->followChoice(choice);
            continue;
        }
        vector <int>::iterator test;
        if (next->getLevel() == 0)
            test = next->m_indices.end();
        else
            test = next->find(next->m_indices.begin(), next->m_indices.end()-1, leftBound, rightBound);
        if (test == next->m_indices.end())
            target = target->followChoice(choice);
        else if ((test != next->m_indices.begin() && (*(test-1)) >= leftBound) ||
                 (test != next->m_indices.end()-1 && (*(test+1)) <= rightBound))
            target = next;
        else
            return *test;
    }
    auto test = target->find(target->m_indices.begin(), target->m_indices.end(), leftBound, rightBound);
    while ((*(test-1)) >= leftBound && test > target->m_indices.begin())
        test--;
    return *test;
}

void Node::traceNode(ostream& out, Node* nptr) {
    if (nptr == nullptr) {
        out << "Null\n";
        return;
    }
    out << "Value: " << nptr->getValue() << '\n';
    out << "Level: " << nptr->getLevel() << '\n';
    out << "Indices:\n";
    for (auto term: nptr->m_indices)
        out << term << ' ';
    out << '\n';
    traceNode(out, nptr->mptr_high);
    traceNode(out, nptr->mptr_low);
}

void PrefixTree::trace(ostream& out) {
    mptr_root->traceNode(out, mptr_root);
}
