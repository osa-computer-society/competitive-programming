with open('csv_to_html_res.csv', 'r') as file:
    html = '<html>\n\t<body>\n\t\t<table>\n'
    html += '\t\t\t<tr><th>' + '</th><th>'.join(map(str.strip, file.readline().split(','))) + '</th></tr>\n'
    for row in file.readlines():
        html += '\t\t\t<tr><td>' + '</td><td>'.join(map(str.strip, row.split(','))) + '</td></tr>\n'
    html += '\t\t<table>\n\t<body>\n<html>\n'
    with open('csv_to_html.html', 'w') as target:
        target.write(html)
