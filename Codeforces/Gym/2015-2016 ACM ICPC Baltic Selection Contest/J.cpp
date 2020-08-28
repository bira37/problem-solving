#include <iostream>
#include <vector>

using namespace std;

template <class T>
class SplayTree {
 public:
  struct SplayNode {
    SplayNode *parent, *child[2];
    int subtree_sz;
    T value;
    SplayNode(T value) {
      parent = nullptr;
      subtree_sz = 1;
      this->value = value;
      child[0] = nullptr;
      child[1] = nullptr;
    }
    SplayNode(SplayNode* parent, SplayNode* lef, SplayNode* rig, T value) {
      this->parent = parent;
      this->value = value;
      child[0] = lef;
      child[1] = rig;
      subtree_sz = 1;
    }
  };

  SplayNode* create(T value) { return new SplayNode(value); }

  SplayNode* get_root() { return root; }

  int subtree_size(SplayNode* cur) { return (cur ? cur->subtree_sz : 0); }

  void splay(SplayNode* cur) {
    while (cur->parent) {
      SplayNode* p = cur->parent;
      if (p->parent && get_id(p) == get_id(cur)) _rotate(p);
      _rotate(cur);
    }
    _update_subtree_size(cur);
  }

  void insert(SplayNode* const x) {
    if (!root) {
      root = x;
      return;
    }
    SplayNode* cur = root;
    while (true) {
      SplayNode*& nxt = cur->child[x->value > cur->value];
      if (!nxt) {
        nxt = x;
        nxt->parent = cur;
        splay(nxt);
        return;
      } else {
        cur = nxt;
      }
    }
  }

  void remove(SplayNode* const x) {
    splay(x);

    if (!x->child[0] && !x->child[1]) {
      root = nullptr;
    } else if (!x->child[0]) {
      root = x->child[1];
    } else if (!x->child[1]) {
      root = x->child[0];
    } else {
      SplayNode* nxt = x->child[0];
      while (nxt->child[1]) nxt = nxt->child[1];
      splay(nxt);
      nxt->child[1] = x->child[1];
      x->child[1]->parent = nxt;
      root = nxt;
    }
    if (root) root->parent = nullptr;
  }

  SplayNode* find_one(T value) {
    SplayNode* cur = root;
    while (cur && cur->value != value) {
      SplayNode* const nxt = cur->child[cur->value < value];
      if (!nxt) splay(cur);
      cur = nxt;
    }
    return cur;
  }

  // 1-based
  SplayNode* find_kth(int kth) {
    SplayNode* cur = root;
    while (cur) {
      int sz = subtree_size(cur->child[0]);
      if (sz + 1 == kth) return cur;
      if (kth <= sz) {
        cur = cur->child[0];
      } else {
        kth -= sz;
        cur = cur->child[1];
      }
    }
    return cur;
  }

 private:
  SplayNode* root;
  bool get_id(SplayNode* cur) { return cur == cur->parent->child[1]; }

  void _rotate(SplayNode* cur) {
    SplayNode* p = cur->parent;
    int id = get_id(cur);
    _set_child(p, cur->child[!id], id);
    if (p->parent) {
      _set_child(p->parent, cur, get_id(p));
    } else {
      cur->parent = nullptr;
      root = cur;
    }
    _set_child(cur, p, !id);
    _update_subtree_size(p);
  }

  void _update_subtree_size(SplayNode* cur) {
    if (!cur) return;
    cur->subtree_sz =
        subtree_size(cur->child[0]) + 1 + subtree_size(cur->child[1]);
  }

  void _set_child(SplayNode* u, SplayNode* v, int ch) {
    u->child[ch] = v;
    if (v) v->parent = u;
  }
};

int main() {
  auto st = SplayTree<int>();
  int q;
  cin >> q;
  vector<SplayTree<int>::SplayNode*> v;
  int desc = -1, cresc = 1;
  while (q--) {
    char c;
    cin >> c;
    if (c == 'F') {
      v.push_back(st.create(desc--));
      st.insert(v.back());
    } else if (c == 'B') {
      v.push_back(st.create(cresc++));
      st.insert(v.back());
    } else {
      int x;
      cin >> x;
      x--;
      st.splay(v[x]);
      cout << min(st.subtree_size(v[x]->child[0]),
                  st.subtree_size(v[x]->child[1]))
           << endl;
      swap(v[x]->child[0], v[x]->child[1]);
      st.remove(v[x]);
    }
  }
}
