#FT_LINE1=7; FT_LINE2=15;
cat /etc/passwd | grep -v '^#' | awk 'NR%2==0' | cut -d ':' -f1 | rev | sort -r | \
awk 'NR>='"${FT_LINE1}"'&&NR<='"${FT_LINE2}"'' | tr '\n' ' ' | sed 's/ /, /g' |  \
sed 's/\(.*\),/\1./' | tr -d '\n'