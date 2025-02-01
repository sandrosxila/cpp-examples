#include <bits/stdc++.h>
using namespace std;

class HuffmanTree{
  private:
  struct Node {
    char data;
    int frequency;

    Node *left = nullptr;
    Node *right = nullptr;

    Node(char data, int frequency) : data(data), frequency(frequency) {}
    Node(char data, int frequency, Node *left, Node *right) : data(data), frequency(frequency), left(left), right(right) {}
    ~Node() {
      delete left;
      delete right;
    }
  } *root;

  struct Compare {
    bool operator()(Node* a, Node* b) {
      return a->frequency > b->frequency;
    };
  };

  void build(const string &text) {
    unordered_map<char, int> freq;
    for(auto letter : text) {
      freq[letter]++;
    }

    priority_queue<Node*, vector<Node*>, Compare> pq;

    for(auto &[letter, frequency] : freq) {
      pq.push(new Node(letter, frequency));
    }

    while(pq.size() > 1) {
      Node *left = pq.top();
      pq.pop();
      Node *right = pq.top();
      pq.pop();

      Node *parent = new Node('$', left->frequency + right->frequency, left, right);
      pq.push(parent);
    }

    root = pq.top();
    pq.pop();
  }

  void fillCodes(Node *current, string& s, vector<pair<char, string>> &codes) {
    if(current->data != '$') {
      codes.push_back({current->data, s});
      return; 
    }

    s += "0";
    fillCodes(current->left, s, codes);
    s.pop_back();

    s += "1";
    fillCodes(current->right, s, codes);
    s.pop_back();
  }

  public:
  HuffmanTree(string text) {
    build(text);
  }

  vector<pair<char, string>> getCodes() {
    vector<pair<char, string>> codes;
    string s;
    fillCodes(root, s, codes);

    return codes;
  }

  ~HuffmanTree() {
    delete root;
    root = nullptr;
  }
};

int main() {
  string text = "abracadabra";

  HuffmanTree h(text);

  for(auto &[letter, code] : h.getCodes()) {
    cout << letter << " : " << code << endl;
  }

  return 0;
}
