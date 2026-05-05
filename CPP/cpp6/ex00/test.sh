#!/bin/bash

echo "BASE CASE"
./convert_scalar 0
echo -e "----------------\n"
./convert_scalar 42
echo -e "----------------\n"
./convert_scalar -42
echo -e "----------------\n"
./convert_scalar 4.2
echo -e "----------------\n"
./convert_scalar -4.2
echo -e "----------------\n"

echo "CHAR"

./convert_scalar a
echo -e "----------------\n"
./convert_scalar Z
echo -e "----------------\n"
./convert_scalar 0
echo -e "----------------\n"
./convert_scalar ~
echo -e "----------------\n"
./convert_scalar !
echo -e "----------------\n"


echo "FLOAT"


./convert_scalar 42.0f
echo -e "----------------\n"
./convert_scalar -42.0f
echo -e "----------------\n"
./convert_scalar 4.2f
echo -e "----------------\n"
./convert_scalar nanf
echo -e "----------------\n"
./convert_scalar +inff
echo -e "----------------\n"
./convert_scalar -inff
echo -e "----------------\n"


echo "WITHOUT F"

./convert_scalar 42.0
echo -e "----------------\n"
./convert_scalar -42.0
echo -e "----------------\n"
./convert_scalar 4.2
echo -e "----------------\n"
./convert_scalar nan
echo -e "----------------\n"
./convert_scalar +inf
echo -e "----------------\n"
./convert_scalar -inf
echo -e "----------------\n"



echo "SPECIAUX"
./convert_scalar nan
echo -e "----------------\n"
./convert_scalar nanf
echo -e "----------------\n"
./convert_scalar +inf
echo -e "----------------\n"
./convert_scalar +inff
echo -e "----------------\n"
./convert_scalar -inf
echo -e "----------------\n"
./convert_scalar -inff
echo -e "----------------\n"


echo "OVERFLOW "
./convert_scalar 2147483647
echo -e "----------------\n"
./convert_scalar 2147483648
echo -e "----------------\n"
./convert_scalar -2147483648
echo -e "----------------\n"
./convert_scalar -2147483649
echo -e "----------------\n"

echo "OVERFLOW FLOAT"
./convert_scalar 3.4e38f
echo -e "----------------\n"
./convert_scalar 3.5e38f
echo -e "----------------\n"

echo "OVERFLOW DOUBLE"
./convert_scalar 1.7e308
echo -e "----------------\n"
./convert_scalar 1.8e308
echo -e "----------------\n"


echo "PRECISION"
./convert_scalar 0.0000001
echo -e "----------------\n"
./convert_scalar 0.0000000000001
echo -e "----------------\n"
./convert_scalar 123456789.123456789
echo -e "----------------\n"

echo "NON PRINTABLE"
./convert_scalar 31
echo -e "----------------\n"
./convert_scalar 32
echo -e "----------------\n"
./convert_scalar 127
echo -e "----------------\n"

echo "INVALID INPUT"
./convert_scalar abc
echo -e "----------------\n"
./convert_scalar 42abc
echo -e "----------------\n"
./convert_scalar --42
echo -e "----------------\n"
./convert_scalar ++42
echo -e "----------------\n"
./convert_scalar 4.2.2
echo -e "----------------\n"
./convert_scalar f
echo -e "----------------\n"
./convert_scalar .
echo -e "----------------\n"


echo "AMBIGUS"
./convert_scalar +42
echo -e "----------------\n"
./convert_scalar -0
echo -e "----------------\n"
./convert_scalar 042
echo -e "----------------\n"
./convert_scalar 0.0f
echo -e "----------------\n"

echo "EXTREME"
./convert_scalar ""
echo -e "----------------\n"
./convert_scalar " "
echo -e "----------------\n"
./convert_scalar "\t"
echo -e "----------------\n"


echo "char deguise"
./convert_scalar 'a'
echo -e "----------------\n"
