bool isValidIp(const std::string candidate)
{
    if( candidate.length() <= 0 )
        return false;
    if( candidate.length() > 3 )
        return false;
    if( ( candidate[0] == '0') && candidate.length() > 1 )
        return false;
    long ip = std::stol( candidate );
    if( ( ip < 0 ) || ( ip > 255 ))
        return false;
    if( ( ip > 0 ) && ( candidate[0] == '0' ))
        return false;
    return true;
}


// standard backtrack pattern
// setup
//    solution vector
//    return vecbtor
//    initial call to backtrack
//
// backtrack
//    check if the solution is valid
//    loop through the string starting at the current position
//       next is valid
//       push to solution
//       backtrack, increment start point on string
//       pop from solution
//

void backtrace(int start_index,
               std::string s,
               std::vector<std::string> &solution,
               std::vector<std::string> &retval)
{
    // all characters have been used
    if( start_index == s.length() )
    {
        // is comprised of 4 strings, so a valid IP
        if( solution.size() == 4 )
        {
            std::string ip = solution[0] + "."
                + solution[1] + "."
                + solution[2] + "."
                + solution[3];
            retval.push_back(ip);
        }
    }

    for(int index=start_index;index<s.length();index++)
    {
        std::string curr = s.substr(start_index,index-start_index+1);

        if(isValidIp(curr ))
        {
            solution.push_back(curr);
            backtrace(index+1,s,solution,retval);
            solution.pop_back();
        }
    }
}


std::vector<std::string> restoreIpAddresses(std::string s)
{
    std::vector<std::string> retval;
    std::vector<std::string> solution;
    backtrace(0,s,solution,retval);
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "LC0093 - Restore IP Addresses" << std::endl << std::endl;
    int test_case = 1;
    {
        std::string s = "25525511135";
        std::vector<std::string> expected = {"255.255.11.135","255.255.111.35"};
        std::vector<std::string> result   = restoreIpAddresses(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        //   std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
