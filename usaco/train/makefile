run:
	g++ -o "build/$(NAME)" "$(NAME).cpp"
	cd build && "./$(NAME)" && \
	echo "========== OUTPUT BEGINS ON NEXT LINE ==========" && cat "$(NAME).out"

new:
	mkdir -p build
	touch "build/$(NAME).in" "build/$(NAME).out"
	cp template.cpp "$(NAME).cpp"
	sed -i '' "s/NAME_OF_TASK/$(NAME)/g" "$(NAME).cpp"
	code -r "$(NAME).cpp" "build/$(NAME).in"

clean:
	rm -r build
