k="$1"
x="$2"

if [ "$#" -ne 2 ]; then
    echo "Invalid number of arguments"
else
	if [ -e "$k" ] && [ -r "$k" ]; then
        awk -F"," 'NR > 1 {print $4",", $5",", $6}' "$k" | sort -t, -k3,3nr -k1,1 | uniq | head -n "$x" 
    else
        echo "Cannot find/read covidVaccines.csv"
    fi
fi