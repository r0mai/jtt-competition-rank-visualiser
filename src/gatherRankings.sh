#!/bin/bash

mkdir -p "tmp"

aggregatedFile="tmp/aggregatedFile"

rm -f ${aggregatedFile}

for playerIndex in {1..309}; do
	echo -n "${playerIndex}"
	tmpFile="tmp/tmp"

	src/downloadPage.sh "95.130.9.140/TM/Trophee2014/Resultats_hiver/statistiques_joueur.php?joueur=${playerIndex}" ${tmpFile}

	awk -f src/parseRankPage.awk -v player=${playerIndex} ${tmpFile} >> "${aggregatedFile}"

	rm -f ${tmpFile}
done

bin/createStats < ${aggregatedFile}

rm -f ${aggregatedFile}

