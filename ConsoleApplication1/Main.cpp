// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "NeuralNetwork.h"

int main()
{
    srand(time(NULL));

    const int INPUT_SIZE = 9;
    NeuralNetwork neuralNetwork(new int[] {INPUT_SIZE, 4, 3}, 3);

    float* output = neuralNetwork.feedForward(new float[INPUT_SIZE] {1, 2, 3, 4, 5,6,7,8,9}, INPUT_SIZE);

    neuralNetwork.logger->printData();
}