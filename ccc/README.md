# Canadian Computing Competition (CCC)

The CCC is the biggest and most reputable competitive programming contest in Canada. You can take it at one of two levels. Anybody can participate and choose which level they want to take.

Both levels give you **3 hours** to solve **5 questions** worth **15 points each** for a total of **75 points.**

**Languages:** C, C++, Python 2 and 3, Pascal, Java, Perl, PHP

- Beware that their [contest page](https://cemc.uwaterloo.ca/contests/computing/details.html) says:

> While various languages are supported by the CCC Online Grader, it may not be possible in all cases to achieve a perfect score with a particular language choice (for example, Python or Java).

We *have* encountered this situation before, so unless you're willing to learn C or C++, *c'est la vie.* That being said, if you TLE, *much* more often than not it'll be your algorithm and not the language. You can write slow algorithms in any language. Same goes for fast ones.

## Junior

The Junior level is fantastic if you're just getting into competitive programming!

| Question(s) | Description                                                                    |
| ----------- | ------------------------------------------------------------------------------ |
| 1, 2        | Straightforward (e.g., basic loops and conditions)                             |
| 3, 4        | More challenging (e.g. some combination of loops, conditions and counting)     |
| 5           | Some advanced material (e.g., recursion, efficient sorting, clever algorithms) |

## Senior

The Senior level is great if you have a good amount of programming experience. Approximately the top 20 students are invited to write the Canadian Computing Olympiad, from which the top 4 students represent Canada at the [International Olympiad of Informatics](/ioi/README.md).

| Question(s) | Description                                                                    |
| ----------- | ------------------------------------------------------------------------------ |
| 1, 2        | Basic algorithms (e.g., sorting, searching)                                    |
| 3 , 4       | More advanced algorithms (e.g., careful counting, some mathematical reasoning) |
| 5           | IOI level question                                                             |

You'll usually see the problems abbreviated as "J5" is question 5 on the Junior contest and "S3" as question 3 on the Senior, for example. J5 is often the same question as S2 or S3.

**How to write:** The contest is run through the [CCC Online Grader](https://www.cemc.uwaterloo.ca/contests/computing/computing-grader.html), which is also available for use if you want to test your solutions to past contests.

Follow the instructions on the page linked above to get started. You'll need to ask Mr. Karas for our school number and get him to authenticate you as a student after you register.

To use the grader:

1. Login to the grader at <http://cccgrader.com/>
2. Click `Enter` beside the contest you want to write/practice on
3. Select a problem
4. Select the language your solution is in
5. Upload the file with your solution and click submit

## Rules

See <https://cccgrader.com/rules.pdf>

### Implementation details

All input is from standard input and all output is to standard output. Your program shouldn't read or write to any files.

All Java programs must be in a file called `Main.java` inside a `public class Main`.

Time limit: **3 seconds** (approx. 3 000 000 000 operations)

Memory limit: **512 MB** (e.g. an array of 64 000 000 `long long`s)

### Submissions

Max 50 submissions per problem

Max 1 submission per minute

### Feedback

Feedback is always provided for the sample test cases. For each subtask of a problem, if all test cases are correct, this feedback is provided for each test case. Otherwise, feedback is provided for all test cases up to and including the first test case that is not correct. More specifically, when feedback is provided for a test case, one of the following results is reported.

- compilation error (e.g., your program did not compile)
- time-limit exceeded (e.g., your program took too long to find an answer)
- run-time error (e.g., segmentation fault in your program)
- wrong answer (e.g., your program gave incorrect output)
- skipped test (e.g., within one test batch, you have failed one of the tests, and thus the remainder of the tests within that batch have been skipped)
- correct (e.g., your output matches the expected output exactly)

### Contest scoring

Your score for a problem is the **maximum** score over all submissions to that problem.

### Internet, references and other tools

You may **only** use the Internet for contest submission and to access official language documentation:

| Language | Documentation                                                   |
| -------- | --------------------------------------------------------------- |
| C++      | <http://www.cplusplus.com/reference/>                           |
| Java     | <https://docs.oracle.com/en/java/javase/15/docs/api/index.html> |
| Python 2 | <https://docs.python.org/2/reference/index.html>                |
| Python 3 | <https://docs.python.org/3/reference/index.html>                |
| C        | <https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html>   |
| Pascal   | <https://www.freepascal.org/docs-html/ref/ref.html>             |

Access to other source or starter code is not allowed during the competition. This includes both electronic and printed source code, either created by the contestant or gathered elsewhere.

Most calculators are permitted. See <http://cemc.uwaterloo.ca/contests/calculators.html> for more information.

Rough paper, graph paper, rulers and compasses are OK.

You may use paper dictionaries but not electronic ones to translate the contest between English and another language.

Use of forbidden tools or sources, or collaboration with other students during the contest will result in severe penalties:

- the student will receive a score of 0 on the CCC;
- their school will be notified;
- the student will be banned from all future CCC contests.
