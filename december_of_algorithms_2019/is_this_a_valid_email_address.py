import re

def is_valid_email(s):
  return re.match(r"[a-zA-Z0-9_.-]+@[a-zA-Z]+\.com")

# def complete(s):
#   return re.match(r"[^.](.?[a-zA-Z0-9!#$%&'*+-/=?^_`{|}~])+", s)