#eligible for vote
age = input("enter ur age: ")
#type casting
age = int(age) #epliccit type casting.
print(type(age))
if(age>=18):
    print("eligible for casting vote.")
else:
    print("not eligible.")
    
# create three variables a,b with values 10,20 and check 
# which equal, greater,
a= 10
b=20
if a>b:
    print("a is greater")
elif a==b:
    print("a and b are equal")
else:
    print("b is greater")
