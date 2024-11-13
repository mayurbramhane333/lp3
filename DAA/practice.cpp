#include<bits/stdc++.h>
using namespace std;

struct node{
    char ch;
    int freq;
    node* left;
    node* right;
    node(char character, int frequency): ch(character) , freq(frequency),left(nullptr),right(nullptr);

};

struct compare{
    bool operator()(node* left, node* right){
        return left->freq>right->freq;
    }
};


void generateCodes(node* root , string code , unordered_map<char,string>& huffmanCode)
{
    if(root== nullptr)
        return;

    if(!root->left && !root->right)
    {
        huffmanCode[root->ch]=code;
    }

    generateCodes(root->left, code+'0',huffmanCode);
    generateCodes(root->right, code+'1',huffmanCode);
}


unordered_map<char, string> huffmanCodeing (const string& text)
{
    unordered_map<char , int> freq;
    for(char ch : text){
        freq[ch]++;
    }
}