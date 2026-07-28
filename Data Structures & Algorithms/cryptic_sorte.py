def k(s : str):
	return (len(s), s.lower(), sum(c.lower() in 'aouei' for c in s))
def cryptic_sorter(strings : list[str]) -> list[str]:
	arr_str = strings[:]
	for i in range(1, len(arr_str)):
		s1 = arr_str[i]
		while i and k(arr_str[i - 1]) > k(s1):
			arr_str[i] = arr_str[i-1]
			i -= 1
		arr_str[i] = s1
	return arr_str
