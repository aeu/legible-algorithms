#include <stdio.h>
#include "Justifier.h"

Justifier::Justifier(std::vector<std::string> input_words)
{
    words = input_words;
}

int Justifier::dumpWordList(int start_position, int end_position )
{
    int current_word_index = start_position;
    std::string current_word;
    while( current_word_index <= end_position )
    {
        current_word = words[current_word_index];
        printf("%s ", current_word.c_str());
        current_word_index++;
    }
    printf("\n");
}

int Justifier::wordLengthOnlyForRange(int start_position, int end_position)
{
    if( end_position < start_position )
    {
        printf("\tInvalid range\n");
        return -1;
    }
    int total_length = 0;
    int current_word_index = start_position;
    std::string current_word;
    while( current_word_index <= end_position )
    {
        current_word = words[current_word_index];
        total_length += current_word.length();
        current_word_index++;
    }
    return total_length;
}

int Justifier::minimumLengthForRange(int start_position, int end_position)
{
    if( end_position < start_position )
    {
        printf("\tInvalid range\n");
        return -1;
    }
    int total_length = 0;
    int current_word_index = start_position;

    std::string current_word;
    while(( current_word_index <= end_position )
          && ( current_word_index < words.size()))
    {
        if( total_length > 0 )
            total_length += 1;
        
        current_word = words[current_word_index];
        total_length += current_word.size();
        current_word_index++;
    }
    return total_length;
}


int Justifier::dumpJustifiedLine(int start_position, int end_position, int justification_width )
{
    int gap_count            = end_position - start_position;
    if( gap_count == 0 )
        gap_count = 1;
    int length_of_words_only = wordLengthOnlyForRange(start_position, end_position);
    int space_to_be_filled   = justification_width - length_of_words_only;
    int average_space        = space_to_be_filled / gap_count ;
    int first_space          = average_space + ( space_to_be_filled % gap_count );

    // if it's the last line we don't need to do the justification
    if( end_position == ( words.size() -1 ))
    {
        average_space = 1;
        first_space = average_space;
    }

    int current_word_index = start_position;
    std::string current_word;
    bool first_time = true;

    printf("\"", current_word.c_str());
    while( current_word_index <= end_position )
    {
        current_word = words[current_word_index];
        printf("%s", current_word.c_str());
        if( first_time )
        {
            first_time = false;
            if( first_space > 0 )
                printf("%s", std::string(first_space,' ').c_str());
        }
        else if( current_word_index != end_position )
        {
            if( average_space > 0 )
                printf("%s", std::string(average_space,' ').c_str());
        }
        current_word_index++;
    }
    printf("\"\n");
}

void Justifier::dumpWords(int start_point, int justification_width)
{
    bool first_time = true;
    int length_so_far = 0;
    std::string current_word;
    printf("\"", current_word.c_str());
    for(int current_word_index = start_point;
        current_word_index < words.size();
        current_word_index++ )
    {
        if( first_time == false )
        {
            printf(" ");
            length_so_far++;
        }
        
        current_word = words[current_word_index];
        length_so_far += current_word.length();
        printf("%s", current_word.c_str());
        if( first_time == true )
        {
            first_time = false;
        }
    }
    int remaining_space = justification_width - length_so_far;
    printf("%s", std::string(remaining_space,' ').c_str());
    printf("\"\n");
}

void Justifier::debug()
{
    minimumLengthForRange(0,  0);
    minimumLengthForRange(0,  1);
    minimumLengthForRange(1,  5);
    minimumLengthForRange(3,  9);
    minimumLengthForRange(2,  7);

    printf("\n\n\n");
    
    wordLengthOnlyForRange(0,  0);
    wordLengthOnlyForRange(0,  1);
    wordLengthOnlyForRange(1,  5);
    wordLengthOnlyForRange(0,  0);
    wordLengthOnlyForRange(0, -1);


}

void Justifier::justify(int justification_width)
{
    int min_line_length;
    int line_start       = 0;
    int line_end         = 0;
    int last_word_dumped = 0;

    while( line_end < words.size() )
    {
        min_line_length = minimumLengthForRange(line_start, line_end);
        if( min_line_length > justification_width )
        {
            line_end--;
            dumpJustifiedLine(line_start, line_end, justification_width);
            last_word_dumped = line_end;
            line_start = line_end+1;
            line_end = line_start;
        }
        else
        {
            line_end++;
        }
    }
    dumpWords(last_word_dumped+1, justification_width);
}
