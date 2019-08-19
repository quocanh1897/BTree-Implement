#include "BTree.h"
#include <sstream>
#include <unistd.h>
#include <chrono>

#define DATA_FILE "./datafile.dat"
#define TEST  1000
using namespace std;
using namespace std::chrono; 

int main()
{
    
    BTree *tree = BTreeInit(DATA_FILE, false);
    
    // set(tree, "thoainh", "Nguyen Huynh Thoai");
    // set(tree, "anhnq6", "Nguyen Quoc Anh");
    // set(tree, "nghiatdh","Ta Dang Hieu Nghia");
    // set(tree, "nghianv2","Nguyen Van Nghia");
    // set(tree, "phucnnh", "Ngo Nguyen Hong Phuc");
    // set(tree, "baonlc", "Nguyen le Chi Bao");
    // set(tree, "kiettt4","Trinh Tuan Kiet");
    // set(tree, "namvh3","Vo Huy Nam");
    // set(tree, "tannh","Huynh Minh Tan");

    // traverse(tree, tree->root);

    // // printf("%s",(Kv_pair*)search(tree,"baonlc")->val);
    // cout << get(tree, "baonlc") << endl;


    for (int i = TEST; i > 0; i--){
        stringstream ss;
        ss << i;
        string temp = ss.str();
        char *chartype = (char*)temp.c_str();

        set(tree, chartype , "xaaxxx");
    }
    
    // cout << "Traversal of tree \n";
    // //traverse(tree, tree->root);
    // auto start = high_resolution_clock::now();
    for (int i = 1; i <= TEST; i++){
        stringstream ss;
        ss << i;
        string temp = ss.str();
        char *chartype = (char*)temp.c_str();

        cout << chartype << ": " << get(tree, chartype) << endl;
    }
    
    // auto stop = high_resolution_clock::now(); 
    // auto duration = duration_cast<microseconds>(stop - start); 

    // cout << "TIME SPEC GET: " << duration.count() << "ms"<< endl;

    // start = high_resolution_clock::now();
    // removeFromTree(tree, "192");
    // stop = high_resolution_clock::now(); 
    
    // duration = duration_cast<microseconds>(stop - start); 
    // cout << "TIME SPEC REMOVE: " << duration.count() << "ms"<< endl;

    //traverse(tree, tree->root);


    BTreeClose(tree);
    return 0;
}