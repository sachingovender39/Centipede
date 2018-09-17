#include "SpiderRendering.h"

namespace GameEngine
{
	SpiderRendering::SpiderRendering(DataPtr data, FieldPtr field):
	_data(data),
	_field(field)
	{
		
	}

	void SpiderRendering::Draw()
	{
		if (!_field->GetSpiders().empty())
		{
			for (unsigned int i = 0; i < _field->GetSpiders().size(); i++)
			{
				_data->window.draw(_field->GetSpiders().at(i).GetObjectSprite());
			}
		}
	}
}