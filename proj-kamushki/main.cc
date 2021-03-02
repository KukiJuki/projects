/*
 * main.cc
 *
 *  Created on: 1 ���. 2021 �.
 *      Author: Natalia.Kukushkina
 */
#include <random>
#include <iostream>
#include <chrono>
#include <sstream>

	int read_int (const char *question)
	{
		int result;
		std::string inp;
		re: std::cout << question;
		std::getline (std::cin, inp);
		{
			std::stringstream inps {inp};
			inps >> result;
			if (inps.fail()){
				if (std::cin.fail()){
					std::cerr <<"������ �����-������!" << std::endl;
					exit(1);
				}
				std::cout << "������������ ����!" << std::endl;
						goto re;
			}
						else if (not inps.eof()){
							std::cout << "���������� ����� � ����� �����!" << std::endl;
							goto re;
						}

						}
		return result;
	}

	int read_int_in_range(const char * question, int min, int max)
		{
			int result;
			for(;;) {
				result = read_int(question);
				if (result>=min and result<=max)
					return result;
				std::cout << "����� ������ ���� � ��������� �� " << min << " �� " << max << std::endl;
			}
		}

int main(){
	using clk = std::chrono::system_clock;
	std::random_device rd;
	std::minstd_rand rnd{unsigned(clk::now().time_since_epoch().count())};
	std::uniform_int_distribution<> d {15,25};
	std::uniform_int_distribution <> d1{1,3};
	int lvl;
	do{
		unsigned stone = d(rnd);
		lvl = read_int_in_range("�������� ������� ���������. ������� ����� � ���������� �� ������ ������:\n"
										"1 - �����\n"
										"2 - ���������\n"
										"3 - ������\n"
										"----------------\n"
										"4 - �����\n", 1, 4);
					if (lvl==4){
						return 0;
					}else
		std::cout << "� ���� " << stone << " ������." << std::endl;
		std::cout << "�� ������ ����� �� 1 �� 3 ������." << std::endl;
		while(lvl != 4){
		std::cout << std::endl;
		std::cout << "������� ������ �����?" << std::endl;
		int x = read_int_in_range("", 1, std::min (3U, stone));
		//��������� ���� ����� ������ ������������
		stone = stone - x;

		if (stone < 26){
			std::cout << "�������� " << stone << " ������." << std::endl;}
			if (stone == 0 || stone > 25){
						std::cout << "�� ���������!\n" << std::endl;
						break;
					} else {
						unsigned computer;
						if (stone < 5 && lvl != 1){
							switch(stone){
								case 4: computer = 3; break;
								case 3: computer = 2; break;
								case 2: computer = 1; break;
							}
						} else {
							if(lvl == 1){
								computer = d1(rnd);
							} else if (lvl == 2){
								switch(x){
									case 1: computer = 3; break;
									case 2: computer = 2; break;
									case 3: computer = 1; break;
								}
							} else {
								for(unsigned i = 25; i > 0; i -= 4){
									if (i == stone){
										computer = d1(rnd);
										break;
									}
									if (stone > i){
										computer = stone - i;
										break;
									}
								}
							}
						}
						stone = stone - computer;
						std::cout << "��������� ���� " << computer << " �����." << std::endl;
						if (stone == 0 || stone > 25){
							std::cout << "�� ��������! �����������!\n" << std::endl;
							break;
						}
						std::cout << "�������� " << stone << " ������." << std::endl;
					}
			}
		}while(true);
	return 0;
}



