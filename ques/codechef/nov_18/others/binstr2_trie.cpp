#include <bits/stdc++.h>

using namespace std;

struct Trie
{
    struct Trie *children[2];
    vector<long int> range;
};

const int NN = 1e6 + 9;
const int N = 1e6 + 9;
struct Trie *T[NN];
long int LengthC[NN] = {0};
long int Length[N] = {0};

long int Next[NN] = {0};

struct Trie *P[NN];
long int Pstart[N];
long int p = 0;

long int SMax[4 * N];
long int SMin[4 * N];

int cmps(string &s1, long int l1, string &s2, long int l2) {
    if (l1 > l2)
        return 1;
    else if (l1 == l2)
        return s1.compare(s2);
    else
        return -1;
}

struct Trie *createNode(void)
{
    struct Trie *v = new Trie;
    v->children[0] = NULL;
    v->children[1] = NULL;
    return v;
}

void build(string &s, long int index) {
    long int l = Length[index];

    if (!T[l]) T[l] = createNode();
    struct Trie *v = T[l];
    v->range.push_back(index);
    P[p] = v;
    p++;

    long int i = 1;
    while (i < l) {
        int b = s[i] - '0';
        if (!v->children[b]) v->children[b] = createNode();
        v = v->children[b];
        v->range.push_back(index);
        P[p] = v;
        p++;
        i++;
    }
}

void buildSMax(vector<string> &S, long int l, long int r, long int id = 1) {
    if (r - l < 2) { //  l + 1 == r
        SMax[id] = l;
        return;
    }

    long int mid = (l + r) / 2;
    buildSMax(S, l, mid, id * 2);
    buildSMax(S, mid, r, id * 2 + 1);
    SMax[id] = cmps(S[SMax[id * 2]], Length[SMax[id * 2]], S[SMax[id * 2 + 1]], Length[SMax[id * 2 + 1]]) > 0
                   ? SMax[id * 2]
                   : SMax[id * 2 + 1];
}

long int maxS(vector<string> &S, long int x, long int y, long int l, long int r, long int id = 1) {
    if (x >= r || l >= y) return -1;

    if (x <= l && r <= y) return SMax[id];

    long int mid = (l + r) / 2;

    long int K1 = maxS(S, x, y, l, mid, id * 2);
    long int K2 = maxS(S, x, y, mid, r, id * 2 + 1);

    if (K1 == -1)
        return K2;
    else if (K2 == -1)
        return K1;
    else
        return cmps(S[K2], Length[K2], S[K1], Length[K1]) > 0 ? K2 : K1;
}

void buildSMin(vector<string> &S, long int l, long int r, long int id = 1) {
    if (r - l < 2) { //  l + 1 == r
        SMin[id] = l;
        return;
    }

    long int mid = (l + r) / 2;
    buildSMin(S, l, mid, id * 2);
    buildSMin(S, mid, r, id * 2 + 1);
    SMin[id] = cmps(S[SMin[id * 2]], Length[SMin[id * 2]], S[SMin[id * 2 + 1]], Length[SMin[id * 2 + 1]]) < 0
                   ? SMin[id * 2]
                   : SMin[id * 2 + 1];
}

long int minS(vector<string> &S, long int x, long int y, long int l, long int r, long int id = 1) {
    if (x >= r || l >= y) { return -1; }

    if (x <= l && r <= y) { return SMin[id]; }

    long int mid = (l + r) / 2;

    long int K1 = minS(S, x, y, l, mid, id * 2);
    long int K2 = minS(S, x, y, mid, r, id * 2 + 1);

    if (K1 == -1) {
        return K2;
    } else if (K2 == -1) {
        return K1;
    } else {
        return cmps(S[K2], Length[K2], S[K1], Length[K1]) > 0 ? K1 : K2;
    }
}

