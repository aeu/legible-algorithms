// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#include <iostream>
#include <iomanip>
#include <optional>
#include <vector>
#include <queue>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <limits.h>

void dumpValues(std::vector<std::string> values)
{
    for(auto curr : values )
    {
        std::cout << curr << " ";
    }
    std::cout << std::endl;
}

int find(int x, std::vector<int> &parent)
{
    if( parent[x] != x )
        parent[x] = find(parent[x],parent);
    return parent[x];
}


void unite(int x,int y, std::vector<int> &parent)
{
    int px = find(x,parent);
    int py = find(y,parent);
    if( px != py )
        parent[px] = py;
}



std::vector<std::vector<std::string>> accountsMerge(std::vector<std::vector<std::string>> &accounts)
{
    std::unordered_map<std::string,int> email_to_id;
    std::unordered_map<std::string,std::string> email_to_name;
    std::vector<std::string> id_to_email;
    std::vector<int> parent;
    std::unordered_map<int,std::vector<std::string>> final_groupings;
    for(auto const &curr : accounts )
    {
        std::string name = curr[0];
        for(int index=1;index<curr.size();index++)
        {
            auto eti_iterator = email_to_id.find( curr[index] );
            if( eti_iterator == email_to_id.end() )
            {
                id_to_email.push_back( curr[index] );
                int id = id_to_email.size()-1;
                email_to_id[ curr[index] ] = id;
                email_to_name[curr[index]] = name;
            }
        }
    }
    // initialize the union find array
    parent.resize( id_to_email.size());
    for(int index = 0;index<parent.size();index++)
    {
        parent[index] = index;
    }
    // unite all the emails
    for(auto const &account : accounts )
    {
        // because the 0 element is the name.
        int first_id = email_to_id[account[1]];
        for(int index=2;index<account.size();index++)
        {
            int current_id = email_to_id[account[index]];
            unite(first_id, current_id,parent);
        }
    }
    for(auto const &account : accounts )
    {
        for(int index=1;index<account.size();index++)
        {
            int current_id = email_to_id[account[index]];
            int base_id = find(current_id, parent );
            final_groupings[base_id].push_back( account[index] );
            // std::cout << "base ID: " << base_id << " - " << account[index] << std::endl;
        }
    }
    
    std::vector<std::vector<std::string>> retval;
    for(auto &[base_id, emails] : final_groupings )
    {
        std::vector<std::string> person; 
        std::string name;
        std::sort(emails.begin(), emails.end() );
        auto niter = email_to_name.find( emails[0] );
        if( niter != email_to_name.end() )
        {
            name = niter->second;
        }
        person.push_back(name);
        for(const auto &email : emails )
        {
            person.push_back(email);
        }
        retval.push_back(person);
        dumpValues(person);
    }
        
    // now build the return value.
    return retval;
}



    
int main(int argc, char **argv)
{
    std::cout << std::endl << "0721-accounts-merge" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::vector<std::string>> accounts =
            {{"John", "johnsmith@mail.com", "john_newyork@mail.com"},
             {"John", "johnsmith@mail.com", "john00@mail.com"},
             {"Mary", "mary@mail.com"},
             {"John", "johnnybravo@gmail.com"}};

        
        std::vector<std::vector<std::string>> expected =
                {{"John","johnsmith@mail.com", "john_newyork@mail.com","johnsmith@mail.com", "john00@mail.com"},
                 {"Mary", "mary@mail.com"},
                 {"John", "johnnybravo@gmail.com"}};
                 
        std::vector<std::vector<std::string>> result = accountsMerge( accounts );
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::vector<std::vector<std::string>> accounts =
            {{"Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"},{"Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"},{"Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"},{"Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"},{"Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"}};
        
        std::vector<std::vector<std::string>> expected =
                {{"John","johnsmith@mail.com", "john_newyork@mail.com","johnsmith@mail.com", "john00@mail.com"},
                 {"Mary", "mary@mail.com"},
                 {"John", "johnnybravo@gmail.com"}};
                 
        std::vector<std::vector<std::string>> result = accountsMerge( accounts );
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    return 0;
}




