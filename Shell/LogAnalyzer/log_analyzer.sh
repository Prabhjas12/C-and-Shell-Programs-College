k="$1"
x=$(awk 'BEGIN{sum=0; counter=0;}{sum=sum+$10; counter=counter+1}END{print sum/counter}' "$k")
echo "$x"
awk '{a[$9]++} END{print length(a)}' "$k"