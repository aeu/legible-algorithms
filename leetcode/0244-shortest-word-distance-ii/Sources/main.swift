// -- Mode: swift; tab-width: 4; indent-tabs-mode: nil; --
//
// red82 // software
//
// This software may not be used or reproduced, in whole or in part,
// without the express written permission of red82


class WordDistance {

    var myWords: [String] = []

    init(_ wordsDict: [String]) {
        for current in wordsDict {
            myWords.append(current)
        }
    }
    
    func shortest(_ word1: String, _ word2: String) -> Int {
        var word1_pos = -1
        var word2_pos = -1
        var distance = myWords.count
        for (index,current) in myWords.enumerated() {
            if current == word1 {
                word1_pos = index
            } else if current == word2 {
                word2_pos = index
            }
            if  ( word1_pos != -1 ) && ( word2_pos != -1 ) {
                let curdis = abs( word1_pos - word2_pos )
                distance = min(distance, curdis)
            }
        }
        return distance
    }
}
