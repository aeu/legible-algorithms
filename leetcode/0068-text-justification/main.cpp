#include <stdio.h>
#include <string.h>
#include <string>
#include <list>
#include "Justifier.h"

int main(int argc, char **argv)
{
    char splitter[2] = " ";
    char *token;
    {
        std::vector<std::string> words;
        char input[]  = "This is an example of text justifcation.";
        
        token = strtok( input, splitter );
        while( token != NULL )
        {
            std::string new_word(token);
            words.push_back(new_word);
            token = strtok(NULL, splitter);
        }
        
        Justifier one = Justifier( words );
        one.justify( 16 );
    }
    printf("\n\n\n");
    {
        std::vector<std::string> words;
        char input[]  = "What must be acknowledgment shall be";
        
        token = strtok( input, splitter );
        while( token != NULL )
        {
            std::string new_word(token);
            words.push_back(new_word);
            token = strtok(NULL, splitter);
        }
        
        Justifier one = Justifier( words );
        one.justify( 16 );
    }
    printf("\n\n\n");
    {
        std::vector<std::string> words;
        char input[]  = "Science is what we understand well enough to explain to a computer. Art is everything else we do";
        
        token = strtok( input, splitter );
        while( token != NULL )
        {
            std::string new_word(token);
            words.push_back(new_word);
            token = strtok(NULL, splitter);
        }
        
        Justifier one = Justifier( words );
        one.justify( 20 );
    }

    


}
