#!/usr/bin/env bash

script_path=$( cd "$(dirname "${BASH_SOURCE[0]}")" ; pwd -P )
DIREC="${script_path}/eviltests"

printf "\033[0;33m################  nothing  ##################\n\033[0m\n" 


./asm "$DIREC/idontexist.s"
./asm "$DIREC/no"
./asm "$DIREC/nocode.s"
./asm "$DIREC/empty.s"

printf "\033[0;33m\n################  commas  ##################\n\033[0m\n" 

./asm "$DIREC/comma1.s"
./asm "$DIREC/comma2.s"
./asm "$DIREC/comma3.s"

printf "\033[0;33m\n################  escapes  ##################\n\033[0m\n" 

./asm "$DIREC/shift1.s"
./asm "$DIREC/shift2.s"

printf "\033[0;33m\n################  commands  ##################\n\033[0m\n" 

./asm "$DIREC/command1.s"
./asm "$DIREC/command2.s"
./asm "$DIREC/command3.s"
./asm "$DIREC/command4.s"
./asm "$DIREC/command5.s"
./asm "$DIREC/command6.s"
./asm "$DIREC/command7.s"
./asm "$DIREC/command8.s"

printf "\033[0;33m\n################  operations  ##################\n\033[0m\n" 

./asm "$DIREC/op1.s"
./asm "$DIREC/op2.s"
./asm "$DIREC/op3.s"
./asm "$DIREC/op4.s"
./asm "$DIREC/op5.s"
./asm "$DIREC/op6.s"

printf "\033[0;33m\n################  labels  ##################\n\033[0m\n" 

./asm "$DIREC/label1.s"
./asm "$DIREC/label2.s"
./asm "$DIREC/label3.s"
./asm "$DIREC/label4.s"



