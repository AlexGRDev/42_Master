# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run_tests.sh                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/01 12:11:09 by agarcia2          #+#    #+#              #
#    Updated: 2026/07/01 12:25:47 by agarcia2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

# Colores
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

PIPEX="./pipex"
INFILE="infile"
OUTFILE="outfile"
OUT_PIPEX="out_pipex.txt"
OUT_BASH="out_bash.txt"

# Función de ejecución
run_test() {
    local test_name="$1"
    local cmd1="$2"
    local cmd2="$3"

    # Imprimir nombre del test alineado (25 caracteres)
    printf "%-25s : " "$test_name"

    $PIPEX "$INFILE" "$cmd1" "$cmd2" "$OUTFILE" > $OUT_PIPEX 2>/dev/null
    EXIT_PIPEX=$?

    bash -c "< $INFILE $cmd1 | $cmd2 > $OUT_BASH" 2>/dev/null
    EXIT_BASH=$?

    if diff -q $OUT_PIPEX $OUT_BASH >/dev/null && [ $EXIT_PIPEX -eq $EXIT_BASH ]; then
        printf "${GREEN}OK${NC}\n"
    else
        printf "${RED}FAIL${NC}\n"
        printf "   [!] Error: Pipex(%d) vs Bash(%d)\n" "$EXIT_PIPEX" "$EXIT_BASH"
    fi
}

# Limpieza
rm -f "$OUT_PIPEX" "$OUT_BASH"
echo "hola" > "$INFILE"

# --- TESTS ---
run_test "Comando simple" "cat" "wc -l"
run_test "Flags" "grep hola" "wc -l"
run_test "Args espacios" "grep hola" "wc -w"
