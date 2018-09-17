#ifndef SPIDER_H
#define SPIDER_H

#include "Entity.h"
#include "Game.h"
#include <SFML/Graphics.hpp>

namespace GameEngine
{
	class Spider: public Entity
	{
	public:
		Spider(DataPtr data);
		void SetTopLeftXPosition(float xpos);
		void SetTopLeftYPosition(float ypos);
		void SetRegion(Region region);
		void SetSubRegion(Region subregion);
		void SetDead(bool isDead);

	private:
		DataPtr _data;
	};
}

#endif