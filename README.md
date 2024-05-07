# AVL Tree to ASCII Character Converter
This program is a C++ program compiled in the MinGW C++ environment. The program reads positive integers from the Veri.txt file and inserts them into AVL trees. When inserting into AVL trees, duplicate values are not added. The leaves of each AVL tree are then read in postorder and placed into a separate stack. For numbers that are not placed into the stack, the sum of node values is calculated for each AVL tree, and converted to an ASCII character using the following formula:
```
int ascii = AVLTotalNodeValue % (90 - 65 + 1) + 65;
```
The characters corresponding to these ASCII values, from the first created AVL tree to the last, are concatenated and printed to the console.

Numbers are popped from the stacks in pairs, starting with the smallest. In case of equality, the data is popped from the initially created stack. This process continues, alternating between smallest and largest, until one of the stacks is empty. The AVL tree associated with the emptied stack is then destroyed.

The process of reading AVL tree leaves in postorder and placing them into stacks continues until only one AVL tree remains. Except for the leaves of the last AVL tree, the ASCII character obtained from the above formula is printed to the console along with the phrase "Last Character" and the number of the AVL tree (numbering starts from 1), and the program terminates.

# Usage
1) Add input data to the Veri.txt file.
2) Compile and run the program.
3) The program will print the result to the console.

# Sample Input
```
5 8 2
3 6 9
```
# Sample Output
```
Last Character: Q - AVL 2
```
