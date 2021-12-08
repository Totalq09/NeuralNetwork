#include "NeuralNetworkLogger.h"
#include <iostream>

NeuralNetworkLogger::NeuralNetworkLogger(int layersCount,
	const int* const layers,
	const float** neurons,
	const float** biases,
	const float*** weights,
	const float** activations): layersCount(layersCount), layers(layers), neurons(neurons), biases(biases), weights(weights), activations(activations)
{
}

void NeuralNetworkLogger::printData()
{
	this->printOutputs();
	this->printNeurons();
	this->printBiases();
	this->printWeights();
}

void NeuralNetworkLogger::printNeurons()
{
	std::cout << std::endl << "NEURONS:" << std::endl;

	for (int i = 0; i < this->layersCount; i++)
	{
		for (int j = 0; j < this->layers[i]; j++)
		{
			std::cout << i << "-" << j << ": " << this->neurons[i][j] << std::endl;
		}
	}
}

void NeuralNetworkLogger::printOutputs()
{
	std::cout << std::endl << "OUTPUTS:" << std::endl;

	for (int i = 0; i < this->layersCount; i++)
	{
		for (int j = 0; j < this->layers[i]; j++)
		{
			std::cout << i << "-" << j << ": " << this->neurons[i][j] << std::endl;
		}
	}
}

void NeuralNetworkLogger::printBiases()
{
	std::cout << std::endl << "BIASES:" << std::endl;

	for (int i = 0; i < this->layersCount; i++)
	{
		for (int j = 0; j < this->layers[i]; j++)
		{
			std::cout << i << "-" << j << ": " << this->biases[i][j] << std::endl;
		}
	}
}

void NeuralNetworkLogger::printWeights()
{
	std::cout << std::endl << "WEIGHTS:" << std::endl;

	for (int i = 0; i < this->layersCount; i++)
	{
		for (int j = 0; j < this->layers[i]; j++)
		{
			for (int k = 0; k < this->layers[i]; k++)
			{
				std::cout << i << "-" << j << "-" << k << ": " << this->weights[i][j][k] << std::endl;
			}
		}
	}
}