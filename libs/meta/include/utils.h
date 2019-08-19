#ifndef _UTILS_
#define _UTILS_

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "BNode.h"
#include "BTree.h"


void nodeInit(BNode *node, bool isLeaf, BTree *tree) {
    
    node->isLeaf = isLeaf;
    node->count = 0;
    node->pos = tree->nextPos;
    tree->nextPos++;
    
    for(int i = 0; i < 2*t; i++) {
        node->children[i] = -1;
    }
    
}

void printFunc(keyValItem *k) {
    
    if(!k) {
        cout << "Record Not Found!!\n\n";
        return;
    }
    
    cout << "\nKey: \n" << k->key;
    cout << "Value: \n" << k->val;
    
}

void diskWrite(BTree* ptrBTree, BNode* p, int pos) {
    // cout << "SIZE of a node: " << sizeof(BNode) << endl;
    if(pos == -1) {
        pos = ptrBTree->nextPos++;
    }

    fseek(ptrBTree->pFile, pos * sizeof(BNode), 0);
    fwrite(p, sizeof(BNode), 1, ptrBTree->pFile);
    // fsync(ptrBTree->pFile);
    
}

void diskRead(BTree* ptrBTree, BNode* p, int pos) {
    
    fseek(ptrBTree->pFile, pos * sizeof(BNode), 0);
    fread(p, sizeof(BNode), 1, ptrBTree->pFile);

}

// string serializeNode(BNode *current)
// {
//     string res = "";
//     /**
//      * int pos;                // position of this node in FILE
//     int count;              // current number of records at each node
//     bool isLeaf;            // true if node is Leaf
//     int t = (T + 1) / 2;    // minimum degree, node can have t-1 to 2t-1 keys
//     int children[T + 1];    // array of positions of child-node in FILE
//     //???BNode<keyValItem> **branch; // point to array of child node 
//     keyValItem keys[T];         // array of records at each node

//      */
//     res += to_string(current->pos) + " " + to_string(current->count) + " " + to_string(current->isLeaf) + " ";

//     string arrChildPos;
//     for (int i : current->children)
//         arrChildPos += to_string(i) + " ";
//     res += arrChildPos;

//     string arrKeys;
//     for (keyValItem i : current->keys)
//         arrKeys += (i.key) + " ";
//     res += arrKeys;

//     return res;
// }

// void deserializeStrToNode(BNode *current, string str)
// {
//     stringstream ss;
//     cout << "inpstr: " << str << endl;
//     ss << str;
//     ss >> current->pos >> current->count >> current->isLeaf;
//     cout << "POS: " << current->pos << " count: " << current->count << " isleaf: " << current->isLeaf << endl;
//     for (int i = 0; i < T + 1; i++)
//     {
//         ss >> current->children[i];
//         cout << "children:__ " << current->children[i] << endl;
//     }

//     for (int j = 0; j < T; j++)
//     {
//         ss >> current->keys[j].key;
//         cout << "keys:__ " << current->keys[j].key << endl;
//     }
// }

// void diskWrite(BNode *current)
// {
//     FILE *f = fopen(DATA_FILE, "wb");

//     fseek(f, 0, SEEK_END);
//     /* Get current pos in FILE*/
//     current->pos = ftell(f);

//     // char buffer[to_string(k).size() +1] ;
//     // strcpy(buffer, to_string(k).c_str());
//     // fwrite(buffer, sizeof(char), sizeof(buffer), f);
//     fwrite(&current->count, sizeof(int), 1, f);
//     fwrite(current->children, sizeof(int), current->count + 1, f);
//     fwrite(current->keys, sizeof(keyValItem), current->count, f);
//     // string temp = serializeNode(current);
//     // cout << endl << "serializeNode: " << endl << temp << endl << "###" << endl;
//     // char buffer[temp.size() + 1];
//     // strcpy(buffer, temp.c_str());
//     // fwrite(buffer, sizeof(char), sizeof(buffer), f);

//     fclose(f);
// }

// string diskRead(int position)
// {
//     FILE *pFile = fopen(DATA_FILE, "rb");
//     char *buffer;

//     fseek(pFile, position, SEEK_SET);
//     long lSize = ftell(pFile);
//     // cout << "lSize " << lSize << endl;
//     // rewind(pFile);

//     buffer = (char *)malloc(sizeof(char) * lSize);
//     size_t res = fread(buffer, 1, lSize, pFile);

//     // cout <<  buffer << endl;
//     string str(buffer);

//     BNode *outNode = new BNode(3, true);
//     deserializeStrToNode(outNode, str);
//     cout << outNode->keys[0].key << endl;
//     cout << "keys[] of outNode: " << endl;
//     for (keyValItem i : outNode->keys)
//         cout << i.key << " ";
//     cout << endl;
//     fclose(pFile);
// }
#endif