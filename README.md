# Top-k_Problem

This program solves the Top-K problem or also known as the Top-K Heavy Hitters.
Given a set of strings, this program will output an approximation of the most popular 
k strings within the set in an efficient manner. I used a Binary Min Heap to store the top K elements as well as a Hash Table to efficiently search for elements.

Running this program:
With the given Makefile, simply run:
./main $INPUT_FILE $OUTPUT_FILE $K
Where the input and output files are paths to said files and K is an integer specifying the maximum strings you'd like to keep track of.
input_ip.in is an example file provided that contains a set of ip addresses.
