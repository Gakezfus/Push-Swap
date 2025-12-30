*This project has been created as part of the 42 curriculum by echoo.*

## Description

This project creates a program that outputs instructions to solve a given push_swap problem as efficiently as possible.

## Instructions

### Compilation

For mandatory function:
```bash
make all
```

For bonus function:
```sh
cc get_next_line_bonus.c get_next_line_utils_bonus.c
```

### Execution

```sh
./push_swap (elements in push_swap)
```

## Resources

### Documentation & References

The idea of the "Turk Algorithm" probably came from this article: https://medium.com/@ayogun/push-swap-c1f5d2d41e97

I don't know for sure where the AI I consulted got the idea from, but it's likely that article. The AI gave me a similar but possibly less efficient idea from the same concept.

From the subject description:

There are 2 stacks named a and b. Initially, the stack a contains a random number of unique negative and/or positive
integers, while the stack b is empty. The goal is to sort the numbers in stack a in ascending order using the following operations:

- sa (swap a): Swap the first 2 elements at the top of stack a. Does nothing if there is only one element or none.
- sb (swap b): Swap the first 2 elements at the top of stack b. Does nothing if there is only one element or none.
- ss : sa and sb at the same time.
- pa (push a): Take the first element at the top of b and put it at the top of a. Does nothing if b is empty.
- pb (push b): Take the first element at the top of a and put it at the top of b. Does nothing if a is empty.
- ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
- rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
- rr : ra and rb at the same time.
- rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
- rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
- rrr : rra and rrb at the same time.

### AI Usage

AI helped me to debug my various memory errors and helped suggest different algorithms for various parts of the program to make it more efficient. Even ideas not accepted were usually helpful for me to think of more. AI also helped me to create the python program to create random numbers so that I could more easily test my program's efficiency.
