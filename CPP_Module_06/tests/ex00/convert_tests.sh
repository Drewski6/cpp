#!/bin/bash
cd ../../project/ex00/

printf "===== arg tests =====\n"
./convert
./convert 9 8

printf "===== inf tests =====\n"
./convert "+inff"
./convert "-inff"
./convert "+inf"
./convert "-inf"

printf "===== nan tests =====\n"
./convert "nan"
./convert "nanf"

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
  ((counter++))
done

printf "===== int tests =====\n"
./convert 2147483647
./convert -2147483648
./convert 8
./convert 0
./convert -98

printf "===== float tests =====\n"
./convert 98.98f
./convert 98.f
./convert 0.0f
./convert -4.2f
./convert 4.2f
./convert 23.f

printf "===== double tests =====\n"

printf "===== error tests =====\n"
# error int
./convert 2147483648
./convert -2147483649
# error float
./convert 98.98.98f
./convert 1.2ff
./convert 1.b2f
./convert 23f
./convert 4-.2f

