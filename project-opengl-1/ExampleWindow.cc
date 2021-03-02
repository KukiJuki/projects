/*
 * ExampleWindow.cc
 *
 *  Created on: 24 февр. 2021 г.
 *      Author: Natalia.Kukushkina
 */

#include "ExampleWindow.h"

#include "Primitives.h"

#include <cmath>

static constexpr double Pi = acos(-1.);


ExampleWindow::ExampleWindow(int width, int height)
: Window(width, height),
  _textureHouse("textureHouse.png"), _textureRoof("textureRoof.png"),
  _tree("tree.png"), _treeTrunk("treeTrunk.png"), _carrot("carrot.png"), _snowmanParts("snowmanParts.png")
{

}

void ExampleWindow::setup()
{
	glEnable(GL_DEPTH_TEST);

//	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_TEXTURE);

	glClearColor(0.2f, 0.35f, 0.45f, 1.0f);

	glMatrixMode(GL_PROJECTION);
	gluPerspective(65.0, double(width()) / double(height()), 0.1, 30.0);
	glMatrixMode(GL_MODELVIEW);

}

//стены дома
static VertexVector s_cube_vertices {
	{  -6.0,  -2.0,  2.7 },
	{  -6.0,  1.0,  2.7 },
	{ -10.0,  1.0,  2.7 },
	{ -10.0,  -2.0,  2.7 },
	{  -6.0,  -2.0,  0.0 },
	{  -6.0,  1.0,  0.0 },
	{ -10.0,  1.0,  0.0 },
	{ -10.0,  -2.0,  0.0 },
};

static FaceVector s_cube_faces {
	{ 4, 0, 1, 2, 3 },
	{ 4, 7, 6, 5, 4 },
	{ 4, 1, 0, 4, 5 },
	{ 4, 3, 2, 6, 7 },
	{ 4, 0, 3, 7, 4 },
	{ 4, 2, 1, 5, 6 },
};

static NormalVector s_cube_normals {
	{  0.0,  0.0,  1.0 },
	{  0.0,  0.0, -1.0 },
	{  1.0,  0.0,  0.0 },
	{ -1.0,  0.0,  0.0 },
	{  0.0,  1.0,  0.0 },
	{  0.0, -1.0,  0.0 },
};

static ColorVector s_cube_colors {
	{  1.0f,  1.0f,  1.0f },
	{  1.0f,  1.0f,  1.0f },
	{  1.0f,  1.0f,  1.0f },
	{  1.0f,  1.0f,  1.0f },
	{  1.0f,  1.0f,  1.0f },
	{  1.0f,  1.0f,  1.0f },
};

static TexCoordVector s_cube_tex_coords {
	{ { 0.00, 0.00 }, { 0.00, 0.00 }, { 0.00, 0.00 }, { 0.00, 0.00 } },
	{ { 0.00, 0.00 }, { 0.00, 0.00 }, { 0.00, 0.00 }, { 0.00, 0.00 } },
	{ { 0.00, 0.00 }, { 0.33, 0.00 }, { 0.33, 0.50 }, { 0.00, 0.50 } },
	{ { 0.50, 0.50 }, { 1.00, 0.50 }, { 1.00, 1.00 }, { 0.50, 1.00 } },
	{ { 0.40, 0.00 }, { 1.00, 0.00 }, { 1.00, 0.50 }, { 0.40, 0.50 } },
	{ { 0.00, 0.50 }, { 0.50, 0.50 }, { 0.50, 1.00 }, { 0.00, 1.00 } },
};

// рыша дома
static VertexVector s_roof_vertices {
	{  -5.6,   -2.4,  2.5 },
	{  -5.6,   1.4,  2.5 },
	{ -10.3,   1.4,  2.5 },
	{ -10.3,   -2.4,  2.5 },
	{  -5.6,   -0.5,  4.4 },
	{ -10.3,   -0.5,  4.4 },
};

static FaceVector s_roof_faces {
	{ 4, 0, 1, 2, 3 },
	{ 4, 1, 4, 5, 2 },
	{ 4, 0, 3, 5, 4 },
	{ 3, 0, 4, 1 },
	{ 3, 2, 5, 3 },
};

static NormalVector s_roof_normals {
	{  0.0,  0.0, -1.0 },
	{  0.0,  1.0,  1.0 },
	{  0.0, -1.0,  1.0 },
	{  1.0,  0.0,  0.0 },
	{ -1.0,  0.0,  0.0 },
};