long int findL(vector<long int> &v, long int x, long int start, long int end) {
    if (start < end) {
        long long mid = start + (end - start) / 2;

        if (v[mid] == x) {
            return mid;
        } else if ((v[mid] > x) && ((mid - 1) >= 0) && (v[mid - 1] < x)) {
            return mid;
        } else if (v[mid] > x) {
            return findL(v, x, start, mid);
        } else {
            return findL(v, x, mid + 1, end);
        }
    } else if ((start == end) && (v[start] >= x)) {
        return start;
    }

    return -1;
}

long int findR(vector<long int> &v, long int x, long int start, long int end) {
    if (start < end) {
        long long mid = start + (end - start) / 2;

        if (v[mid] == x) {
            return mid;
        } else if ((v[mid] < x) && ((mid + 1) < (int)v.size()) && (v[mid + 1] > x)) {
            return mid;
        } else if (v[mid] > x) {
            return findR(v, x, start, mid);
        } else {
            return findR(v, x, mid + 1, end);
        }
    } else if ((start == end) && (v[start] <= x)) {
        return start;
    }

    return -1;
}

long int findLR(struct Trie *v, long int l, long int r) {
    if (!v) { return -1; }

    long int s = v->range.size();
    long int posl = findL(v->range, l, 0, s - 1);
    long int posr = findR(v->range, r, 0, s - 1);

    if ((posl != -1) && (posr != -1) && (posl <= posr)) { return v->range[posl]; }

    return -1;
}

long int findBinStr(struct Trie *v, string &X, long int XLength, long int start, long int L, long int R) {
    long int posl;
    int Xb;

    while (start < XLength) {
        Xb = X[start] - '0';

        if (!v->children[Xb]) {
            v = v->children[1 - Xb];
        } else if (!v->children[1 - Xb]) {
            v = v->children[Xb];
        } else {
            posl = findLR(v->children[1 - Xb], L, R);

            if (posl != -1) {
                v = v->children[1 - Xb];
            } else {
                v = v->children[Xb];
            }
        }

        start++;
    }

    return findLR(v, L, R);
}

int main() {
    long int N;
    long int Q;
    cin >> N >> Q;

    vector<string> S(N);
    for (long int i = 0; i < N; ++i) { cin >> S[i]; }

    long int maxL = 0;
    long int l;
    for (long int i = 0; i < N; ++i) {
        l = S[i].length();
        Length[i] = l;
        LengthC[l]++;
        if (l > maxL) { maxL = l; }
    }
    for (long int i = 1; i <= maxL; ++i) {
        if (LengthC[i] > 0) { T[i] = NULL; }
    }

    for (long int i = 0; i < N; ++i) {
        Pstart[i] = p;
        build(S[i], i);
    }

    buildSMax(S, 0, N);
    buildSMin(S, 0, N);

    long int L, R, maxI, maxLRLength, minI, minLRLength, XLength;
    string X, maxLR, minLR;
    long int offset, start, pos;
    int b;

    for (long int i = 0; i < Q; ++i) {
        cin >> L >> R >> X;

        maxI = maxS(S, L - 1, R, 0, N);
        maxLR = S[maxI];
        maxLRLength = Length[maxI];

        minI = minS(S, L - 1, R, 0, N);
        string minLR = S[minI];
        minLRLength = Length[minI];

        XLength = X.length();

        if (XLength < maxLRLength) {
            offset = maxLRLength - (XLength + 1);
            b = maxLR[offset] - '0';
            cout << findBinStr(P[Pstart[maxI] + offset], X, XLength, 0, L - 1, R - 1) + 1;
        } else {
            start = XLength - maxLRLength;
            while (start <= (XLength - minLRLength)) {
                if (X[start] == '0') {
                    pos = findLR(T[XLength - start], L - 1, R - 1);
                    if (pos != -1) {
                        cout << findBinStr(T[XLength - start], X, XLength, start + 1, L - 1, R - 1) + 1;
                        break;
                    }
                } else if (start == (XLength - minLRLength)) {
                    cout << findBinStr(T[XLength - start], X, XLength, start + 1, L - 1, R - 1) + 1;
                }
                start++;
            }
        }

        if (i != Q - 1) { cout << endl; }
    }
}
