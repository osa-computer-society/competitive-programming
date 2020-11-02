from glob import glob
import sys
import os
from subprocess import call
import re


def promptyn(prompt):
    '''prompt the user for a yes/no response.'''
    return input(prompt + ' [y/N] ').lower().startswith('y')


def get_problem_id():
    if len(sys.argv) <= 1:
        problem_id = os.path.split(os.getcwd())[-1]
    else:
        problem_id = sys.argv[1]

    if not promptyn('is ' + problem_id + ' your problem id?'):
        problem_id = input('please enter the problem id: ')

    return problem_id


def safecall(*args, **kwargs):
    assert call(*args, **kwargs) == 0, 'subprocess had nonzero exit code'


def main():
    problem_id = get_problem_id()

    solution_path = input(
        'please enter the relative path to your solution, including the extension: ')

    if solution_path.endswith('.cpp'):
        os.mkdir('tmp')
        os.chdir('tmp')
        safecall(['g++', '-Wall', '../' + solution_path, '-o', problem_id])

        for test_case_path in glob('../tests/' + problem_id + '.[0-9][0-9].in'):
            safecall(['cp', test_case_path, problem_id + '.in'])
            safecall([f'./{problem_id}'])
            casenum = test_case_path.split('.')[-2]
            # check solution
            with open(problem_id + '.out', 'r') as file:
                result = file.read()
            with open(test_case_path.replace('.in', '.out'), 'r') as file:
                expected = file.read()

            if result.strip() == expected.strip():
                print('solved case ' + casenum)
            else:
                print('returned the following for case ' + casenum + ':')
                print(result)
                print('expected result:')
                print(expected)

        os.chdir('..')
        safecall(['rm', '-rf', './tmp'])


if __name__ == '__main__':
    main()
