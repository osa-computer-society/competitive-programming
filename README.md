[![Run on Repl.it](https://repl.it/badge/github/piguyinthesky/competitive-programming)](https://repl.it/github/piguyinthesky/competitive-programming)

# competitive-programming

Here's a small informal repo where a couple of friends and I practice for computing competitions. Feel free to open up a pull request if you have solutions to contribute! Always remember to attempt the problem before you look at the solution. Don't copy-paste a solution: even typing it out is better! It'll help you build up the muscle memory.

# Resources

## Language of choice: C++

- [C++ tutorial](http://www.cplusplus.com/doc/tutorial/)
- Most of our code is written using C++. To run a C++ file (.cpp) from the Mac/Linux terminal:
  1. `cd` to the directory containing the file you want to run.
  2. Type `g++ [filename]`. This should create a file named `a.out` in the same directory.
  3. To run the file, type `./a.out` in your terminal and press enter.
  4. The program should run.
- You can test this using the `hello_world.cpp` file.
- Some subdirectories also have Makefiles you can use if you're familiar with them.
- An interesting way to learn a new language is translating an existing solution. Keep in mind that this might not always be directly possible!

### Conventions

- Use the standard namespace, i.e. put `using namespace std;` at the top of your C++ files.
- Use underscores to separate words in function, variable and file names, i.e. `book_genre` or `cpp_primer`.
- Our suffix for the files is `.cpp`, just to keep things consistent.
- I'm not too worried about style conventions, as long as it's readable.
- To clean up build files, run `./cleanup.sh`. Make sure it's marked as an executable by running `chmod +x cleanup.sh`.
