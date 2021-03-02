/*
 * ExampleWindow.h
 *
 *  Created on: 21 февр. 2021 г.
 *      Author: Natalia.Kukushkina
 */

#ifndef EXAMPLEWINDOW_H_
#define EXAMPLEWINDOW_H_

#include "Window.h"

class ExampleWindow: public Window
{
protected:
	std::shared_ptr<SDL_Texture> _sky,_stardestroyer, _mountains, _cloud, _cloud1, _twosuns, _desert, _xwing, _obj1, _obj2;

	int
			_sky_x,
			_sky_y,
			_sky_x2,

			_width_twosuns,
			_twosuns_x,
			_twosuns_y,

			_width_cloud,
			_cloud_x,
			_cloud_y,
			_cloud_x2,
			_cloud_x3,
			_cloud_x4,
			_cloud_x5,
			_cloud_x6,

			_obj1_x,
			_obj1_y,
			_obj1_x2,

			_obj2_x,
			_obj2_y,
			_obj2_x2,

			_mountains_y,

			_desert_x,
			_desert_y,
			_desert_x2,

			_xwing_x,
			_xwing_y,

			_stardestroyer_x,
			_stardestroyer_y;

public:
	ExampleWindow(
			int width = DEFAULT_WIDTH,
			int height = DEFAULT_HEIGHT);
	virtual ~ExampleWindow() = default;

	virtual void render() override;
	virtual void do_logic() override;
	virtual void handle_keys(const Uint8 *keys) override;
};



#endif /* EXAMPLEWINDOW_H_ */
