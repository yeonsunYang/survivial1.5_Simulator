#include "World.h"

World* World::instance = nullptr;

World::World()
{
	DataInit();
}

World::World(const World& other) : World::World()
{

}
World::~World()
{

}

void World::DataInit()
{
	needEnergy = 0;
	deltaNeedEnergy = 0;
	supplyEnergy = 0;
	deltaSupplyEnergy = 0;
	savingEnergy = 0;

	firePlants = 0;
	greenPlants = 0;

	population = 0;
	live = 0;
	dead = 0;
	dailyDead = 0;

	dailyEmission = 0;
	totalEmission = 0;
	carbonPPM_p2 = 40000;

	temperature_p2 = 0;
	startTemperature_p2 = 0;

	recognition = 0;
	deltaRecognition = 0;
}

void World::SetPopulation(int _population, int _live, int _dead)
{
	dailyDead = _dead - dead;
	population = _population;
	live = _live;
	dead = _dead;
}
void World::SetEnergy(int _need, int _dNeed, int _supply, int _dSupply, int _saving)
{
	needEnergy = _need;
	deltaNeedEnergy = _dNeed;
	supplyEnergy = _supply;
	deltaSupplyEnergy = _dSupply;
	savingEnergy = _saving;
}

void World::SetPlants(int _firePlants, int _greenPlants)
{
	firePlants = _firePlants;
	greenPlants = _greenPlants;
}
void World::SetEmission(int _emission)
{
	dailyEmission = _emission;
	totalEmission += dailyEmission;
}

void World::CalTemperature()
{
	carbonPPM_p2 += dailyEmission / 440; //기존 나누기 40에서 440으로 수정
	temperature_p2 = static_cast<int> (carbonPPM_p2 * 0.008984) + 1236;
}
void World::SetStartTemperature()
{
	startTemperature_p2 = temperature_p2;
}

void World::SetRecognition(int _recognition)
{
	deltaRecognition = _recognition - recognition;
	recognition = _recognition;
}