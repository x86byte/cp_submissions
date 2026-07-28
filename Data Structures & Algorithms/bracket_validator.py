def checker(c, s):
    ctr = 0
    for i in s:
        if i == c:
            ctr += 1
    return ctr

def bracket_validator(s: str) -> bool:
    prev = None
    for i in s:
        if i >= 'a' and i <= 'z' or i >= '0' and i <= '9':
            s = s.replace(i, "")
    ctr = checker('(', s)
    while ctr != 0:
        s = s.replace('()', '')
        ctr -= 1
    ctr = checker('[', s)
    while ctr != 0:
        s = s.replace('[]', '')
        ctr -= 1
    ctr = checker('{', s)
    while ctr != 0:
        s = s.replace('{}', '')
        ctr -= 1
    return s == ""