static ColorVector s_roof_colors {
	{  1.0f,  1.0f,  1.0f },
	{  1.0f,  1.0f,  1.0f },
	{  1.0f,  1.0f,  1.0f },
	{  1.0f,  1.0f,  1.0f },
	{  1.0f,  1.0f,  1.0f },
};

static TexCoordVector s_roof_tex_coords {
	{ { 0.00, 0.00 }, { 0.00, 0.00 }, { 0.00, 0.00 }, { 0.00, 0.00 } },
	{ { 0.00, 1.00 }, { 0.00, 0.00 }, { 0.45, 0.00 }, { 0.45, 1.00 } },
	{ { 0.45, 1.00 }, { 0.00, 1.00 }, { 0.00, 0.00 }, { 0.45, 0.00 } },
	{ { 0.50, 1.00 }, { 0.75, 0.20 },  { 1.00, 1.00 } },
	{ { 0.50, 1.00 }, { 0.75, 0.20 },  { 1.00, 1.00 } },
};

//ƒымоход
static VertexVector s_tube_vertices {
	{ -7.0,  0.75, 4.5 },
	{ -7.0,  0.25,  4.5 },
	{ -6.5,   0.25,  4.5 },
	{ -6.5,   0.75, 4.5 },
	{ -7.0,  0.75, 2.0 },
	{ -7.0,  0.25,  2.0 },
	{ -6.5,   0.25,  2.0 },
	{ -6.5,   0.75, 2.0 },
};

static FaceVector s_tube_faces {
	{ 4, 0, 1, 2, 3 },
	{ 4, 7, 6, 5, 4 },
	{ 4, 1, 0, 4, 5 },
	{ 4, 3, 2, 6, 7 },
	{ 4, 0, 3, 7, 4 },
	{ 4, 2, 1, 5, 6 },
};

static NormalVector s_tube_normals {
	{  0.0,  0.0,  1.0 },
	{  0.0,  0.0, -1.0 },
	{  1.0,  0.0,  0.0 },
	{ -1.0,  0.0,  0.0 },
	{  0.0,  1.0,  0.0 },
	{  0.0, -1.0,  0.0 },
};

static ColorVector s_tube_colors {
	{  0.0f,  0.0f,  0.0f },
	{  1.0f,  1.0f,  1.0f },
	{  1.0f,  1.0f,  1.0f },
	{  1.0f,  1.0f,  1.0f },
	{  1.0f,  1.0f,  1.0f },
	{  1.0f,  1.0f,  1.0f },
};

static TexCoordVector s_tube_tex_coords {
	{ { 0.00, 0.00 }, { 0.00, 0.00 }, { 0.00, 0.00 }, { 0.00, 0.00 } },
	{ { 0.00, 0.00 }, { 0.00, 0.00 }, { 0.00, 0.00 }, { 0.00, 0.00 } },
	{ { 0.00, 0.00 }, { 1.00, 0.00 }, { 1.00, 1.00 }, { 0.00, 1.00 } },
	{ { 0.00, 0.00 }, { 1.00, 0.00 }, { 1.00, 1.00 }, { 0.00, 1.00 } },
	{ { 0.00, 0.00 }, { 1.00, 0.00 }, { 1.00, 1.00 }, { 0.00, 1.00 } },
	{ { 0.00, 0.00 }, { 1.00, 0.00 }, { 1.00, 1.00 }, { 0.00, 1.00 } },
};


SimpleModel cube { s_cube_vertices, s_cube_faces, s_cube_normals, s_cube_colors, s_cube_tex_coords };
SimpleModel roof { s_roof_vertices, s_roof_faces, s_roof_normals, s_roof_colors, s_roof_tex_coords };
SimpleModel tube { s_tube_vertices, s_tube_faces, s_tube_normals, s_tube_colors, s_tube_tex_coords };

