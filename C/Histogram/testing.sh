# Test Case 1: Numbers within the original range [0, 16)
echo -e "3 -4 5 1 7 0\n8 0 15 12 3 5\n3 3 3 3 3\n" | ./histogram


# Test Case 2: Number outside the original range, leading to range doubling
echo -e "8 0 15 12 3 5\n18\n19 20 30 7 12\n50\n34\n32\n19\n44\n" | ./histogram


# Test Case 3: Number well past the current bin size, leading to multiple range doublings
echo -e "150" | ./histogram


# Test Case 4: Example using bash syntax to generate a list of numbers
echo "{1..16} 150" | ./histogram

