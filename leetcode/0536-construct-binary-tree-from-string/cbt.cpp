// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#include <iostream>
#include <optional>
#include <vector>
#include <queue>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <limits.h>


struct TreeNode {
    int val;
    TreeNode  *left;
    TreeNode  *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *parser(std::string s, int &current_pos)
{
    int start = current_pos;
    char curr = s[current_pos];
    if( curr == '-' )
        current_pos++;
    while(( current_pos < s.size() ) && ( isdigit( s[current_pos])))
        current_pos++;
    std::string nvals = s.substr( start, current_pos - start ) ;
    int nvali = std::stoi( nvals );

    TreeNode *root = new TreeNode( nvali );
    
    if(( current_pos < s.size()) && ( s[current_pos] == '(' ))
    {
        current_pos++;
        root->left = parser(s, current_pos );
        current_pos++;
    }
    if(( current_pos < s.size()) && ( s[current_pos] == '(' ))
    {
        current_pos++;
        root->right = parser(s, current_pos );
        current_pos++;
    }
    return root;
}


TreeNode *str2tree(std::string s)
{
    std::cout << "str2tree : " << s << std::endl;
    int current_pos = 0;
    TreeNode *root = parser(s,current_pos);
    std::cout << "cpos : " << current_pos << std::endl;
    return root;
}
        

int main(int argc, char **argv)
{
    std::cout << std::endl << "0536-construct-binary-tree-from-string" << std::endl << std::endl;
    int test_case = 1;
    {
        std::string s = "4(2(3(1))(6(5))";
        TreeNode *root = str2tree(s);
        int expected = 0;
        int result = 0;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "4(2(3)(1))(6(5)(7))";
        TreeNode *root = str2tree(s);
        int expected = 0;
        int result = 0;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "-4(2(3)(1))(6(5)(7))";
        TreeNode *root = str2tree(s);
        int expected = 0;
        int result = 0;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
