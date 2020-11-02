# In progress
n = int(input())
og = []
nvwls = []
vwl_cnt = []
for i in range(n):
    wd = input()
    og.append(wd)
    nvwls.append(''.join([l for l in wd.upper() if l not in "AEIOU"]))
    vwl_cnt.aappend()

enc = input()

for i in range(n-1):
    for j in range(i+1, n):
        if len(nvwls[i]) % len(nvwls[j]) == 0 and nvwls[j] * (len(nvwls[i]) // len(nvwls[j])) == nvwls[i]:


dec = ""
buf = ""
for c in enc:
    buf += c
    if buf in nvwls:
        dec += og[nvwls.index(buf)] + " "
        buf = ""

print(dec[:-1])
