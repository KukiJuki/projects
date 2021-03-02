/*
 * ExampleWindow.cc
 *
 *  Created on: 21 февр. 2021 г.
 *      Author: Natalia.Kukushkina
 */
#include "ExampleWindow.h"

#include <stdexcept>
#include <SDL2/SDL_image.h>

ExampleWindow::ExampleWindow(int width, int height) :
		Window(width, height),
		_sky_x(0),
		_sky_y(0),
		_sky_x2(width),

		_width_twosuns(width/5),
		_twosuns_x(width),
		_twosuns_y(10),

		_width_cloud(width / 4),
		_cloud_x(width),
		_cloud_y(height / 90),
		_cloud_x2(_width_cloud*2),
		_cloud_x3(_width_cloud*3),
		_cloud_x4(_width_cloud*10),
		_cloud_x5(_width_cloud*5),
		_cloud_x6(_width_cloud*20),

		_obj1_x(100),
		_obj1_y(450),
		_obj1_x2(2600),

		_obj2_x(50),
		_obj2_y(570),
		_obj2_x2(width/8*7),
		_mountains_y(160),

		_desert_x(0),
		_desert_y(height/5*3),
		_desert_x2(width),

		_xwing_x(0),
		_xwing_y(300),



		_stardestroyer_x(0),
		_stardestroyer_y(height/15)


		{

	_sky = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "sky.png"), SDL_DestroyTexture);
			if (_sky == nullptr)
				throw std::runtime_error(
						std::string("Не удалось загрузить небо: ")
						+ std::string(SDL_GetError()));

	_mountains = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "mountains.png"), SDL_DestroyTexture);
			if (_mountains == nullptr)
				throw std::runtime_error(
						std::string("Не удалось загрузить горы: ")
						+ std::string(SDL_GetError()));

	_cloud = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "cloud.png"), SDL_DestroyTexture);
	_cloud1 = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "cloud1.png"), SDL_DestroyTexture);
			if (_cloud == nullptr || _cloud1 == nullptr)
				throw std::runtime_error(
						std::string("Не удалось загрузить облака: ")
						+ std::string(SDL_GetError()));

	_twosuns = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "twosuns.png"), SDL_DestroyTexture);
			if (_twosuns == nullptr)
				throw std::runtime_error(
						std::string("Солнце было уничтожено Звездой Смерти: ")
						+ std::string(SDL_GetError()));

	_desert = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "desert.png"), SDL_DestroyTexture);
			if (_desert == nullptr)
				throw std::runtime_error(
						std::string("Не удалось загрузить пустыню: ")
						+ std::string(SDL_GetError()));

	_xwing = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "xwing.png"), SDL_DestroyTexture);
			if (_xwing == nullptr)
				throw std::runtime_error(
						std::string("Не удалось загрузить x-wing: ")
						+ std::string(SDL_GetError()));

	_obj1 = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "obj1.png"), SDL_DestroyTexture);
	_obj2 = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "obj2.png"), SDL_DestroyTexture);
			if (_obj1 == nullptr || _obj2 == nullptr)
				throw std::runtime_error(
						std::string("Не удалось загрузить objects: ")
						+ std::string(SDL_GetError()));

	_stardestroyer = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "stardestroyer.png"),
			SDL_DestroyTexture);
			if (_stardestroyer == nullptr)
				throw std::runtime_error(
						std::string("Не удалось загрузить stardestroyer: ")
						+ std::string(SDL_GetError()));
}

