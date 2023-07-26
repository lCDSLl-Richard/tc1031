for i in 1 2 3 4
do
  g++ test$i.cpp -std=c++11 -o test$i
done

for i in 1 2 3 4
do
  ./test$i
done