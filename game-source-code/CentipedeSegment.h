#ifndef CENTIPEDESEGMENT_H
#define CENTIPEDESEGMENT_H

#include "Game.h"
#include "Direction.h"
#include "Trajectory.h"
#include "Region.h"
#include <SFML/Graphics.hpp>
#include "Entity.h"

namespace GameEngine
{
	class CentipedeSegment: public Entity
	{
	public:
		CentipedeSegment(DataPtr data, bool firstSegment);

		// Address Accessor Functions
		sf::Sprite &GetSegmentSprite();

		// Mutator Functions
		void SetDead(bool isDead);
		void SetRegion(Region region);
		void SetSubRegion(Region subregion);
		void SetTopLeftXPosition(float xpos);
		void SetTopLeftYPosition(float ypos);

		// Mutators specific to CentipedeSegment
		void SetTrajectory(Trajectory trajectory);
		void SetTurningLeft(bool isTurningLeft);

		// Accessor Functions specifc to Centipede Segment
		Trajectory GetTrajectory();
		float GetCenterXPosition();
		float GetCenterYPosition();
		bool IsFirstSegment();
		bool IsTurningLeft();

	private:
		// pointer to GameData layer
		DataPtr _data;
		sf::Sprite _segment;
		// movement information
		bool _turningLeft;
		Trajectory _trajectory;
		// segment characteristics
		bool _firstSegment;
	};
}

#endif