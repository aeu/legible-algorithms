#ifndef JUSTIFIER_H
#define JUSTIFIER_H


#include <list>
#include <string>
#include <array>
#include <vector>

class Justifier {
 public:

    int dumpWordList(int start_position, int end_position );
    void dumpWords(int start_point, int justification_width );
    int dumpJustifiedLine(int start_position, int end_position, int justification_width );
    int minimumLengthForRange(int start_position, int end_position);
    int wordLengthOnlyForRange(int start_position, int end_position);
    Justifier(std::vector<std::string> words);
    void justify(int width);
    
 protected:
 private:
    void debug();

    std::vector<std::string> words;

};

#endif
