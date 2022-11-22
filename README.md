# competitive-programming

This repository is aimed at introducing new programmers, and more specifically, Canadian high school students, to the world of competitive programming. This is maintained by the executives of the OSA Computer Society, and as such it will be opinionated, since it is much more efficient to learn one way well than to spend many hours deciding which way to learn.

**Always attempt the problem before you look at the solution!** Also, **NEVER** copy and paste: even typing out the solution by hand is better, since it'll help you build up the muscle memory.

There are no shortcuts; only hard work and dedication. Be patient and set realistic goals.

If you would like to contribute a solution, please feel free to open a pull request following the guidelines below!

Even solutions which score partial marks are useful too!

## Getting started

We recommend adding the following alias to your shell startup file:

```bash
function comp() {
  g++ \
    # print all warnings
    -Wall -Wextra -pedantic \
    # or c++17 depending on contest
    -std=c++11 \
    # optimizations
    -O2 \
    # catch a variety of possible warning
    -Wshadow \
    -Wformat=2 \
    -Wfloat-equal \
    -Wconversion \
    -Wshift-overflow \
    -Wcast-qual \
    -Wcast-align \
    # optional, use for debugging
    # -D_GLIBCXX_DEBUG \
    # -D_GLIBCXX_DEBUG_PEDANTIC \
    # run-time buffer overflow detection
    -D_FORTIFY_SOURCE=2 \
    -fstack-protector \
    "$1.cpp" -o "$1"
}
```

That way, you can compile `foo.cpp` via `comp foo` and then run it via `./foo`.

## Contributing

- Style is not the most important attribute as long as your code is readable. [The Zen of Python](https://zen-of-python.info/) is good advice no matter what language you're writing in.
- Document any non-trivial parts of your code, including algorithms you use.
- Please place your code in the folder for the contest where it was originally written.
- Use underscores in file names.
- Remove any confidential information, such as your username/id in a header comment.
- Use the file extension `.cpp` for C++ files and not `.cc`.
- If the question has an ID, i.e. DMOJ, the filename should be the ID. If the questions are ordered, place the question number in front of the title or ID, i.e. `1_moobuzz.cpp`, `2_meetings.cpp`, etc.

## Resources

Resources are currently scattered throughout the directory as well as on [our website](https://osacs.tech/).

We do assume that you have some basic experience with the programming language you aim to use, such as:

- Loops (for, while)
- Conditionals (if, else)
- Basic data structures (arrays)

If you're *entirely new*, we recommend learning either Python or C++. The former is easier to learn for most people, while the latter is very fast and allows you more precision over low-level details.
