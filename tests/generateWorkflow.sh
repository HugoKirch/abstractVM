#!/bin/bash


cat buildtest > output
cat mandatorytest >> output
#generate job for mandatory tests
for d in mandatory/*; do
    if FILE=$(ls "$d" | grep ".*\.avm") ; then
        TEMPLATE=$(cat tasktemplate)
        NAME=${FILE%.avm}
        echo "Generating task templated test for $d, name test: $NAME"
        TEMPLATE=${TEMPLATE//|FOLDER|/$d}
        TEMPLATE=${TEMPLATE//|NAME|/$NAME}
        TEMPLATE=${TEMPLATE//|FILE|/$FILE}
        echo "$TEMPLATE" >> output
    elif FILE=$(ls "$d" | grep ".*\.input") ; then
        NAME=${FILE%.input}
        echo "Generating input templated test for $d, name test: $NAME"
        TEMPLATE=$(cat inputtemplate)
        NAME=${NAME%.input}
        TEMPLATE=${TEMPLATE//|FOLDER|/$d}
        TEMPLATE=${TEMPLATE//|NAME|/$NAME}
        TEMPLATE=${TEMPLATE//|FILE|/$FILE}
        echo "$TEMPLATE" >> output
    fi

done

cat mirroringmodule >> output

cp output ../.github/workflows/c-cpp.yml
rm output