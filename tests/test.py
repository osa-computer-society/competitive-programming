from util import *
from glob import glob
import re
import signal


def handler(signum, frame):
    raise Exception('time limit exceeded')


signal.signal(signal.SIGALRM, handler)


def test_solution(problem_id, lang):
    '''assumes we are working in a tmp directory.'''
    if lang == 'cpp':
        safecall(['g++', '-Wall', '-std=c++17', '-o',
                  problem_id, f'../{problem_id}.cpp'])

    for test_case_path in sorted(glob('../tests/' + problem_id + '.[0-9][0-9].in')):
        safecall(['cp', test_case_path, problem_id + '.in'])
        signal.alarm(1)

        try:
            if lang == 'cpp':
                safecall([f'./{problem_id}'])
            elif lang == 'py':
                safecall(['python3', '../main.py'])
        except Exception:
            print('time limit exceeded')

        signal.alarm(0)

        casenum = test_case_path.split('.')[-2]

        # check solution
        with open(problem_id + '.in', 'r') as file:
            test_case = file.read()
        with open(problem_id + '.out', 'r') as file:
            result = file.read()
        with open(test_case_path.replace('.in', '.out'), 'r') as file:
            expected = file.read()

        if result.strip() == expected.strip():
            print('solved case ' + casenum + ', input:')
            print(test_case)
        else:
            print('incorrectly returned the following for case ' + casenum + ':')
            print(result)
            print('expected result:')
            print(expected)


def main():
    problem_id = get_problem_id()

    if not os.path.exists('tmp'):
        os.mkdir('tmp')
    os.chdir('tmp')

    if os.path.isfile(f'../{problem_id}.cpp'):
        print('testing cpp')
        test_solution(problem_id, 'cpp')
    if os.path.isfile(f'../{problem_id}.py'):
        print('testing py')
        test_solution(problem_id, 'py')

    # clean up temporary directory
    os.chdir('..')
    safecall(['rm', '-rf', './tmp'])

    # room for other extensions


if __name__ == '__main__':
    main()
