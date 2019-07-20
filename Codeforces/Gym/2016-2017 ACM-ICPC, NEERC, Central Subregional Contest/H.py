inpts = open("input.txt")
outpts = open("output.txt", "w")
 
n = [x.strip() for x in inpts.readlines()]
 
n = int(n[0])
ans = 1
for i in range(1, 2):
  ans *= 8
 
if n <= 1:
  outpts.write(str(ans) + '\n')
else:
  for i in range(2, min(n+1, 10)):
    ans *= 9
  if n<=9:
    outpts.write(str(ans) + '\n')
  else:
    for i in range(10, n+1):
      ans *= 10
    outpts.write(str(ans) + '\n')
