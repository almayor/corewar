echo "\033[0;33m################  nothing  ##################\n\033[0m" 


./asm eviltests/idontexist.s
./asm eviltests/no
./asm eviltests/nocode.s
./asm eviltests/empty.s

echo "\033[0;33m\n################  commas  ##################\n\033[0m" 

./asm eviltests/comma1.s
./asm eviltests/comma2.s
./asm eviltests/comma3.s

echo "\033[0;33m\n################  escapes  ##################\n\033[0m" 

./asm eviltests/shift1.s
./asm eviltests/shift2.s

echo "\033[0;33m\n################  commands  ##################\n\033[0m" 

./asm eviltests/command1.s
./asm eviltests/command2.s
./asm eviltests/command3.s
./asm eviltests/command4.s
./asm eviltests/command5.s
./asm eviltests/command6.s
./asm eviltests/command7.s
./asm eviltests/command8.s

echo "\033[0;33m\n################  operations  ##################\n\033[0m" 

./asm eviltests/op1.s
./asm eviltests/op2.s
./asm eviltests/op3.s
./asm eviltests/op4.s
./asm eviltests/op5.s
./asm eviltests/op6.s

echo "\033[0;33m\n################  labels  ##################\n\033[0m" 

./asm eviltests/label1.s
./asm eviltests/label2.s
./asm eviltests/label3.s
./asm eviltests/label4.s



