#!/usr/bin/env bash

################################# CONFIG #################################

WIDTH=60
DIREC=champions

if [[ "$OSTYPE" == "linux-gnu"* ]]; then
	ZAZ_ASM=./asm_zaz_linux
elif [[ "$OSTYPE" == "darwin"* ]]; then
	ZAZ_ASM=./asm_zaz_osx
else
	>&2 echo "OS not supported"
	exit 1
fi

c_red="\033[031m"
c_green="\033[032m"
c_yellow="\033[033m"
c_blue="\033[034m"
c_pink="\033[035m"
c_cyan="\033[036m"
c_off="\033[0m"

t_bold=$(tput bold)
t_underline=$(tput smul)
t_underline_off=$(tput rmul)
t_rev=$(tput rev)
t_blink=$(tput blink)
t_invis=$(tput invis)
t_standout=$(tput smso)
t_standout_off=$(tput rmso)
t_off=$(tput sgr0)

##########################################################################

function print_champions
{
	str="$@"
	if (( ${#str} > $WIDTH ))
	then
		str="${1:0:$(($WIDTH - 3))}..."
	fi
	if (( ($WIDTH - ${#str}) % 2 ))
	then
		str="$str "
	fi
	while (( ${#str} < $WIDTH ))
	do
		str="$str. "
	done
	printf "    $str "
}

function full_path_champions
{
	champs=""
	for champ in $@; do
		champs="${champs}${DIREC}/$champ "
	done
	printf "$champs"
}

function test_asm
{
	name="$1"
	(( num_total += 1 ))

	champ=$(full_path_champions "$1")
	print_champions "$name"

	tmp1=/tmp/asm-test-1.s
	ln -f $champ $tmp1
	out1=$($ZAZ_ASM $tmp1 2>&1 1> /dev/null)
	if [ $? -ne 0 ]; then
		printf "${c_yellow}INVALID!${c_off}\n"
		echo $out1
		return
	fi
	out1=${tmp1%.*}.cor

	tmp2=/tmp/asm-test-2.s
	ln -f $champ $tmp2
	out2=$(./asm $tmp2 2>&1 1> /dev/null)
	if [ $? -ne 0 ]; then
		printf "${c_red}KO${c_off}\n"
		echo $out2
		return
	fi
	out2=${tmp2%.*}.cor

	diff=$(diff $out1 $out2)

	if [[ ! -z $diff ]]; then
		printf "${c_red}KO${c_off}\n"
	else
		(( num_passed += 1))
		printf "${c_green}OK${c_off}\n"
	fi
}

head="=== ${t_bold}ASM: Comparing binary${t_off} ============================================="
head_len=${#head}

num_passed=0
num_total=0

echo
echo $head

test_asm "Gagnant.s"
test_asm "ex.s"
test_asm "jumper.s" 
test_asm "mortel.s"
test_asm "maxidef.s"
test_asm "slider2.s"
test_asm "bigzork.s"
test_asm "fluttershy.s"
test_asm "helltrain.s"
test_asm "turtle.s"
test_asm "Car.s"
test_asm "toto.s"
test_asm "bee_gees.s"
test_asm "zork.s"
test_asm "Douceur_power.s"
# test_asm "Explosive_Kitty.s"
# test_asm "Kittystrophic.s"
test_asm "overwatch.s"
# test_asm "run_Kitty_RUN.s"
# test_asm "ultima.s"
test_asm "gateau.s"

echo "    ---------------------------------------------------------------"
echo "    $num_passed tests passed out of $num_total"
echo "======================================================================="

if [ $num_passed -eq $num_total ]; then
	printf "${t_bold}${c_green}PASSED${c_off}${t_off}\n\n"
else
	printf "${t_bold}${c_red}FAILED${c_off}${t_off}\n\n"
fi
