while true; do
    # Generate 500 random numbers between -5000 and 5000 using awk
    arg=$(awk 'BEGIN{srand(); for(i=0;i<500;i++) printf("%d ", int(rand() * 10001) - 5000)}')
    
    # Run push_swap and count the number of operations
    num_operations=$(./push_swap $arg | wc -l)
    
    # Print the number of operations
    echo "Number of operations: $num_operations"
    
    # Check if the number of operations exceeds 5499
    if [ "$num_operations" -gt 5499 ]; then
        echo "Exceeded 5499 operations. Stopping..."
        break
    fi
done
