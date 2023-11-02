#ifndef JUSTIFIER_H
#define JUSTIFIER_H


#include <list>
#include <string>
#include <array>
#include <vector>

class Justifier {
 public:

    Justifier(std::vector<std::string> words);

    void finalLine(int start_point, int justification_width );
    void justifiedLine(int start_position, int end_position, int justification_width );
    void justify(int width);
    
 protected:

    int minimumLengthForRange(int start_position, int end_position);
    int wordLengthOnlyForRange(int start_position, int end_position);

private:

    std::vector<std::string> words;

};

#endif
