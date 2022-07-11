#!/bin/bash


cat generators_templates/buildtest > output
cat generators_templates/mandatorytest >> output
#generate job for mandatory tests
for d in mandatory/*; do
    if FILE=$(ls "$d" | grep ".*\.avm") ; then
        TEMPLATE=$(cat generators_templates/tasktemplate)
        NAME=${FILE%.avm}
        echo "Generating task templated test for $d, name test: $NAME"
        TEMPLATE=${TEMPLATE//|FOLDER|/$d}
        TEMPLATE=${TEMPLATE//|NAME|/$NAME}
        TEMPLATE=${TEMPLATE//|FILE|/$FILE}
        echo "$TEMPLATE" >> output
    elif FILE=$(ls "$d" | grep ".*\.input") ; then
        NAME=${FILE%.input}
        echo "Generating input templated test for $d, name test: $NAME"
        TEMPLATE=$(cat generators_templates/inputtemplate)
        NAME=${NAME%.input}
        TEMPLATE=${TEMPLATE//|FOLDER|/$d}
        TEMPLATE=${TEMPLATE//|NAME|/$NAME}
        TEMPLATE=${TEMPLATE//|FILE|/$FILE}
        echo "$TEMPLATE" >> output
    fi

done
cat generators_templates/extratest >> output
for d in extra/*; do
    if FILE=$(ls "$d" | grep ".*\.avm") ; then
        TEMPLATE=$(cat generators_templates/tasktemplate)
        NAME=${FILE%.avm}
        echo "Generating task templated test for $d, name test: $NAME"
        TEMPLATE=${TEMPLATE//|FOLDER|/$d}
        TEMPLATE=${TEMPLATE//|NAME|/$NAME}
        TEMPLATE=${TEMPLATE//|FILE|/$FILE}
        echo "$TEMPLATE" >> output
    elif FILE=$(ls "$d" | grep ".*\.input") ; then
        NAME=${FILE%.input}
        echo "Generating input templated test for $d, name test: $NAME"
        TEMPLATE=$(cat generators_templates/inputtemplate)
        NAME=${NAME%.input}
        TEMPLATE=${TEMPLATE//|FOLDER|/$d}
        TEMPLATE=${TEMPLATE//|NAME|/$NAME}
        TEMPLATE=${TEMPLATE//|FILE|/$FILE}
        echo "$TEMPLATE" >> output
    fi

done

cat generators_templates/mirroringmodule >> output

cp output ../.github/workflows/c-cpp.yml
rm output