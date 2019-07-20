n, s = [int(x) for x in input().split()]
 
cur = 0
 
lst = {}
for i in range(n):
  name, x = input().split()
  x = int(x)
  lst[x] = name
  
ans = []
 
lst = sorted(lst.items(), key=lambda kv: kv[0], reverse=True)
 
for x, name in lst:
  if cur + x <= s:
    ans.append(name)
    cur += x
 
if cur == s:
  print(len(ans))
  for name in ans:
    print(name)
else:
  print (0)  
  
