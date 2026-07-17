#!/bin/bash

# ===================================================
#   ITSALEXITO PUSH_SWAP STRESS TESTER — FINAL VERSION
#   "Fortnite real, sin cuentos."
# ===================================================

PUSH_SWAP=./push_swap
CHECKER_LINUX=./checker_linux
CHECKER_MAC=./checker_Mac

RED="\033[1;31m"
GREEN="\033[1;32m"
YELLOW="\033[1;33m"
CYAN="\033[1;36m"
GLITCH="\033[5;31m"
RESET="\033[0m"

printf "${RED}${GLITCH}=== ITSALEXITO PUSH_SWAP TESTER — ULTRA HUMILIATION MODE ===${RESET}\n\n"

# ===================================================
# DETECCIÓN DE SISTEMA
# ===================================================
OS=$(uname -s)

if [[ "$OS" == "Darwin" ]]; then
    printf "${CYAN}→ Sistema detectado: macOS${RESET}\n"
    CHECKER=$CHECKER_MAC

elif [[ "$OS" == "Linux" ]]; then
    printf "${CYAN}→ Sistema detectado: Linux${RESET}\n"
    CHECKER=$CHECKER_LINUX

else
    printf "${RED}✘ Sistema desconocido. Abortando.${RESET}\n"
    exit 1
fi

# ===================================================
# AUTOCOMPILACIÓN
# ===================================================
if [[ ! -f push_swap ]]; then
    printf "${YELLOW}→ push_swap no encontrado, compilando con make all…${RESET}\n"
    make all &>/dev/null
fi

# ===================================================
# COMPILACIÓN ASAN (solo Linux)
# ===================================================
if [[ "$OS" == "Linux" ]]; then
    printf "${YELLOW}→ Compilando versión ASAN (Linux)…${RESET}\n"
    make fclean &>/dev/null
    make CFLAGS="-fsanitize=address -g3 -O0 -fno-omit-frame-pointer" &>/dev/null
    mv push_swap push_swap_asan
fi

printf "${YELLOW}→ Compilando versión NORMAL…${RESET}\n"
make fclean &>/dev/null
make all &>/dev/null

# ===================================================
# SEGURIDAD + UB TESTER
# ===================================================
run_safety_test() {
    ARG="$1"
    printf "${CYAN}→ Probando seguridad con arg: %s${RESET}\n" "$ARG"

    timeout 4 ./push_swap $ARG &>/dev/null
    if [[ $? -eq 124 ]]; then
        printf "${RED}✘ Timeout / posible bucle infinito${RESET}\n"
        return
    fi

    OUT=$(./push_swap $ARG 2>&1)

    if echo "$OUT" | grep -qi "segmentation"; then
        printf "${RED}✘ SEGFAULT detectado${RESET}\n"
        return
    fi

    if echo "$OUT" | grep -qi "core dumped"; then
        printf "${RED}✘ CORE DUMP detectado${RESET}\n"
        return
    fi

    if [[ "$OS" == "Linux" ]]; then
        ASAN_OPTIONS=detect_leaks=0 ./push_swap_asan $ARG &>/dev/null 2>asan_out.txt
        if grep -q "ERROR:" asan_out.txt; then
            printf "${RED}✘ Undefined Behavior detectado por ASAN${RESET}\n"
            cat asan_out.txt
            rm asan_out.txt
            return
        fi
        rm asan_out.txt
    fi

    printf "${GREEN}✔ Test de seguridad superado${RESET}\n"
}

# ===================================================
# STRESS TEST (100 / 500 / 1000) + TIEMPO RESTANTE
# ===================================================
run_batch() {
    SIZE=$1
    COUNT=$2

    printf "\n${CYAN}⚡ Stress Test → %d tests de size %d${RESET}\n" "$COUNT" "$SIZE"

    MIN=9999999
    MAX=0
    TOTAL=0

    START_TIME=$(date +%s)

    for ((i=1; i<=COUNT; i++)); do

        # LISTA PERFECTA ÚNICA
        SEQ=$(seq 0 $((SIZE-1)) | shuf | tr '\n' ' ')

        MOVES=$(./push_swap $SEQ | wc -l)
        RESULT=$(./push_swap $SEQ | $CHECKER $SEQ)

        if [[ "$RESULT" != "OK" ]]; then
            printf "${RED}✘ KO detectado en test %d${RESET}\n" "$i"
            continue
        fi

        ((TOTAL+=MOVES))
        ((MOVES<MIN)) && MIN=$MOVES
        ((MOVES>MAX)) && MAX=$MOVES

        # ======================
        # CALCULO TIEMPO RESTANTE
        # ======================
        NOW=$(date +%s)
        ELAPSED=$((NOW - START_TIME))
        AVERAGE_TIME=$(echo "$ELAPSED / $i" | bc -l)
        REMAINING_TESTS=$((COUNT - i))
        REMAINING_SECONDS=$(printf "%.0f" $(echo "$AVERAGE_TIME * $REMAINING_TESTS" | bc -l))

        H=$((REMAINING_SECONDS/3600))
        M=$(( (REMAINING_SECONDS%3600)/60 ))
        S=$((REMAINING_SECONDS%60))

        printf "✔ %d/%d → %d moves | ⏳ %02d:%02d:%02d restando...\r" \
            "$i" "$COUNT" "$MOVES" "$H" "$M" "$S"
    done

    printf "\n\n${GREEN}📊 RESULTADOS size %d${RESET}\n" "$SIZE"
    AVG=$(echo "$TOTAL / $COUNT" | bc -l)
    printf "   🔹 Min: %d\n" "$MIN"
    printf "   🔸 Max: %d\n" "$MAX"
    printf "   🔻 Media: %.2f\n" "$AVG"
}

# ===================================================
# BREAKER MODE
# ===================================================
printf "\n${YELLOW}⚠️ BREAKER MODE — Intentando petar push_swap…${RESET}\n"

ATTACKS=(
    '""'
    '"    "'
    '"--42"'
    '"++42"'
    '"4 2 a 3"'
    '"2147483648"'
    '"-2147483649"'
    '"1 1 1 1"'
    '"$(printf "1 %.0s" {1..20000})"'
)

for atk in "${ATTACKS[@]}"; do
    run_safety_test "$atk"
done

# ===================================================
# RUN FULL HUMILIATION MODE
# ===================================================
run_batch 100 1000
run_batch 500 200
run_batch 1000 50

printf "${RED}${GLITCH}\n=== FIN DEL MEGATEST ITSALEXITO ===${RESET}\n\n"
