find . \( \( -type f -name *.in -o -name *.out -o -name *.txt -o -name *.csv \) -o \( -type d -name *.dSYM \) \) -exec rm -rf {} \;
