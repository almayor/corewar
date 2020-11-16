#!/usr/bin/env bash

RD="\033[031m"
GR="\033[032m"
YW="\033[033m"
BL="\033[034m"
PK="\033[035m"
CN="\033[036m"
EOC="\033[0m"

CHAMPS_ARR=(
	# "champs/Gagnant.cor"
	# "champs/ex.cor"
	# "champs/jumper.cor"
	# "champs/mortel.cor"
	# "champs/maxidef.cor"
	# "champs/slider2.cor"
	# "champs/examples/bigzork.cor"
	# "champs/examples/fluttershy.cor"
	# "champs/examples/turtle.cor"
	# "champs/Gagnant.cor champs/ex.cor"
	"champs/ex.cor champs/Gagnant.cor"
	"champs/Gagnant.cor champs/slider2.cor"
)

INCR=1000

for champs in "${CHAMPS_ARR[@]}"; do

	printf "${PK}Champions: $champs${EOC}\n"
	utils/test_vm $champs
	if [ $? -ne 0 ]; then break; fi
	echo

done
