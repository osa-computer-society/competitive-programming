import json

def load():
  with open('/src/res', 'r') as file:
    data = json.loads(file.read())
    