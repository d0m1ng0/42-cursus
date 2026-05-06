*This project has been created as a part of the 42 curriculum by dverdini*

### Description
This project implements an efficient sorting algorithm using two stacks. The
goal is to sort data with a limited set of operations, minimizing the total
number of moves. This implementation uses a cost-optimization (arbitrage)
algorithm to find the most "expensive" or "cheapest" path to sort elements.

### Instructions
- Installation: clone the repo.
- MANDATORY PART:
	make
	ARG=$(seq -min_range max_range | shuf -n number_elements | tr '\n' ' '); 
	./push_swap $ARG | ./checker_linux $ARG ./push_swap $ARG | wc -l
- BONUS PART:
	make bonus
	ARG=$(seq -min_range max_range | shuf -n number_elements | tr '\n' ' ');
	./push_swap $ARG | tee >(./checker_linux $ARG) | ./checker $ARG
	./push_swap $ARG | wc -l
	
- optional: valgrind
	./push_swap

### Resources
- Internet.
- man: arbitrage algorithms, read, malloc, free, open, GNU MAKE.
- youtube.
- medium.

### Algorithm Explanation
The core of this push_swap implementation is a cost-optimization algorithm.
1. The Pre-Sort Phase:
(Pushing to stack b) We leave two nodes in stack a and push all others to stack
b.
While pushing, we can perform a "primitive" sort to keep stack b roughly
ordered (descending), which reduces the cost of future rotations.
2. The Arbitrage Calculation (The "Best Move" Logic):
For each node in stack b, we calculate the total cost to move it to its correct
position in Stack A. The cost is the sum of:
	Cost a: rotations needed to bring the target position in a to the top.
	Cost b: Rotations needed to bring the current node in B to the top.
3. Optimization with Double Rotations
The algorithm doesn't just add $cost a + cost B$. It identifies opportunities
for Simultaneous Rotations (rr or rrr): If both nodes need to go "Up" (positive
rotation), we use rr until one reach the top.If both need to go "Down" (reverse
rotation), we use rrr.This significantly reduces the total move count, often
keeping 100 elements under 700 moves.
4. The Final Alignment
Once Stack B is empty and all nodes are back in Stack A,
we perform a final rotation to ensure the smallest number is at the top.
