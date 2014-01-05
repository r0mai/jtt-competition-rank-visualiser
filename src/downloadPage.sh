#!/bin/bash
#

if [ $# -ne 2 ]; then
	echo "downloadPage.sh: 2 arguments expected: URL, output" 1>&2
	exit 1
fi

curl --progress-bar -o "$2" "$1"

