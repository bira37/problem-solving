n,k = input().split()
 
n = int(n)+1
k = int(k)
 
l = []
 
qm = 0
 
for i in range(n):
  x = input()
  if x == '?':
    qm += 1
  else:
    l.append([int(x), i])
 
player = False
 
if len(l)%2 == 0:
  player = False
else:
  player = True
 
    
if k == 0:
  
  if len(l) == 0:
    if player:
      print('Yes')
    else:
      print('No')
  elif l[0][1] == 0:
    if l[0][0] == 0:
      print('Yes')
    else:
      print('No')
  elif l[0][1] != 0:
    if player:
      print('Yes')
    else:
      print('No')
else:
  
  if len(l) == n:
    ok = True
    for i in range(n-1):
      if l[i][0]%k == 0:
        l[i+1][0] += l[i][0]/k
      else:
        ok = False
        
    if ok and l[n-1][0] == 0:
      print('Yes')
    else:
      print('No')
  else:
    qm -= 1
    qm = qm%2
    ans = 0
    if player:
      ans += 1
    ans += qm
    ans = ans%2
    if ans == 0:
      print('No')
    else:
      print('Yes')
    
        
  
