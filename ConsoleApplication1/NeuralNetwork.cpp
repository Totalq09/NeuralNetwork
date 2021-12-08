#include "NeuralNetwork.h"
#include <iostream>

NeuralNetwork::NeuralNetwork(int layers[], int size)
{
	this->initLayers(layers, size);
	this->initNeurons();
	this->initBiases();
	this->initWeights();

	logger = new NeuralNetworkLogger(
		this->layersCount,
		const_cast<const int*>(this->layers), 
		const_cast<const float**>(this->neurons), 
		const_cast<const float**>(this->biases), 
		const_cast<const float***>(this->weights), 
		const_cast<const float**>(this->activations));
}

void NeuralNetwork::initLayers(int layers[], int size)
{
	this->layersCount = size;
	this->layers = new int[size] ;

	for (int i = 0; i < size; i++)
	{
		this->layers[i] = layers[i];
	}
}

void NeuralNetwork::initNeurons()
{
	this->neurons = new float* [this->layersCount];

	for (int i = 0; i < this->layersCount; i++)
	{
		this->neurons[i] = new float[this->layers[i]];
	}
}

void NeuralNetwork::initBiases()
{
	this->biases = new float* [this->layersCount];

	for (int i = 0; i < this->layersCount; i++)
	{
		this->biases[i] = new float[this->layers[i]];

		for (int j = 0; j < this->layersCount; j++)
		{
			this->biases[i][j] = this->getNextRandom(-1, 1);
		}
	}
}

void NeuralNetwork::initWeights() 
{
	this->weights = new float** [this->layersCount];

    this->weights[0] = new float* [this->layers[0]];

	for (int i = 0; i < this->layers[0]; i++)
	{
		this->weights[0][i] = new float[this->layers[0]];

		for (int j = 0; j < this->layers[0]; j++)
		{
			this->weights[0][i][j] = 1.0;
		}
	}

	for (int layer = 1; layer < this->layersCount; layer++)
	{
		int neuronsInPreviousLayer = this->layers[layer - 1];
		this->weights[layer] = new float*[neuronsInPreviousLayer];

		for (int neuronInLayer = 0; neuronInLayer < this->layers[layer]; neuronInLayer++)
		{
			this->weights[layer][neuronInLayer] = new float[neuronsInPreviousLayer];

			for (int outgoingWeight = 0; outgoingWeight < neuronsInPreviousLayer; outgoingWeight++)
			{
				this->weights[layer][neuronInLayer][outgoingWeight] = this->getNextRandom(-1, 1);
			}
		}
	}
}

float NeuralNetwork::activate(float value)
{
	return tanh(value);
}

float* NeuralNetwork::feedForward(float inputs[], int size)
{
	if (size != this->layers[0])
		throw new std::exception("Invalid input size");

	for (int i = 0; i < size; i++)
	{
		this->neurons[0][i] = inputs[i];
	}

	for (int i = 1; i < this->layersCount; i++)
	{
		for (int j = 0; j < this->layers[i]; j++)
		{
			float value = 0.0;

			for (int k = 0; k < this->layers[i - 1]; k++)
			{
				float weightValue = this->weights[i - 1][j][k];
				float neuronValue = this->neurons[i - 1][k];
				value += weightValue * neuronValue;
			}

			this->neurons[i][j] = this->activate(value + this->biases[i][j]);
		}
	}

	return this->neurons[layersCount - 1];
}

float NeuralNetwork::getNextRandom(int min, int max)
{
	return 2 * (rand() / (double)RAND_MAX) - 1;
}