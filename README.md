# IO-exception

The purpose of this problem is to get you used to handling I/O exceptions. Write a program
that consumes the names of several les on the command line, and computes the sum of all
integers found in the les (we dene an integer to be any sequence of characters for which
reading from a stream into an integer variable succeeds). However, some of the les whose
names were given to the program may not exists, and not everything in these les is a number.
When the program is nished, it must print out a list of all les that did not exist, the total
of all numbers found, and the total number of words in all les that did not denote numbers.
For example, if le a contains 1 2 3 4 5, le b contains 1 b 3 d 5 and les c and d do not
exist, then ./a4q1 a b c d should produce the following output:
Non-existent files: c d
Total of all numbers: 24
Total number of non-numbers: 2
The number of command-line arguments could be arbitrarily long; do not assume an articial
maximum.
If reading a number fails, consume a word (i.e., up to the next whitespace) and proceed from
there. For example, if a contains 2.5, then ./a4q1 a should produce
Non-existent files:
Total of all numbers: 2
Total number of non-numbers: 1
