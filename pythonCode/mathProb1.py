from math import e

def getEquation(n):
    return 2*(n**2) - (e**-n) - 4

def segmentAprox(x1, x2):
    if(abs(abs(x1) - abs(x2)) < 0.01):
        return x1, x2 
    else:
        n = (x1 + x2)/2
        return segmentAprox(x1, n) if getEquation(n) > 0 else segmentAprox(n, x2)

x1 = float(input("Digite o primeiro numero:"))
x2 = float(input("Digite o segundo numero:"))

if(getEquation(x1) * getEquation(x2) < 0 ):
    a, b = segmentAprox(x1,x2)
    print('A equação tem pelo menos uma solução neste intervalo: [',a,',',b,']')
else: 
    print("Não é possível afirmar que existe solução neste intervalo, tente outros dois números.")