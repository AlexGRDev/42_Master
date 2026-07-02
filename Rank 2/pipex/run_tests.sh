#!/bin/bash

PIPEX=./pipex
i=1

run_test() {
    echo "------ TEST $i ------"
    CMD="$@"
    
    # Ejecutar pipex
    eval $PIPEX $CMD > out_pipex.txt 2> err_pipex.txt
    EXIT_PIPEX=$?

    # Ejecutar pipeline real
    eval "<$1 $2 | $3 > out_bash.txt" 2> err_bash.txt
    EXIT_BASH=$?

    # Comparar salidas
    if diff -q out_pipex.txt out_bash.txt >/dev/null && diff -q err_pipex.txt err_bash.txt >/dev/null; then
        echo "OK"
    else
        echo "FAIL"
        echo "---- PIPEX ERR ----"
        cat err_pipex.txt
        echo "---- BASH ERR ----"
        cat err_bash.txt
    fi

    # Mostrar códigos de salida
    echo "pipex exit: $EXIT_PIPEX | bash exit: $EXIT_BASH"
    echo ""
    i=$((i+1))
}

################################################################################
# TESTS EXTREMOS
################################################################################

# 1. Comando normal
run_test infile "cat" "wc -l" outfile

# 2. Comando con flags
run_test infile "grep hola" "wc -l" outfile

# 3. Comando con múltiples argumentos
run_test infile "cut -d ' ' -f 1" "sort" outfile

# 4. No existe infile
run_test nofile "cat" "wc -l" outfile

# 5. Comando inexistente en cmd1
run_test infile "nofoundcmd" "wc -l" outfile

# 6. Comando inexistente en cmd2
run_test infile "cat" "owegjg" outfile

# 7. Infile vacío
echo -n "" > emptyfile
run_test emptyfile "cat" "wc -c" outfile

# 8. Archivo gigante (stress test)
yes "hola mundo" | head -n 50000 > bigfile
run_test bigfile "grep hola" "wc -l" outfile

# 9. Comando cmd1 vacío
run_test infile "" "wc -l" outfile

# 10. Comando cmd2 vacío
run_test infile "cat" "" outfile

# 11. Comando con espacios múltiples
run_test infile "   cat    -n   " "   wc   -l    " outfile

# 12. PIPEX sin permisos en infile
touch no_perm; chmod 000 no_perm
run_test no_perm "cat" "wc -l" outfile
chmod 644 no_perm

# 13. PATH corrupto
( export PATH=""; $PIPEX infile "ls" "wc -l" outfile ) > out_x 2>err_x
echo "------ TEST 13 ------"
echo "PATH vacío: (ls debería fallar)"
cat err_x
echo ""

# 14. Cientos de ejecuciones (stress test real)
echo "------ TEST 14 ------"
for k in {1..50}; do
    $PIPEX infile "cat" "wc -l" outfile > /dev/null 2>&1
done
echo "Stress test OK si no crashea :)"
echo ""

rm -f out_pipex.txt out_bash.txt err_pipex.txt err_bash.txt
