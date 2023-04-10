#pragma once
#include <RotatedPlanarCode.h>
#include <decoder.h>

class Simulation
{
public:
	Simulation(Engine* e) {
		m_Code = new RotatedPlanarCode(codeDistance);
		m_RenderEngine = e;

		srand((int)time(NULL));

		Decoder decoder;
	};
	~Simulation() {};

	int codeDistance = 7;
	float errorRate = 0.01f;
	int delay = 2; // number of frames between each successive step
	int currentExecutionStep = 0;
	bool detailedExecution = false;

	void render();
	void doTimeStep();

	bool propagateErrors();
	bool stabilizerMeasurements();
	bool assembleErrorGraph();
	bool decodeErrorGraph();
	bool fixErrors();

private:
	bool needsVisualUpdate = true;
	int current_idx = 0;
	std::vector<GenericCode::Qubit> err_qubits;
	GenericCode* m_Code;
	Decoder decoder;
	Engine* m_RenderEngine;
};