void ExampleWindow::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	gluLookAt(10.0, 10.0, 10.0,
			  0.0, 0.0, 0.0,
			  0.0, 0.0, 1.0);


	glRotated(_angle, 0.0, 0.0, 1.0);

	_textureHouse.bind();
	glEnable(GL_TEXTURE_2D);
	draw_model(cube);
	glDisable(GL_TEXTURE_2D);

	_textureRoof.bind();
	glEnable(GL_TEXTURE_2D);
	draw_model(roof);
	glDisable(GL_TEXTURE_2D);

	_textureRoof.bind();
	glEnable(GL_TEXTURE_2D);
	draw_model(tube);
	glDisable(GL_TEXTURE_2D);

	_tree.bind();
	glEnable(GL_TEXTURE_2D);
	draw_cone_tree(20, 0., 0., 2.5, 1, 1.0);
	draw_cone_tree(20, 0., 0., 3, 2.0, 0.9);
	draw_cone_tree(20, 0., 0., 4, 3.0, 0.7);
	glDisable(GL_TEXTURE_2D);

	draw_sphere_smooth(64, 32, 2+xx, 2+yy, 0.5+zz, 0.5);
	draw_sphere_smooth(64, 32, 2+xx, 2+yy, 1.2+zz, 0.35);
	draw_sphere_smooth(64, 32, 2+xx, 2+yy, 1.7+zz, 0.2);

	draw_sphere_smooth(32, 16, 1.5, -4, 0.5, 0.5);
	draw_sphere_smooth(32, 16, 1.5, -4, 1.2, 0.35);
	draw_sphere_smooth(32, 16, 1.5, -4, 1.7, 0.2);

	draw_sphere_smooth(32, 16, -1, -5, 0.5, 0.5);
	draw_sphere_smooth(32, 16, -1, -5, 1.2, 0.35);
	draw_sphere_smooth(32, 16, -1, -5, 1.7, 0.2);

	draw_sphere_smooth(32, 16, -3.5, -4, 0.5, 0.5);
	draw_sphere_smooth(32, 16, -3.5, -4, 1.2, 0.35);
	draw_sphere_smooth(32, 16, -3.5, -4, 1.7, 0.2);

	draw_sphere_smooth(32, 16, -1.5, 4, 0.5, 0.5);
	draw_sphere_smooth(32, 16, -1.5, 4, 1.2, 0.35);
	draw_sphere_smooth(32, 16, -1.5, 4, 1.7, 0.2);

	draw_sphere_smooth(32, 16, 1, 5, 0.5, 0.5);
	draw_sphere_smooth(32, 16, 1, 5, 1.2, 0.35);
	draw_sphere_smooth(32, 16, 1, 5, 1.7, 0.2);

	draw_sphere_smooth(32, 16, 3.5, 4, 0.5, 0.5);
	draw_sphere_smooth(32, 16, 3.5, 4, 1.2, 0.35);
	draw_sphere_smooth(32, 16, 3.5, 4, 1.7, 0.2);

	_snowmanParts.bind();
	glEnable(GL_TEXTURE_2D);
	//jumping snowman
	if (k == 1) {
		draw_sphere_smooth(32, 16, 2+xx, 1.50+yy, 0.5+zz, 0.06);
		draw_sphere_smooth(32, 16, 2+xx, 1.65+yy, 1.2+zz, 0.06);
	}
	if (k == 2) {
		draw_sphere_smooth(32, 16, 1.5+xx, 2.0+yy, 0.5+zz, 0.06);
		draw_sphere_smooth(32, 16, 1.65+xx, 2.0+yy, 1.2+zz, 0.06);
	}
	if (k == 3) {
		draw_sphere_smooth(32, 16, 2.2+xx, 2.3+yy, 0.5+zz, 0.06);
		draw_sphere_smooth(32, 16, 2.2+xx, 2.3+yy, 1.2+zz, 0.06);
	}
	if (k == 4) {
		draw_sphere_smooth(32, 16, 2.5+xx, 2.0+yy, 0.5+zz, 0.06);
		draw_sphere_smooth(32, 16, 2.35+xx, 2.0+yy, 1.2+zz, 0.06);
	}
	//1
	draw_sphere_smooth(32, 16, 1.5, -3.50, 0.5, 0.06);
	draw_sphere_smooth(32, 16, 1.5, -3.65, 1.2, 0.06);
	//1 - глаза
	draw_sphere_smooth(32, 16, 1.45, -3.82, 1.78, 0.025);
	draw_sphere_smooth(32, 16, 1.6, -3.82, 1.78, 0.025);
	//2
	draw_sphere_smooth(32, 16, -1, -4.50, 0.5, 0.06);
	draw_sphere_smooth(32, 16, -1, -4.65, 1.2, 0.06);
	//2 - глаза
	draw_sphere_smooth(32, 16, -0.9, -4.82, 1.78, 0.025);
	draw_sphere_smooth(32, 16, -1.06, -4.82, 1.78, 0.025);
	//3
	draw_sphere_smooth(32, 16, -3.5, -3.50, 0.5, 0.06);
	draw_sphere_smooth(32, 16, -3.5, -3.65, 1.2, 0.06);
	//3 - глаза
	draw_sphere_smooth(32, 16, -3.45, -3.82, 1.78, 0.025);
	draw_sphere_smooth(32, 16, -3.57, -3.82, 1.78, 0.025);
	//4
	draw_sphere_smooth(32, 16, -1.5, 3.50, 0.5, 0.06);
	draw_sphere_smooth(32, 16, -1.5, 3.65, 1.2, 0.06);
	//4 - глаза
	draw_sphere_smooth(32, 16, -1.45, 3.82, 1.78, 0.025);
	draw_sphere_smooth(32, 16, -1.6, 3.82, 1.78, 0.025);
	//5
	draw_sphere_smooth(32, 16, 1, 4.50, 0.5, 0.06);
	draw_sphere_smooth(32, 16, 1, 4.65, 1.2, 0.06);
	//5 - глаза
	draw_sphere_smooth(32, 16, 0.9, 4.82, 1.78, 0.025);
	draw_sphere_smooth(32, 16, 1.06, 4.82, 1.78, 0.025);
	//6
	draw_sphere_smooth(32, 16, 3.5, 3.50, 0.5, 0.06);
	draw_sphere_smooth(32, 16, 3.5, 3.65, 1.2, 0.06);
	//6 - глаза
	draw_sphere_smooth(32, 16, 3.45, 3.82, 1.78, 0.025);
	draw_sphere_smooth(32, 16, 3.57, 3.82, 1.78, 0.025);
	glDisable(GL_TEXTURE_2D);

	_treeTrunk.bind();
	glEnable(GL_TEXTURE_2D);
	draw_prism_smooth(32, 0., 0.);
	glDisable(GL_TEXTURE_2D);

	_carrot.bind();
		glEnable(GL_TEXTURE_2D);
		if (k == 1)
			draw_pyramid(32, 2+xx, 1.7+zz, 1.5+yy, 1.9+yy, 0.03);
		if (k == 2)
			draw_cone_orange(32, 1.7+zz, 2+yy, 1.5+xx, 1.9+xx, 0.03);
		if (k == 3)
			draw_pyramid(32, 2+xx, 1.7+zz, 2.5+yy, 2.1+yy, 0.03);
		if (k == 4)
			draw_cone_orange(32, 1.7+zz, 2+yy, 2.5+xx, 2.1+xx, 0.03);

	draw_pyramid(32, 1.5, 1.7, -3.6, -4, 0.03);
	draw_pyramid(32, -1, 1.7, -4.6, -5, 0.03);
	draw_pyramid(32, -3.5, 1.7, -3.6, -4, 0.03);
	draw_pyramid(32, -1.5, 1.7, 3.6, 4, 0.03);
	draw_pyramid(32, 1, 1.7, 4.6, 5, 0.03);
	draw_pyramid(32, 3.5, 1.7, 3.6, 4, 0.03);
	glDisable(GL_TEXTURE_2D);

}

