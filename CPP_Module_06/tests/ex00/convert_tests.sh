#!/bin/bash
cd ../../project/ex00/

printf "===== arg tests =====\n"
./convert
printf "\n"
./convert 9 8
printf "\n"

printf "===== inf tests =====\n"
./convert "+inff"
printf "\n"
./convert "-inff"
printf "\n"
./convert "+inf"
printf "\n"
./convert "-inf"
printf "\n"

printf "===== nan tests =====\n"
./convert "nan"
printf "\n"
./convert "nanf"
printf "\n"

printf "===== char tests =====\n"
counter=0
while [ $counter -le 127 ]
do
  if [ $counter -eq 0 ]; then
    printf "input: NULL\n"
  elif [ $counter -eq 10 ]; then
    printf "input: new_line\n"
  fi
  ./convert "$(printf \\$(printf '%03o' $counter))"
  printf "\n"
  ((counter++))
done

printf "===== int tests =====\n"
./convert 2147483647
printf "\n"
./convert -2147483648
printf "\n"
./convert 8
printf "\n"
./convert 0
printf "\n"
./convert -98
printf "\n"

printf "===== float tests =====\n"
./convert 98.98f
printf "\n"
./convert 98.f
printf "\n"
./convert 0.0f
printf "\n"
./convert -4.2f
printf "\n"
./convert 4.2f
printf "\n"
./convert 23.f
printf "\n"

printf "===== double tests =====\n"
./convert 4.2
printf "\n"
./convert 9.8
printf "\n"
./convert 0.0
printf "\n"
./convert 23.5
printf "\n"

printf "===== error tests =====\n"
# error int
./convert 2147483648
printf "\n"
./convert -2147483649
printf "\n"
# error float
./convert 98.98.98f
printf "\n"
./convert 1.2ff
printf "\n"
./convert 1.b2f
printf "\n"
./convert 4-.2f
printf "\n"

