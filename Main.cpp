#include<stdio.h>
#include <vector>
#include<iostream>
#include<time.h>
using namespace std;


float sigmoid(float x)
{
	return (1 / (1 + exp(-x)));
}

vector<float> randomLayer(vector<float> input) {
	for (int i = 0; i < input.size(); i++) {
		input[i] = (float)rand() / (float)RAND_MAX;
	}
	return input;
}

vector<float> createLayer(int numberOfNeurons) {
	vector<float> Layer(numberOfNeurons);
	return Layer;
}

vector<vector<float>> generateRandomWeights(vector<float> L1, vector<float> L2) {
	vector<vector<float>> weights;
	for (int L2neuron = 0; L2neuron < L2.size(); L2neuron++) {
		weights.push_back(vector<float>());
		for (int L1neuron = 0; L1neuron < L1.size(); L1neuron++) {
			weights[L2neuron].push_back(10*(float)rand()/(float)RAND_MAX-5);
		}
	}
	return weights;
}

vector<float> activateNextLayer(vector<float> L1, vector<float> L2, vector<vector<float>> weights) {
	for (int L2neuron = 0; L2neuron < L2.size(); L2neuron++) {
		float total = 0;
		for (int L1neuron = 0; L1neuron < L1.size(); L1neuron++) {
			total = total + L1[L1neuron] * weights[L2neuron][L1neuron];
		}
		L2[L2neuron] = sigmoid(total);
	}
	return L2;
}

int main() {
	srand(time(0));
	vector<float> L1 = createLayer(2);
	vector<float> L2 = createLayer(1);

	L1 = randomLayer(L1);

	vector<vector<float>> weights = generateRandomWeights(L1, L2);

	L2 = activateNextLayer(L1, L2, weights);

	for (int i = 0; i < L2.size(); i++) {
		printf("%f\n", L2[i]);
	}
	return 1;
}