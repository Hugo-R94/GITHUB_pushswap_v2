#!/bin/bash

# Étape 1 : Générer 100 entiers uniques sans doublon ni x/-x
generate_unique_numbers() {
    declare -A used
    count=0
    while [ $count -lt 100 ]; do
        num=$((RANDOM * (RANDOM % 2 == 0 ? 1 : -1)))
        abs_num=${num#-}
        if [ "${used[$abs_num]}" != "1" ]; then
            echo -n "$num " >> numbers.txt
            used[$abs_num]=1
            ((count++))
        fi
    done
}

# Nettoyage anciens fichiers
rm -f numbers.txt output2.txt

# Étape 2 : Générer la liste
generate_unique_numbers

# Étape 3 : Exécuter push_swap et stocker les instructions proprement
./push_swap $(cat numbers.txt) > output2.txt

# Étape 4 : Compter et afficher le nombre d'instructions
line_count=$(wc -l < output2.txt)
echo "Nombre total d'instructions : $line_count"
