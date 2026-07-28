def echo_validator(text: str) -> bool:
    s1 = text
    res = ""
    for c in text:
        if c.isalpha():
            res += c.lower()
    bp = res
    return (bp[::-1] == res)


print(echo_validator("raceca3r"))
