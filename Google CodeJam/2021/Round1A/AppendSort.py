t = int(input())

def digs(x):
  ans = 0
  while x > 0:
    x = x // 10
    ans+=1
  return ans


for tt in range(t):
  t -= 1

  ops = 0

  n = int(input())

  v = [int(x) for x in input().split()]

  for i in range(len(v)):
    if i == 0:
      continue
    
    if v[i] > v[i-1]:
      continue
    
    #print(v[i], v[i-1])
    if digs(v[i]) == digs(v[i-1]):
      v[i] = 10*v[i]
      ops+=1
      continue

    a = str(v[i])
    b = str(v[i-1])

    comps = 0
    for j in range(len(a)):
      if a[j] == b[j]:
        comps = 0
        continue
      elif a[j] < b[j]:
        comps = -1
        break
      else:
        comps = 1
        break
    
    if comps == 0:
      dig = -1
      for j in range(len(a), len(b)):
        if b[j] != '9':
          dig = j

      if dig == -1:
        while len(a) != len(b):
          a += '0' 
          ops+=1
        a += '0'
        ops += 1
      else:
        for j in range(len(a), dig):
          a += b[j]
          ops+=1
        
        a += str(chr(ord(b[dig])+1))
        ops += 1

        for j in range(dig+1, len(b)):
          a += '0'
          ops+=1
      
      v[i] = int(a)
    elif comps == 1:
      while len(a) != len(b):
        a += '0'
        ops+=1
      v[i] = int(a)
    else:
      while len(a) != len(b):
        a += '0'
        ops+=1
      a += '0'
      ops+=1
      v[i] = int(a)
  
  #print(v)
  print("Case #" + str(tt+1)  + ": " + str(ops))