void ExampleWindow::draw_model(SimpleModel &model)
{
	for (unsigned i = 0; i < model.faces.size(); ++i) {
		int count = model.faces[i][0];
		if (count == 3)
			glBegin(GL_TRIANGLES);
		else if (count == 4)
			glBegin(GL_QUADS);
		else
			glBegin(GL_POLYGON);

		glNormal3dv(&model.normals[i][0]);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, &model.colors[i][0]);
		for (int j = 1; j <= count; ++j) {
			glTexCoord2dv(&model.tex_coords[i][j-1][0]);
			glVertex3dv(&model.vertices[model.faces[i][j]][0]);
		}

		glEnd();
	}
}

void ExampleWindow::do_logic()
{
	_angle -= 0.5;
	if (_angle >= 360.)
		_angle -= 360.;

	zz += 0.05 * i;
	if (zz >= 0.5) i = -1;
	else if (zz <= 0) i = 1;

	if (k == 1) {
		yy -= 0.05;
		if (yy <= -4) k = 2;
	} else if (k == 2){
		xx -= 0.05;
		if (xx <= -4) k = 3;
	} else if (k == 3){
		yy += 0.05;
		if (yy >= 0) k = 4;
	} else if (k == 4){
		xx += 0.05;
		if (xx >= 0) k = 1;
	}

	_camera_z = 5 + sin(_angle / 45. * Pi) * 6.;
}
