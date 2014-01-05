#!/bin/bash

function reWriteLine() {
	#\e[1A rewrites last line, \033[K deletes the line first
	echo -e "\e[1A\033[K$@"
}

#MAIN

doDownload="false"
while getopts "d" OPTION; do
	case $OPTION in
		d)
			doDownload="true"
			;;
	esac

done

aggregatedFile="tmp/aggregatedFile"

if [ "${doDownload}" == "true" ]; then
	mkdir -p "tmp"

	echo

	for playerIndex in {1..309}; do
		playerPage="tmp/player_${playerIndex}.web"

		reWriteLine "Downloading ${playerIndex}"

		src/downloadPage.sh "95.130.9.140/TM/Trophee2014/Resultats_hiver/statistiques_joueur.php?joueur=${playerIndex}" ${playerPage}
	done
fi

if [ ! -d "tmp" ]; then
	echo "You have to run download first" 1>&2
	exit 1
fi

aggregatedFile="tmp/aggregatedFile"

rm -f ${aggregatedFile}

echo

for playerPage in $(ls tmp/*.web); do
	playerIndex=$(echo ${playerPage} | sed s/[^0-9]//g)

	reWriteLine "Parsing player ${playerIndex}"

	awk -f src/parseRankPage.awk -v player=${playerIndex} ${playerPage} >> "${aggregatedFile}"
done

echo "Processing..."

bin/createStats < ${aggregatedFile}

