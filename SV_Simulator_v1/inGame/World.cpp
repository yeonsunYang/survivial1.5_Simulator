#include "World.h"
#include "Country.h"
#include <iostream>
using namespace std;
///<summary>
	///#함수 역할 : 멤버변수들을 초기화시켜주는 생성자 함수 
	///#매개변수 countiryNum : 생성할 국가 개수
	///</summary>
World::World()
{
	countries = new Country[COUNTRY_NUM];
	
	//매개변수 : 국가코드 / 산업개수 / gdp / 세율 / 인구 수 / 탄소배출량
	countries[KOR].init_Country(KOR,16190000, 0.3, 51640000, 411290);
	countries[USA].init_Country(USA,205400000, 0.2, 328200000, 5269520);

	this->worldCarbonPPM = 411.29; //(2020년 9월 기준 농도)
	calculator_worldTemperature(); //초기화한 농도 기준으로 평균온도 적용
	total_CarbonEmissionOfCountries();//전세계 탄소배출량 합산값으로 초기화
}


///<summary>
///#함수 역할 : 모든 국가의 탄소배출량을 합산하는 함수
///</summary>
void World::total_CarbonEmissionOfCountries()
{
	this->worldCarbonEmission = 0;
	for (int i = 0; i < COUNTRY_NUM; i++)
	{
		this->worldCarbonEmission += this->countries[i].carbonEmission;
	}
}

///<summary>
///#함수 역할 : 세계 온도를 계산하는 함수
///#w1 = 0.008984563 , b=12.366367558
///</summary>
void World::calculator_worldTemperature()
{
	this->worldTemperature = 0.008984563 * this->worldCarbonPPM + 12.366367558;
}

///<summary>
///#함수 역할 : 세계 탄소 농도를 계산하는 함수
///#w1 = 1.2 b=0
///</summary>
void World::calculator_worldCarbonPPM()
{
	this->worldCarbonPPM = 0.001* (this->worldCarbonEmission);
}

///<summary>
///#함수 역할 : 디버깅 용 테스트 함수
///</summary>
void World::printStatus()
{
	cout << "countryNum: " << COUNTRY_NUM << endl; // (+)추가변수 : 국가 개수
	cout << "worldTemperature: " << worldTemperature << endl; //전세계 평균온도
	cout << "worldCarbonEmission: " << worldCarbonEmission << endl; //전세계 탄소배출량
	cout << "worldPopulation: " << worldPopulation << endl; //전세계 인구수
	cout << "worldCarbonPPM: " << worldCarbonPPM << endl; //전세계 평균탄소농도(ppm)
	
}