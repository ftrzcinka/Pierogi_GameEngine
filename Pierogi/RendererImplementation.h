#pragma once

#include "Picture.h"
#include "Unit.h"

namespace pr {
	class RendererImplementation {
	public:
		virtual void Init() = 0;
		virtual void Draw(int x, int y, Picture& picture) = 0;
		virtual void Draw(Unit& unit) = 0;
		virtual void Clear() = 0;
		virtual ~RendererImplementation() {};
	};
}