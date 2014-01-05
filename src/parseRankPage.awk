
BEGIN {
	mapIndex = -1
}

( $0 == "<tr><td>" ) && ( mapIndex == -1 ) {
	mapIndex = 0
}

( $0 == "</td>" ) && ( mapIndex >= 0 ) {
	++mapIndex
}

{
	if ( 0 != match($0, "<tr class=\"impair2\"><td><td class=\"right_(best)?temps\">([0-9:.]*)</td></td><td class=\"right_date\">([a-zA-Z0-9: ]*)</td></tr>", a) ) {
   		printf "%s/%d/%s/%s\n", player, mapIndex, substr($0, a[2, "start"], a[2, "length"]), substr($0, a[3, "start"], a[3, "length"])
	}

}

