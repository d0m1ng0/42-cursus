cat /etc/passwd | grep -v '^#' | awk 'NR % 2 == 0' | cut -d ':' -f1 | rev
