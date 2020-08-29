run:
	g++ -o "$(NAME)" "$(NAME).cpp"
	"./$(NAME)"
	echo "========== OUTPUT BEGINS ON NEXT LINE =========="
	cat "$(NAME).out"

new:
	touch "$(NAME).in" "$(NAME).out"
	cp template.cpp "$(NAME).cpp"
	sed -i '' "s/NAME_OF_TASK/$(NAME)/g" "$(NAME).cpp"
	code -r "$(NAME).cpp" "$(NAME).in"

clean:
	find . \( -type d -name "*.dSYM" \) -o -type f \( -name "*.in" -o -name "*.out" -o -perm 755 \) -exec rm -rf {} \;
