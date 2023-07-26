rm main
g++ -std=c++11 -o main main.cpp
for i in {1..4}
do
  echo "Test $i"
  ./main "input$i.txt" "solution$i.txt"
  diff "output$i.txt" "solution$i.txt"
done