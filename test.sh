
#!/bin/bash

# Clear the file first
> scores.txt

for i in $(seq 1 200);
do
    ARG=$(python3 test_ints.py 500)
    ./push_swap $ARG | wc -l >> scores.txt
done
