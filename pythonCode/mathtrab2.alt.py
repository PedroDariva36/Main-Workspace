import math
b = float(input("Velocidade da Barca: "))
c = float(input("Velocidade do Carro: "))

b2 = b*b
c2 = c*c

x = ((1600*b2)/(c2 - b2))
x = math.sqrt(x)

dist_c = 100 - x
hipo = math.sqrt((1600+(x*x))) 
dist_total = hipo + dist_c

print(" ")
print(f"Distancia da Cidade até a estação: {dist_c:.2f}Km")
print(f"Distancia percorrida pela Barca: {hipo:.2f}Km")
print(f"Distancia total: {dist_total:.2f}Km")