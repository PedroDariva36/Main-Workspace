./a.out <entrada06.in >ex06.out
./a.out <entrada05.in >ex05.out
./a.out <entrada04.in >ex04.out
./a.out <entrada03.in >ex03.out
./a.out <entrada02.in >ex02.out
./a.out <entrada01.in >ex01.out

diff ex01.out saida01.out -s
diff ex02.out saida02.out -s 
diff ex03.out saida03.out -s 
diff ex04.out saida04.out -s 
diff ex05.out saida05.out -s 
diff ex06.out saida06.out -s 

echo "done"