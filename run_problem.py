'''
This is an interactive problem runner for repl.it to avoid holding every problem in its own repl.
'''

from util import *
import os


def choice(options):
    for i, option in enumerate(options):
        print(f'[{i}] {option}')


if __name__ == '__main__':
    while True:
        filename = input('please type out the full filename to your code: ')
        if os.path.isdir(filename):
            print(os.listdir(filename))

        elif os.path.isfile(filename) and promptyn('open ' + filename + '?'):
            if filename.endswith('.cpp'):
                # os.mkdir('tmp')
                print(os.path.split(filename))
                os.chdir('tmp')
                safecall(['g++', '-Wall', '../' + filename, '-o', get_problem_id(filename)])

                if 'usaco/train' in filename:
                  safecall(['cp', '../' + filename])

                break

        else:
            print('File not found, please try again')
