s1 = "29162"
s2 = "10524"

i = 0

while(i<len(s1)):
    if(s1[i]==s2[i]):
        i+=1
    else:
        break

ind = i

t1 = 0
if(s1[ind]<s2[ind]):
    t1+=1
    ind+=1
else:
    ind+=1

for j in range(ind,len(s1)):
    if(s1[ind]>s2[ind]):
        t1+=1
    ind+=1
        
t2 = 0
ind = i 
if(s1[ind]>s2[ind]):
    t2+=1
    ind+=1
else:
    ind+=1
    
for j in range(ind,len(s1)):
    if(s1[ind]<s2[ind]):
        t2+=1
    ind+=1
print(min(t1,t2))
