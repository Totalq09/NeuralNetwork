#pragma once

class NeuralNetworkLogger
{
private:
	const int layersCount;
	const int* const layers;
	const float** const neurons;
	const float** const biases;
	const float*** const weights;
	const float** const activations;

public:
	NeuralNetworkLogger(int layersCount,
		const int* const layers,
		const float** const neurons,
		const float** const biases,
		const float*** const weights,
		const float** const activations);

	void printNeurons();
	void printBiases();
	void printWeights();
	void printOutputs();
	void printData();
};

