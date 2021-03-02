/*
 * ExampleWindow.h
 *
 *  Created on: 24 февр. 2021 г.
 *      Author: Natalia.Kukushkina
 */
#pragma once
#ifndef EXAMPLEWINDOW_H_
#define EXAMPLEWINDOW_H_


#include <GL/gl.h>
#include <GL/glu.h>
#include "Window.h"
#include "Texture.h"
#include <vector>

using VertexVector = std::vector<std::vector<double>>;
using FaceVector = std::vector<std::vector<int>>;
using NormalVector = std::vector<std::vector<double>>;
using ColorVector = std::vector<std::vector<float>>;
using TexCoordVector = std::vector<std::vector<std::vector<double>>>;

struct SimpleModel
{
	VertexVector & vertices;
	FaceVector & faces;
	NormalVector & normals;
	ColorVector & colors;
	TexCoordVector & tex_coords;
};


class ExampleWindow: public Window
{
protected:
	double _camera_z { 0. };
	double _angle { 45. };
	double zz = 0., i = 1, k = 2;
	double xx = 0, yy = 0;

	Texture _textureHouse;
	Texture _textureRoof;
	Texture _tree;
	Texture _treeTrunk;
	Texture _carrot;
	Texture _snowmanParts;

	void draw_model(SimpleModel &model);

public:
	ExampleWindow(int width = DEFAULT_WIDTH, int height = DEFAULT_HEIGHT);
	virtual ~ExampleWindow() = default;

	virtual void setup() override;
	virtual void render() override;
	virtual void do_logic() override;
};

#endif /* EXAMPLEWINDOW_H_ */
