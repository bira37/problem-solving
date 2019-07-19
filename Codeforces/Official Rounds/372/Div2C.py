n = int(input())
 
lst = 0
for i in range(n):
  if i == 0:
    print(2)
    lst = 2
  else:
    j = i+1
    #print('lst = ' + str(lst))
    #print('want = ' + str((j*(j+1))**2))
    print((((j*(j+1))**2) - lst)//j)
    lst = ((j*(j+1)))
  
