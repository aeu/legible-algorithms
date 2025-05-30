
0065-valid-number

-123.456e7.8e9
any unexpected non-numeric in exponent

Test case : 1 : Pass
 (expected 0, got 0)
-123.456e7.89
any unexpected non-numeric in exponent

Test case : 2 : Pass
 (expected 0, got 0)
-123.456e7.8.9
any unexpected non-numeric in exponent

Test case : 3 : Pass
 (expected 0, got 0)
-123.456e7.89
any unexpected non-numeric in exponent

Test case : 4 : Fail
 (expected 1, got 0)
2

Test case : 5 : Pass
 (expected 1, got 1)
0089

Test case : 6 : Pass
 (expected 1, got 1)
-0.1

Test case : 7 : Pass
 (expected 1, got 1)
+3.14

Test case : 8 : Pass
 (expected 1, got 1)
4.

Test case : 9 : Pass
 (expected 1, got 1)
-.9

Test case : 10 : Pass
 (expected 1, got 1)
2e10

Test case : 11 : Pass
 (expected 1, got 1)
-90E3

Test case : 12 : Pass
 (expected 1, got 1)
3e+7

Test case : 13 : Pass
 (expected 1, got 1)
+6e-1

Test case : 14 : Pass
 (expected 1, got 1)
53.5e93

Test case : 15 : Pass
 (expected 1, got 1)
-123.456e789

Test case : 16 : Pass
 (expected 1, got 1)
