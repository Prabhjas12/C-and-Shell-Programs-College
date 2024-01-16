k=$2
cat sample.txt | tr -c '[:alnum:]' '[\n*]'| tr 'A-Z' 'a-z'| sort | grep -vwFf stopwords | uniq -c | sort -k1,1nr -k2,2 | head -n "$k" | awk '{print $2}'