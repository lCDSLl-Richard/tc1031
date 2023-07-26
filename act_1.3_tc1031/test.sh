#!/bin/bash

g++ main.cpp -std=c++11 -o main
for i in 1 2 3 4
do
  ./main input$i.txt solution$i.txt
  diff output$i.txt solution$i.txt
done