#find . | wc -l | sed 's/ //g'
find . | wc -l | tr -d ' '