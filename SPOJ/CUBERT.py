from __future__ import division
from __future__ import print_function

t = int(input())

while t > 0:
  
  arr = raw_input()
  
  n = ''
  for i in range(len(arr)):
    if arr[i] >= '0' and arr[i] <= '9':
      n += arr[i]
  
  if len(n) <= 0:
    continue
         
  n = int(n)
  
  n = n*(10**30)
  
  l = 0
  r = 10**60  
  for it in range(500):
    m = (l+r)//2
    if m*m*m <= n:
      l = m
    else:
      r = m
  
  ans = str(l)
  cksm = 0
  for c in ans:
    cksm = (cksm + ord(c) - ord('0'))%10
  
  print('{} '.format(cksm), end = '')  
  for i in range(len(ans)):
    if i + 10 == len(ans):
      print('.', end = '')
    print(ans[i], end = '')
  print('')
  t -= 1
