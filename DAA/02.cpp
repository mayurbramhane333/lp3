#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

// A Huffman tree node
struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;

    Node(char character, int frequency) : ch(character), freq(frequency), left(nullptr), right(nullptr) {}
};

// Comparison object to be used in the priority queue
struct Compare {
    bool operator()(Node* left, Node* right) {
        return left->freq > right->freq;
    }
};

// Recursive function to generate Huffman codes
void generateCodes(Node* root, string code, unordered_map<char, string>& huffmanCode) {
    if (root == nullptr)
        return;

    // Leaf node, store the code
    if (!root->left && !root->right) {
        huffmanCode[root->ch] = code;
    }

    generateCodes(root->left, code + "0", huffmanCode);
    generateCodes(root->right, code + "1", huffmanCode);
}

// Build Huffman Tree and generate codes
unordered_map<char, string> huffmanCoding(const string& text) {
    // Calculate frequency of each character
    unordered_map<char, int> freq;
    for (char ch : text) {
        freq[ch]++;
    }

    // Priority queue to store live nodes of the Huffman tree
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Create a leaf node for each character and add it to the priority queue
    for (auto pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }

    // Iterate until there is only one node in the queue
    while (pq.size() != 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        int sum = left->freq + right->freq;
        Node* node = new Node('\0', sum);  // '\0' is a placeholder for internal nodes
        node->left = left;
        node->right = right;
        pq.push(node);
    }

    // Root node is the last node in the priority queue
    Node* root = pq.top();

    // Traverse the Huffman tree to generate codes
    unordered_map<char, string> huffmanCode;
    generateCodes(root, "", huffmanCode);

    return huffmanCode;
}

int main() {
    string text = "AAAABBBBBBBCCCDDEEEE";

    unordered_map<char, string> huffmanCode = huffmanCoding(text);

    cout << " Char | Huffman Code \n";
    cout << "----------------------\n";
    for (char ch : text) {
        if (huffmanCode.find(ch) != huffmanCode.end()) {
            cout << " " << ch << "    | " << huffmanCode[ch] << '\n';
            huffmanCode.erase(ch);  // To avoid duplicate printing
        }
    }

    return 0;
}
