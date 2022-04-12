import math
x = float(input("Velocidade da barca: "))
y = float(input("Velocidade do Carro: "))


length = 100
oldest = length + 1
j = 0
while j < length:
    b = length - j
    c = math.sqrt(b**2 + 1600)
    newest = j/y + c/x
    if (newest < oldest):
        oldest = newest
        dist = j
    j = j + 0.1

b = 100-dist
d = math.sqrt(b**2+1600)+dist

print(dist)
print(d)