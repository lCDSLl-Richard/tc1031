rm main
g++ main.cpp -o main -std=c++11
for i in {1..4}
do
  echo "Test $i"
  ./main input$i.txt solution$i.txt
  diff solution$i.txt output$i.txt
done