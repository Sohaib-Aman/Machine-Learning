# It can be done using single '' double "" and triple ''' ''' quotes

print('Hello World1')
print("Hello World2")
print('''Hello World3''')

#MultiLine strings      

#1. using single triple quotes

x= '''I'm learning python for Artificial Intelligence,machine learning,deep learning,data analysis and for data scientist'''

print(x)

#2. using double triple quotes

x= """I'm learning python for Artificial Intelligence,machine learning,deep learning,data analysis and for data scientist"""

print(x)


#strings are arrays
a="hello, world"
print(a[0])


# string slicing 
#   name[start:end+1]  # range operator
print(a[0:5])
print(a[7:12])
print(a[:5])   # starting index may skip:
print(a[7:])   # ending index can also be skiped.

# negative indexing
print(a[-12:-7])

# ----------------- string manipulation ---------------

x = " hello, World "
print(x.upper()) # string convert into uppercase.
print(x.lower()) # string convert into lowercase.
print(x.strip()) # remove spaces from start and end.
print(x.replace("World", "Python"))
print(x.split()) # break string and convert into list.
