import re
import os
import sys
from subprocess import call


def promptyn(prompt):
    '''prompt the user for a yes/no response.'''
    return input(prompt + ' [y/N] ').lower().startswith('y')


def get_problem_id():
    if len(sys.argv) <= 1:
        problem_id = os.path.split(os.getcwd())[-1]
    else:
        problem_id = sys.argv[1]
    assert promptyn('is ' + problem_id +
                    ' your problem id?'), 'please pass the problem id as an argument, e.g. "python3 generate_tests.py ride"'
    return problem_id


def safecall(*args, **kwargs):
    assert call(*args, **kwargs) == 0, 'subprocess had nonzero exit code'


def case_path(problem_id, num, ext='in'):
    '''gets the filepath of a specific case based on its index.'''
    return f'tests/{problem_id}.{str(num+1).zfill(2)}.{ext}'


def read_cases(path, test_case_re):
    '''reads test cases from a file using the usaco format.'''
    with open(path, 'r') as file:
        return test_case_re.split(file.read())[1:]


def write_cases(problem_id, cases, cases_in):
    '''writes the cases in problem_id to separate files within a directory.'''
    if not os.path.exists('tests'):
        os.mkdir('tests')

    for num, line in enumerate(cases):
        with open(case_path(problem_id, num), 'w') as case_file:
            case_file.write(line)

    if promptyn('move original test file to "./tests"?'):
        safecall(['mv', cases_in, './tests'])


def gen_output(cases, cpp_path, problem_id, cases_in):
    if os.path.isfile(cpp_path) and promptyn(f'generate cases using {cpp_path}?'):
        os.mkdir('./tmp')
        os.chdir('./tmp')
        # we are now working inside the tmp directory
        safecall(['g++', '-Wall', '../' + cpp_path, '-o', problem_id])

        for num, case in enumerate(cases):
            for process in (
                ['cp', '../' + case_path(problem_id, num), cases_in],
                [f'./{problem_id}'],
                ['mv', problem_id + '.out', '../' +
                    case_path(problem_id, num, 'out')]
            ):
                safecall(process)

        os.chdir('..')
        safecall(['rm', '-rf', './tmp'])


def main():
    test_case_re = re.compile(r'------- test \d+ \[length \d+ bytes\] ----\n')
    problem_id = get_problem_id()
    cases_in = problem_id + '.in'
    cpp_path = problem_id + '.cpp'

    assert os.path.isfile(
        cases_in), f'please make sure that there is a file titled "{cases_in}" in the current directory containing the test cases in the format of the USACO judge'

    cases = read_cases(cases_in, test_case_re)
    write_cases(problem_id, cases, cases_in)
    gen_output(cases, cpp_path, problem_id, cases_in)


if __name__ == '__main__':
    main()
