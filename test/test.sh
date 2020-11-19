#!/usr/bin/env bash

################################# CONFIG #################################

WIDTH=60
DIREC=test/champions

if [[ "$OSTYPE" == "linux-gnu"* ]]; then
	ZAZ_VM=test/corewar_zaz_linux
elif [[ "$OSTYPE" == "darwin"* ]]; then
	ZAZ_VM=test/corewar_zaz_osx
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

function check_champions
{
	out=$($ZAZ_VM -d 0 $1)
	if [ $? -ne 0 ]; then
		echo "$out"
	fi
}

function get_dump
{
	dump=""
	regex="^(0x)?[0-9a-f]+ ?: ?([0-9a-f ]+)$"
	
	while read line; do
		line=$(sed 's/^ *//;s/ *$//' <<< $line)
		if [[ $line =~ $regex ]]; then
			dump="${dump} ${BASH_REMATCH[${#BASH_REMATCH[@]}-1]}"
		fi
	done

	echo "$dump"
}

function test_champions
{
	names="$1"
	icycle=$2
	(( num_total += 1 ))

	champs=$(full_path_champions "$1")
	print_champions "$names"

	check=$(check_champions "$champs")
	if [[ ! -z $check ]]; then
		printf "${c_red}KO${c_off}\n"
		echo " $check"
		return
	fi

	out_zaz="$($ZAZ_VM -d $icycle $champs | get_dump)"
	out_our="$(./corewar -dump $icycle $champs | get_dump)"

	if [[ `wc -w <<< $out_zaz` -ne 4096 ]] || \
	   [[ `wc -w <<< $out_our` -ne 4096 ]]; then
		printf "${c_yellow}INVALID${c_off}\n"
		return
	fi

	diff=$(diff <(printf "%s\n" "${out_zaz[@]}") <(printf "%s\n" "${out_our[@]}"))

	if [[ ! -z $diff ]]; then
		printf "${c_red}KO${c_off}\n"
	else
		(( num_passed += 1))
		printf "${c_green}OK${c_off}\n"
	fi
}

num_passed=0
num_total=0

head="=== ${t_bold}Comparing memory dumps against Zaz's machine${t_off} ======================"
head_len=${#head}

echo
echo $head

test_champions "Gagnant.cor" 26023
test_champions "ex.cor" 3071
test_champions "jumper.cor" 24690
test_champions "mortel.cor" 7429
test_champions "maxidef.cor" 25901
test_champions "slider2.cor" 25902
test_champions "bigzork.cor" 28362
test_champions "fluttershy.cor" 25902
test_champions "helltrain.cor" 27438
test_champions "turtle.cor" 40480
test_champions "leapfrog.cor" 180949
test_champions "helltrain.cor fluttershy.cor" 25901
test_champions "fluttershy.cor toto.cor leapfrog.cor" 25901
test_champions "le_pet_de_nonne.cor Car.cor helltrain.cor" 9999
test_champions "Gagnant.cor ex.cor" 25902
test_champions "Gagnant.cor slider2.cor" 25902
test_champions "leapfrog.cor helltrain.cor Gagnant.cor mortel.cor" 24366


echo "    ---------------------------------------------------------------"
echo "    $num_passed tests passed out of $num_total"
echo "======================================================================="
echo

if [ $num_passed -eq $num_total ]; then
	printf "${t_bold}${c_green}PASSED${c_off}${t_off}\n"
else
	printf "${t_bold}${c_red}FAILED${c_off}${t_off}\n"
fi
