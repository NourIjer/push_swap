#!/bin/bash

max_ops=12
count=0

generate_numbers() {
    for i in {1..4}; do
        echo -n "$((RANDOM % 101)) "
    done
}

while true; do
    count=$((count + 1))
    numbers=$(generate_numbers)
    result=$(./push_swap $numbers | wc -l)
    
    if [ $result -gt $max_ops ]; then
        echo "Test failed on attempt $count"
        echo "Numbers: $numbers"
        echo "Operations: $result"
        exit 1
    fi

    if [ $((count % 100)) -eq 0 ]; then
        echo "Completed $count tests successfully"
    fi
done