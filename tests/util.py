import sys
import os
from subprocess import call


def promptyn(prompt):
    '''prompt the user for a yes/no response.'''
    return input(prompt + ' [y/N] ').lower().startswith('y')


def safecall(*args, **kwargs):
    assert call(*args, **kwargs) == 0, 'subprocess had nonzero exit code'


def get_problem_id(path=None):
    if path != None:
        return os.path.splitext(os.path.split(path)[1])[0]

    if len(sys.argv) <= 1:
        problem_id = os.path.split(os.getcwd())[-1]
    else:
        problem_id = sys.argv[1]

    assert promptyn('is ' + problem_id +
                    ' your problem id?'), 'please pass the problem id as an argument, e.g. "python3 generate_tests.py ride"'

    return problem_id
