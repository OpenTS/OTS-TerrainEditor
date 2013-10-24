#pragma once
#include "base.h"

namespace OTS
{
	class ColorValue
	{
	public:
		static const ColorValue WHITE;
		static const ColorValue BLACK;
		static const ColorValue RED;
		static const ColorValue GREEN;
		static const ColorValue BLUE;

		ColorValue();
		ColorValue(FLOAT red, FLOAT green, FLOAT blue, FLOAT alpha);
		~ColorValue(void);

		FLOAT r,g,b,a;
	};
}


