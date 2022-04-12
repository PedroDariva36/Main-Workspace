import math

a = float(input("Tamanho da Costa: "))
d = float(input("Distancia da Costa até a Cidade: "))
b = float(input("Velocidade da Barca: "))
c = float(input("Velocidade do Carro: "))

if(b < c):
    b2 = b*b
    c2 = c*c
    a2 = a*a


    x = ((a2*b2)/(c2 - b2))
    x = math.sqrt(x)



    dist_c = d - x


    hipo = math.sqrt((a2+(x*x))) 
    dist_total = hipo + dist_c

    tb = hipo/b
    tc = dist_c/c
    t = tb + tc

    print("")
    print(x)
    print(f"Tempo minimo -> {tb:.2f} + {tc:.2f} = {t:.2f}" )
    print(f"Distancia da Cidade até a estação: {dist_c:.2f}Km")
    print(f"Distancia percorrida pela Barca: {hipo:.2f}Km")
    print(f"Distancia total: {dist_total:.2f}Km")