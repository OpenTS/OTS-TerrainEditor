#include "ColorValue.h"

namespace OTS
{
	const ColorValue ColorValue::BLACK = ColorValue(0.0, 0.0, 0.0, 0.0);
	const ColorValue ColorValue::WHITE = ColorValue(1.0, 1.0, 1.0, 1.0);
	const ColorValue ColorValue::RED = ColorValue(1.0, 0.0, 0.0, 1.0);
	const ColorValue ColorValue::GREEN = ColorValue(0.0, 1.0, 0.0, 1.0);
	const ColorValue ColorValue::BLUE = ColorValue(0.0, 0.0, 1.0, 1.0);

	ColorValue::ColorValue() : r(1.0), g(1.0), b(1.0), a(1.0)
	{

	}

	ColorValue::ColorValue(FLOAT red = 1.0f, FLOAT green = 1.0f, 
						  FLOAT blue = 1.0f, FLOAT alpha = 1.0) : r(red), g(green), 
																  b(blue), a(alpha)
	{

	}


	ColorValue::~ColorValue(void)
	{
	}
}