void ExampleWindow::render() {
	SDL_SetRenderDrawColor(_renderer.get(), 32, 32, 96, 255);
	SDL_RenderClear(_renderer.get());

	SDL_Rect sky_rect { _sky_x, _sky_y, width(), height() };
	SDL_Rect sky_rect2 { _sky_x2, _sky_y, width(), height() };
	SDL_Rect desert_rect{ _desert_x, _desert_y, width(), height()/2};
	SDL_Rect desert_rect2{ _desert_x2, _desert_y, width(), height()/2};
	SDL_Rect mountains_rect { _sky_x, _mountains_y, width(), height() / 2 };
	SDL_Rect mountains_rect2 { _sky_x2, _mountains_y, width(), height() / 2 };
	SDL_Rect obj1_rect{ _obj1_x, _obj1_y, 30, 100};
	SDL_Rect obj1_rect2{ _obj1_x2, _obj1_y, 30, 100};
	SDL_Rect stardestroyer_rect{ _stardestroyer_x, _stardestroyer_y, width()/2, height()/3};
	SDL_Rect obj2_rect{ _obj2_x, _obj2_y, 200, 200};
	SDL_Rect obj2_rect2{ _obj2_x2, _obj2_y, 200, 200};
	SDL_Rect cloud_rect { _cloud_x, _cloud_y + 100, _width_cloud, height() / 7 };
	SDL_Rect cloud_rect2 { _cloud_x2, _cloud_y + 175, _width_cloud, 180};
	SDL_Rect cloud_rect3 { _cloud_x3, _cloud_y + 45, _width_cloud, height() / 7 };
	SDL_Rect cloud_rect4 { _cloud_x4, _cloud_y + 175, _width_cloud, 180};
	SDL_Rect cloud_rect5 { _cloud_x5, _cloud_y + 45, _width_cloud, height() / 7 };
	SDL_Rect cloud_rect6 { _cloud_x6, _cloud_y + 175, _width_cloud, 180 };
	SDL_Rect twosuns_rect{ _twosuns_x, _twosuns_y, _width_twosuns, _width_twosuns};

	SDL_Rect xwing_rect{ _xwing_x, _xwing_y, width()/5, height()/6};

	SDL_RenderCopy(_renderer.get(), _sky.get(), nullptr, &sky_rect);
	SDL_RenderCopyEx(_renderer.get(), _sky.get(), nullptr, &sky_rect2, 0, nullptr, SDL_FLIP_HORIZONTAL);
	SDL_RenderCopy(_renderer.get(), _cloud1.get(), nullptr, &cloud_rect2);
	SDL_RenderCopy(_renderer.get(), _cloud1.get(), nullptr, &cloud_rect4);
	SDL_RenderCopy(_renderer.get(), _cloud1.get(), nullptr, &cloud_rect6);
	SDL_RenderCopy(_renderer.get(), _twosuns.get(), nullptr, &twosuns_rect);
	SDL_RenderCopy(_renderer.get(), _mountains.get(), nullptr, &mountains_rect);
	SDL_RenderCopy(_renderer.get(), _mountains.get(), nullptr, &mountains_rect2);
	SDL_RenderCopy(_renderer.get(), _desert.get(), nullptr, &desert_rect);
	SDL_RenderCopyEx(_renderer.get(), _desert.get(), nullptr, &desert_rect2, 0, nullptr, SDL_FLIP_HORIZONTAL);
	SDL_RenderCopy(_renderer.get(), _cloud.get(), nullptr, &cloud_rect);
	SDL_RenderCopy(_renderer.get(), _cloud.get(), nullptr, &cloud_rect5);
	SDL_RenderCopy(_renderer.get(), _cloud.get(), nullptr, &cloud_rect3);
	SDL_RenderCopy(_renderer.get(), _obj1.get(), nullptr, &obj1_rect);
	SDL_RenderCopy(_renderer.get(), _obj1.get(), nullptr, &obj1_rect2);
	SDL_RenderCopy(_renderer.get(), _xwing.get(), nullptr, &xwing_rect);
	SDL_RenderCopy(_renderer.get(), _stardestroyer.get(), nullptr, &stardestroyer_rect);
	SDL_RenderCopy(_renderer.get(), _xwing.get(), nullptr, &xwing_rect);
	SDL_RenderCopy(_renderer.get(), _obj2.get(), nullptr, &obj2_rect);
	SDL_RenderCopy(_renderer.get(), _obj2.get(), nullptr, &obj2_rect2);

}

void ExampleWindow::do_logic() {
	_sky_x -= 1;
	_sky_x2 -= 1;
	_cloud_x -= 3;
	_cloud_x2 -= 3;
	_cloud_x3 -= 3;
	_cloud_x4 -= 3;
	_cloud_x5 -= 3;
	_cloud_x6 -= 3;
	_twosuns_x -= 2;
	_desert_x -= 1;
	_desert_x2 -= 1;
	_xwing_x += 4;
	_obj1_x -= 2;
	_obj1_x2 -= 2;
	_stardestroyer_x += 1;
	_obj2_x -= 3;
	_obj2_x2 -= 3;
	if (_sky_x <= 0 - width()) {
		_sky_x = width();
	}
	if (_sky_x2 <= 0 - width()) {
		_sky_x2 = width();
	}
	if (_xwing_x > width()) {
		_xwing_x = -width()/2;
	}
	if (_obj1_x <= 0 - width()/4) {
		_obj1_x = width();
	}
	if (_obj1_x2 <= 0 - width()/4) {
		_obj1_x2 = width();
	}
	if (_stardestroyer_x > width()) {
		_stardestroyer_x = -width()/2;
	}
	if (_obj2_x <= 0 - width()/2) {
		_obj2_x = width();
	}
	if (_obj2_x2 <= 0 - width()/2) {
		_obj2_x2 = width();
	}
	if (_cloud_x <= -_width_cloud) {
		_cloud_x = width();
	}
	if (_cloud_x2 <= -_width_cloud) {
		_cloud_x2 = width();
	}
	if (_cloud_x3 <= -_width_cloud) {
		_cloud_x3 = width();
	}
	if (_cloud_x4 <= -_width_cloud) {
		_cloud_x4 = width();
	}
	if (_cloud_x5 <= -_width_cloud) {
		_cloud_x5 = width();
	}
	if (_cloud_x6 <= -_width_cloud) {
		_cloud_x6 = width();
	}
	if (_twosuns_x <= 0-_width_twosuns) {
		_twosuns_x = width();
	}
	if (_sky_x <= 0 - width()) {
		_sky_x = width();
	}
	if (_sky_x2 <= 0 - width()) {
		_sky_x2 = width();
	}
	if (_desert_x <= 0 - width()) {
		_desert_x = width();
	}
	if (_desert_x2 <= 0 - width()) {
		_desert_x2 = width();
	}
}

void ExampleWindow::handle_keys(const Uint8 *keys) {
	if (keys[SDL_SCANCODE_DOWN] && _xwing_y < (350))
		_xwing_y += 3;
	if (keys[SDL_SCANCODE_UP] && _xwing_y > (59))
		_xwing_y -= 3;
}




