This project has been created as part of the 42 curriculum by alamjada

# Push swap

## Description
At first glance, the exercise seems simple: sorting a sequence of numbers from 1 to n in ascending order.

To do this, we were given a few constraints:

- maximum of two stacks
- limited set of operations (swap, push, rotate, and reverse rotate)
- maximum number of moves to validate the project

[subject](https://cdn.intra.42.fr/pdf/pdf/192339/en.subject.pdf)

### Choice
I chose the Turk algorithm, which guarantees an 80% score without optimization. 
It selects the least costly move for each operation when moving elements from one stack to the other.

Radix sort can also reach 80%, but not beyond that without adding other sorting methods.

I made extensive use of the linked list data structure; without it, each move would have required creating a new array.

This exercise helped me improve my understanding of linked lists and their advantages, 
as well as how to approach a problem by breaking it down into smaller subproblems:

- parsing the input  
- creating the stack  
- finding the target node  
- calculating the cost of movements
- moving values to their correct position  

## Instructions

- Compile the project
`make`

- Run
`./push_swap 2 3 4 5 1 ...`

## Resources

### Videos
- [Push_swap: Stack Sorting Algorithm Challenge](https://www.youtube.com/watch?v=mIqpsnKmfzw)
- [10 Sorting Algorithms Easily Explained](https://www.youtube.com/watch?v=rbbTd-gkajw&t=11s)

### Articles
- [Medium-Turk algorithm](https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0)
- [Medium  A journey to find most efficient sorting algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)

### Tools
- [Push swap visualizer](https://github.com/o-reo/push_swap_visualizer)

