#include "CentipedeSegment.h"
#include "DEFINITIONS.h"

namespace GameEngine
{
	CentipedeSegment::CentipedeSegment(DataPtr data, bool firstSegment):
	Entity(Direction::RIGHT, SCREEN_LHS, SCREEN_TOP),
	_data(data),
	_turningLeft(true),
	_trajectory(Trajectory::DOWNWARD),
	_firstSegment(firstSegment)
	{
		if (_firstSegment)
		{
		_segment.setTexture(_data->resources.GetTexture("Segment sprite"));
		}
		else
		{
		_segment.setTexture(_data->resources.GetTexture("Body Segment sprite"));
		}

		_segment.setPosition(Entity::GetTopLeftXPosition(), Entity::GetTopLeftYPosition());
	}

	sf::Sprite &CentipedeSegment::GetSegmentSprite()
	{
		return _segment;
	}

	void CentipedeSegment::SetDead(bool isDead)
	{
		Entity::SetDead(isDead);
	}

	void CentipedeSegment::SetTrajectory(Trajectory trajectory)
	{
		_trajectory = trajectory;
	}

	void CentipedeSegment::SetTopLeftXPosition(float xpos)
	{
		Entity::SetTopLeftXPosition(xpos);
	}

	void CentipedeSegment::SetTopLeftYPosition(float ypos)
	{
		Entity::SetTopLeftYPosition(ypos);
	}

	void CentipedeSegment::SetTurningLeft(bool isTurningLeft)
	{
		_turningLeft = isTurningLeft;
	}

	void CentipedeSegment::SetRegion(Region region)
	{
		Entity::SetRegion(region);
	}

	void CentipedeSegment::SetSubRegion(Region subregion)
	{
		Entity::SetSubRegion(subregion);
	}

	bool CentipedeSegment::IsFirstSegment()
	{
		return _firstSegment;
	}

	bool CentipedeSegment::IsTurningLeft()
	{
		return _turningLeft;
	}

	Trajectory CentipedeSegment::GetTrajectory()
	{
		return _trajectory;
	}

	float CentipedeSegment::GetCenterXPosition()
	{
		return Entity::GetTopLeftXPosition() + CENTIPEDE_SPRITE_SIDE_SIZE/2;
	}

	float CentipedeSegment::GetCenterYPosition()
	{
		return Entity::GetTopLeftYPosition() + CENTIPEDE_SPRITE_SIDE_SIZE/2;
	}
}