#!/bin/bash

# =============================================
#      ITSALEXITO PUSH_SWAP TESTER v3
#   "Fortnite real, sin cuentos."
# =============================================

PUSH_SWAP=./push_swap
CHECKER=./checker_Mac

# ===== COLORS =====
RED="\033[1;31m"
BLK="\033[1;30m"
GLITCH="\033[5;31m"
RESET="\033[0m"
GREEN="\033[1;32m"
YELLOW="\033[1;33m"

# ===== GLITCH HEADER =====
header() {
    printf "\n${RED}${GLITCH}============================================${RESET}\n"
    printf "${RED}🔥  %s${RESET}\n" "$1"
    printf "${RED}${GLITCH}============================================${RESET}\n"
}

# ===== OUTPUT MINI =====
ok()  { printf "${GREEN}✔${RESET} %s\n" "$1"; }
fail(){ printf "${RED}✘${RESET} %s\n" "$1"; }

# ===== TEST FUNCTIONS =====
error_test() {
    OUT=$(eval "$1" 2>&1)
    if [[ "$OUT" == "Error" ]]; then
        ok "$1"
    else
        fail "$1 → '$OUT'"
    fi
}

empty_test() {
    OUT=$(eval "$1" 2>&1)
    if [[ -z "$OUT" ]]; then
        ok "$1"
    else
        fail "$1 → '$OUT'"
    fi
}

checker_ok() {
    RES=$(printf "%b" "$2" | $CHECKER $1 2>&1)
    if [[ "$RES" == "OK" ]]; then
        ok "checker $1"
    else
        fail "$1 → $RES"
    fi
}

checker_ko() {
    RES=$(printf "%b" "$2" | $CHECKER $1 2>&1)
    if [[ "$RES" == "KO" ]]; then
        ok "checker KO $1"
    else
        fail "$1 → $RES"
    fi
}

# ===== ANIMATION =====
loading() {
    for i in {1..8}; do
        printf "${RED}${BLK}⧖${RESET} Cargando meta...\r"
        sleep 0.1
        printf "${RED}⧗${RESET} Cargando meta...\r"
        sleep 0.1
    done
    printf "\n"
}

loading

# =============================================
header "1. ERROR MANAGEMENT"
# =============================================

error_test "$PUSH_SWAP a"
error_test "$PUSH_SWAP 1 a 2"
error_test "$PUSH_SWAP --"
error_test "$PUSH_SWAP ++"
error_test "$PUSH_SWAP 4 2 3b"
error_test "$PUSH_SWAP \"1 2 hola 3\""
error_test "$PUSH_SWAP 1 1"
error_test "$PUSH_SWAP 2147483648"
error_test "$PUSH_SWAP -2147483649"

printf "\n${YELLOW}→ Sin parámetros debe imprimir nada${RESET}\n"
empty_test "$PUSH_SWAP"

# =============================================
header "2. IDENTITY TEST"
# =============================================

empty_test "$PUSH_SWAP 42"
empty_test "$PUSH_SWAP 2 3"
empty_test "$PUSH_SWAP 0 1 2 3"
empty_test "$PUSH_SWAP 0 1 2 3 4 5 6 7 8 9"
empty_test "$PUSH_SWAP \"0 1 2 3 4 5 6 7 8 9\""

# =============================================
header "3. SIMPLE TESTS"
# =============================================

ARG="2 1 0"
printf "Test 2-1-0 → %s\n" "$($PUSH_SWAP $ARG | $CHECKER $ARG)"

ARG="0 2 1"
printf "Test 0-2-1 → %s\n" "$($PUSH_SWAP $ARG | $CHECKER $ARG)"

# =============================================
header "4. SIMPLE 5 NUMBERS"
# =============================================

ARG="1 5 2 4 3"
printf "5 numbers → %s\n" "$($PUSH_SWAP $ARG | $CHECKER $ARG)"


# =============================================
header "5. RANDOM TESTS (shuf)"
# =============================================

random_test() {
    SIZE="$1"
    SEQ=$(shuf -i 0-9999 -n "$SIZE")
    MOVES=$($PUSH_SWAP $SEQ | wc -l)
    RESULT=$($PUSH_SWAP $SEQ | $CHECKER $SEQ)

    if [[ "$RESULT" == "OK" ]]; then
        printf "${GREEN}✔${RESET} %s numbers → %s moves\n" "$SIZE" "$MOVES"
    else
        printf "${RED}✘${RESET} %s numbers → KO (moves: %s)\n" "$SIZE" "$MOVES"
    fi
}

# Tests típicos estilo push_swap-tester
printf "\n${YELLOW}→ Probando randoms: 5, 100, 500${RESET}\n\n"

random_test 10
random_test 100
random_test 500

printf "\n${RED}${GLITCH}=== FIN DE TESTS ===${RESET}\n\n"