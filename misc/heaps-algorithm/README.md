## Heap's Algorithm for generating Permutations

### About:
So while working on another puzzle, it contained a "find all the combinations" phase.  As I was typing this up I did some digging and it turns out that I've been generating permutations subobtimally the whole time.  There's an algorithm called "Heap's Algorithm" which is (according to Sedgewick) is the most efficient algorithm for generating permutations.

So here it is.

One other thing that is neat about Heaps is that you can use it for N of K permutations (find all possible 5 letter strings from these 20 characters) which is really cool.

### Output:
      alfonso@maraval heaps-algorithm % ./heaps          
      Heap's algorithm for generating permutations
      Generating all permutations for: abcd
      abcd
      bacd
      cabd
      acbd
      bcad
      cbad
      dbca
      bdca
      cdba
      dcba
      bcda
      cbda
      dacb
      adcb
      cdab
      dcab
      acdb
      cadb
      dabc
      adbc
      bdac
      dbac
      abdc
      badc

