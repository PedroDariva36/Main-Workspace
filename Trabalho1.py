fx = input("Digite a função que voce deseja integrar: ")
print("Digite o intervalo da função: ")
a = float(input('a = '))
b = float(input('b = '))
n = int(input('Qual o número de subintervalos: '))

delta = ((b - a)/n)
result = sum([eval(fx.replace('x', str((a + i*delta)))) for i in range(1, n)])
print(result)
result += 0.5 * eval(fx.replace('x', str(a))) + 0.5*eval(fx.replace('x', str(b)))
result *= delta

print(f"Area aproximada: {abs(result)}")