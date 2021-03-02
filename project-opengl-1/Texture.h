/*
 * Texture.h
 *
 *  Created on: 24 февр. 2021 г.
 *      Author: Natalia.Kukushkina
 */

#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <GL/gl.h>
#include <GL/glu.h>

class Texture
{
protected:
	GLuint _tex;
public:
	Texture(const char * filename);
	virtual ~Texture();

	void bind();
};
#endif /* TEXTURE_H_ */
