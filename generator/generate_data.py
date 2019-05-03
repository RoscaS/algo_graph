# sudo pip3 install ForgeryPy

import forgery_py
from random import randint

NUMBER = 10
filename = "rawdata"
protocol = "www."

raw = [forgery_py.internet.domain_name() for i in range(NUMBER)]

uniq = list(set(raw))

lines = []

for url in uniq:
    lst = [f'"{protocol}{url}"']
    for link in range(randint(3, 10)):
        lst.append(f'"{protocol}{uniq[randint(0, len(uniq) - 1)]}"')
    lines.append(lst)

strLst = [" ".join(i) for i in lines]

with open(filename, 'w') as f:
    for i in strLst:
        f.writelines(f'{i}\n')
