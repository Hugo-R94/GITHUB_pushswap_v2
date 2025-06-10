#!/bin/bash

# Paramètre pour le nombre d'opérations de push_swap
MAX_OPERATIONS=5500

# Compteurs pour les résultats
checker_ok=0
checker_linux_ok=0
total_tests=1000
total_operations=0
errors_count=0

for i in $(seq 1 $total_tests); do
    # Étape 1 : Générer 100 entiers uniques sans doublon ni x/-x
    generate_unique_numbers() {
        declare -A used
        count=0
        while [ $count -lt 500 ]; do
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
    rm -f numbers.txt output.txt output_linux.txt

    # Étape 2 : Générer la liste
    generate_unique_numbers

    # Étape 3 : Exécuter push_swap et stocker les instructions proprement
    ./push_swap $(cat numbers.txt) > output.txt

    # Étape 4 : Exécuter checker et vérifier le résultat
    cat numbers.txt | ./checker > /dev/null
    if [ $? -eq 0 ]; then
        checker_result="OK"
        ((checker_ok++))
    else
        checker_result="KO"
        ((errors_count++))
    fi

    # Étape 5 : Exécuter checker_linux et vérifier le résultat
    cat numbers.txt | ./checker_linux > /dev/null
    if [ $? -eq 0 ]; then
        checker_linux_result="OK"
        ((checker_linux_ok++))
    else
        checker_linux_result="KO"
        ((errors_count++))
    fi

    # Étape 6 : Compter le nombre d'instructions
    operations_count=$(wc -l < output.txt)
    total_operations=$((total_operations + operations_count))

    echo "Test $i : checker = $checker_result || checker_linux = $checker_linux_result || Nombre d'instructions : $operations_count"

    if [ $operations_count -gt $MAX_OPERATIONS ]; then
        echo "Nombre d'instructions dépassé ($MAX_OPERATIONS)"
    fi
done

# Affichage des résultats
echo "Résultats des tests :"
echo "Checker : $checker_ok / $total_tests ($(bc -l <<< "scale=2; $checker_ok / $total_tests * 100")%)"
echo "Checker_linux : $checker_linux_ok / $total_tests ($(bc -l <<< "scale=2; $checker_linux_ok / $total_tests * 100")%)"
echo "Nombre moyen d'instructions : $(bc -l <<< "scale=2; $total_operations / $total_tests")"
echo "Nombre d'erreurs : $errors_count"
