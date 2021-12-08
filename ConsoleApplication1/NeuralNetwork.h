#pragma once
#include "Consts.h"
#include <iterator>
#include <random>
#include "NeuralNetworkLogger.h"

class NeuralNetwork
{
private:
	int layersCount;

	int *layers;
	float **neurons;
	float **biases;
	float ***weights;
	float **activations;

	float getNextRandom(int min, int max);

	void initLayers(int layers[], int size);
	void initNeurons();
	void initBiases();
	void initWeights();

	float activate(float value);

public:
	NeuralNetwork(int layers[], int size);

	NeuralNetworkLogger* logger;

	float* feedForward(float inputs[], int size);
};

