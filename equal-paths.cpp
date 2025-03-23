#ifndef RECCHECK
#include <algorithm>

#endif

#include "equal-paths.h"
using namespace std;


int checkDepth(Node * root);


bool equalPaths(Node * root)
{
    return (checkDepth(root) != -1);
}

int checkDepth(Node * root)
{
    if (root == nullptr)
        return 0;
    
    int leftDepth = checkDepth(root->left);
    int rightDepth = checkDepth(root->right);
    
    if (leftDepth == -1 || rightDepth == -1)
        return -1;
    if (leftDepth != 0 && rightDepth != 0 && leftDepth != rightDepth)
        return -1;
    return max(leftDepth, rightDepth)+1;
}