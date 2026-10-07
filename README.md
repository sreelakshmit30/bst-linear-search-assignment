# BST vs Linear Search

## Aim

To implement and compare Binary Search Tree (BST) search and Linear Search for identification numbers.

## Input Data

A102
A25
A7
B100
B12
A120
B3
A45

## Search IDs

A120
B12
A7

## Methods Used

1. Binary Search Tree (BST)
2. Linear Search

## BST Inorder Traversal

A102 A120 A25 A45 A7 B100 B12 B3

## Results

| Search ID | BST Comparisons | Linear Comparisons |
|-----------|-----------------|--------------------|
| A120      | 3               | 6                  |
| B12       | 5               | 5                  |
| A7        | 3               | 3                  |

## Complexity Analysis

### BST Search

Best Case: O(1)

Average Case: O(log n)

Worst Case: O(n)

Space: O(n)

### Linear Search

Best Case: O(1)

Average Case: O(n)

Worst Case: O(n)

Auxiliary Space: O(1)

## Conclusion

For the given data, BST required fewer or equal comparisons than Linear Search.

The performance of a normal BST depends on its height and insertion order. A balanced BST provides approximately O(log n) search time, while a skewed BST can take O(n).

For a large and growing database, a self-balancing BST such as an AVL tree or Red-Black tree is preferable.

## Files

- main.c - C program
- input.txt - Input data
- output.txt - Program output
- trace_table.txt - Insertion and search trace
- comparison_table.txt - Comparison of BST and Linear Search
- complexity.txt - Complexity analysis