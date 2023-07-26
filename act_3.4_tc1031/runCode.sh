rm main
g++ main.cpp -o main -std=c++11
for i in {0..4}
do
    echo "Test $i"
    ./main input$i.txt solution$i.txt
    diff output$i.txt solution$i.txt
done