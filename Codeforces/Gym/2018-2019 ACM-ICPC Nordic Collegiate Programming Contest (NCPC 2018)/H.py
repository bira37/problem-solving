from math import gcd
 
def valid(T, l, cut, t, c):
	return T*l<=cut*t*c
 
def mmc(i, j):
	return (i*j)/gcd(i, j)
 
out = []
menor = 10**6
l, m = (int(i) for i in input().split())
for i in range(m):
	nome, p, c, t, r = (s.strip() for s in input().split(','))
	p = int(p)
	c = int(c)
	t = int(t)
	r = int(r)
 
	a = mmc((t+r), 10080)
	T = float(a)/10080
	cut = float(a)/(t+r)
	if valid(T, l, cut, t, c):
		if p==menor:
			out.append(nome)
		elif p<menor:
			out = [nome]
			menor = p
 
if len(out) == 0:
	print("no such mower")
 
for nome in out:
	print(nome)
