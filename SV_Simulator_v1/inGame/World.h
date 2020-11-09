#pragma once
#include <string>

class Country;

class World
{
private:
	Country* countries; //전세계 모든 국가 포인터
	int countryNum; // (+)추가변수 : 국가 개수
	float worldTemperature; //전세계 평균온도
	long long worldCarbonEmission; //전세계 탄소배출량
	long long worldPopulation; //전세계 인구수
	long long worldCarbonAbsorbing; //전세계 탄소흡수량
	float worldCarbonPPM; //전세계 평균탄소농도(ppm)
	
public:
	/*#####################################
	1. 초기화 되어야 하는 부분
		# 생성자 
			-국가 개수 초기화
			-국가 생성
			-평균 온도 초기화 
			-탄소배출량 초기화
			-인구수 초기화 
			-탄소흡수량 초기화
			-탄소 농도 초기화
		
	
	2. 주기 별로 계산이 필요한 함수
		# 전세계 평균온도 계산 (탄소 농도 필요)
		# 탄소농도계산 (탄소배출량과 흡수량 필요)
		# 전세계 탄소배출량 합산
		# 전세계 탄소흡수량 합산
		# 전세계 인구수 계산
	
	3. 이벤트 함수
		# 탄소배출량 변화되는 이벤트 시 호출 (갱신)
		# 탄소흡수량 변화되는 이벤트 시 호출 (갱신)
		
	#########################################*/

	///<summary>
	///#함수 역할 : 멤버변수들을 초기화시켜주는 생성자 함수 
	///#매개변수 countiryNum : 생성할 국가 개수
	///</summary>
	World(int countryNum); 

	///<summary>
	///#함수 역할 : 모든 국가의 인구수를 합산하는 함수
	///</summary>
	void total_PopulationOfCountries();

	///<summary>
	///#함수 역할 : 모든 국가의 탄소배출량을 합산하는 함수
	///</summary>
	void total_CarbonEmissionOfCountries();

	///<summary>
	///#함수 역할 : 모든 국가의 탄소흡수량을 합산하는 함수
	///</summary>
	void total_CarbonAbsorbingOfCountries();

	///<summary>
	///#함수 역할 : 세계 온도를 계산하는 함수
	///#w1 = 0.008984563 , b=12.366367558
	///</summary>
	void calculator_worldTemperature();

	///<summary>
	///#함수 역할 : 세계 탄소 농도를 계산하는 함수
	///#w1 = 1 b=0
	///</summary>
	void calculator_worldCarbonPPM();

	void printStatus();
};