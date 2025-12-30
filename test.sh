
#!/usr/bin/bash

# clears scores.txt
> scores.txt

for i in $(seq 1 5000);
do
    ARG=$(python3 test_ints.py 500)
    ./push_swap $ARG | wc -l >> scores.txt
done
