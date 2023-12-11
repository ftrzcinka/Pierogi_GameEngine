#pragma once

#include "RendererImplementation.h"

namespace pr {
	class OpenGLRenderer : public RendererImplementation {
	public:
		virtual void Init() override;
		virtual void Draw(int x, int y, Picture& picture) override;
		virtual void Draw(Unit& unit) override;
		virtual void Clear() override;
	};
}