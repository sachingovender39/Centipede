#include "Entity.h"

namespace GameEngine
{
	Entity::Entity(Direction direction, float topLeftXPosition,
				float topLeftYPosition):
	_direction(direction),
	_topLeftXPosition(topLeftXPosition),
	_topLeftYPosition(topLeftYPosition),
	_isDead(false)
	{
		
	}

	void Entity::SetTopLeftXPosition(float xpos)
	{
		_topLeftXPosition = xpos;
	}

	void Entity::SetTopLeftYPosition(float ypos)
	{
		_topLeftYPosition = ypos;
	}

	void Entity::SetRegion(Region region)
	{
		_region = region;
	}

	void Entity::SetSubRegion(Region subregion)
	{
		_subregion = subregion;
	}

	void Entity::SetDead(bool isDead)
	{
		_isDead = isDead;
	}

	bool Entity::IsDead() const
	{
		return _isDead;
	}

	Direction Entity::GetDirection() const
	{
		return _direction;
	}

	Region Entity::GetRegion() const
	{
		return _region;
	}

	Region Entity::GetSubRegion() const
	{
		return _subregion;
	}

	float Entity::GetTopLeftXPosition() const
	{
		return _topLeftXPosition;
	}

	float Entity::GetTopLeftYPosition() const
	{
		return _topLeftYPosition;
	}
}