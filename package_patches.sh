#!/bin/bash

netids=$1
name=$2
base=$3


git show-ref --verify --quiet refs/heads/$base
if [ "$?" != "0" ]; then
	echo "Error: $base is an invalid branch!"
	exit
fi

echo "Packaging: netids=$netids, name=$name, base=$base"
rm -rf $name $name.tar.gz
mkdir -p $name
git format-patch -o $name $base > /dev/null
output="$name-$netids.tar.gz"
tar zcf $output $name
rm -rf $name
echo "Output file is $output"

