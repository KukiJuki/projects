/*
 * main.cc
 *
 *  Created on: 8 ����. 2021 �.
 *      Author: Natalia.Kukushkina
 */
// ������ �� 5.10.2020-6.10.2020


#include <fstream>
#include <cmath>
#include <cstdint>
#include <vector>
#include <iostream>
#include <cassert>

// ��� � ��� ��������� ��������� TGA-�����
#pragma pack(push, 1)
struct TGA_Header
{
	uint8_t id_len;			// ����� ��������������
	uint8_t pal_type;		// ��� �������
	uint8_t img_type;		// ��� �����������
	uint8_t pal_desc[5];	// �������� �������
	uint16_t x_pos;			// ��������� �� ��� X
	uint16_t y_pos;			// ��������� �� ��� Y
	uint16_t width;			// ������
	uint16_t height;		// ������
	uint8_t depth;			// ������� �����
	uint8_t img_desc;		// ��������� �����������
};
#pragma pack(pop)

constexpr uint16_t IMG_WIDTH = 1920;
constexpr uint16_t IMG_HEIGHT = 1080;
constexpr uint32_t COL_BACKGROUND = 0xff003f3f;
constexpr uint32_t COL_FOREGROUND = 0xffcfcfcf;
constexpr double rx = 20., ry = 20., rz = 190., xmax = 20., xmin = -20., ymax = 20., ymin = -20., step1 = 0.5, step2 = 0.01;


double sinc(double x)
{
	if (x == 0) return 1.;
	return sin(x) / x;
}

double my_evil_function(double x, double y)
{
	return sinc(hypot(x, y));
}

void pic(std::vector<uint32_t>& pixels, int x, int y, uint32_t c,std::vector<int>& h)
{
	if (x < 0 || x >= IMG_WIDTH) return;
	if ( y > h[x]) return;
	h[x]=y;
	if(y<0)return;
	assert(y * IMG_WIDTH + x >= 0);
	assert(y * IMG_WIDTH + x < IMG_WIDTH * IMG_HEIGHT);
	pixels[y*IMG_WIDTH + x] = c;

}

int main()
{
	// ��������� ������ ������� � ��������� ������
	std::vector<uint32_t> picture(IMG_WIDTH * IMG_HEIGHT);
	for (auto && p : picture) p = COL_FOREGROUND;
	int sx=0,sy=0;
	double z;
	std::fstream tga_file;
	std::vector<int> hor;
	hor.resize(IMG_WIDTH);
	for(auto && a:hor)
		a=IMG_HEIGHT;
	std::vector <uint32_t> k;
	k.resize(IMG_WIDTH*IMG_HEIGHT);
	for(auto && c:k)
		c=COL_BACKGROUND;



	// �������� ����������� ����������� � ���� ������� TGA
	TGA_Header hdr {};
	hdr.width = IMG_WIDTH;
	hdr.height = IMG_HEIGHT;
	hdr.depth = 32;
	hdr.img_type = 2;
	hdr.img_desc = 0x28;
	std::cout.flush();
	for (double i = xmax; i >= xmin; i -= step1) {
			for (double j = ymax; j >= ymin; j -= step2) {

				z = sinc(sqrt(i * i + j * j));
				sx = int(IMG_WIDTH / 2 - rx * i * cos(M_PI / 6) + ry * j * cos(M_PI / 6));
				sy = int(IMG_HEIGHT / 2 + rx * i * sin(M_PI / 6) + ry * j * sin(M_PI / 6) - rz * z);

					pic(k, sx, sy, COL_FOREGROUND,hor);
				}
			}
	for (auto&& a : hor)
			a = IMG_HEIGHT;
		for (double i = xmax; i >= xmin; i -= step2) {
			for (double j = ymax; j >= ymin; j -= step1) {

				z = sinc(sqrt(i * i + j * j));
				sx = int(IMG_WIDTH / 2 - rx * i * cos(M_PI / 6) + ry * j * cos(M_PI / 6));
				sy = int(IMG_HEIGHT / 2 + rx * i * sin(M_PI / 6) + ry * j * sin(M_PI / 6) - rz * z);
						pic(k, sx, sy, COL_FOREGROUND,hor);
					}
				}
	std::cout.flush();
	// ������ ����� + ��������� ����� ����
	tga_file.open("output.tga",std::ios::out|std::ios::binary);
	// ���������� ��������� � ������ ��������

	tga_file.write(reinterpret_cast<char*>(&hdr),sizeof(TGA_Header));
	tga_file.write(reinterpret_cast<char*>(&k[0]),IMG_WIDTH*IMG_HEIGHT*4);
	// ��������� ����
	tga_file.close();


	return 0;
}



