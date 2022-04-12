import math

v = float(input("digite o volume: "))
x = float(input("digite o custo da base: "))
y = float(input("digite o custo dos lados: "))

v = v * math.pi / 1000000 
r = (v)/(2*math.pi)
r = math.pow(r,1/3)

h = math.pow((4*v/math.pi),1/3)

ab = math.pi * r**2 
al =(2*math.pi*r*h)
at = al + 2*ab

p = al*y + (ab*2)*x

print(ab*2)
print(al)

print(f"Preço total de: R$ {p:.2f}")
print(f"Área total de: {at:.2f} m²")
print(f"Raio total de: {r:.2f} m")
print(f"Altura total de: {h:.2f} m")
