#pragma once

#include "pch.h"
#include "Utilities.h"
#include "RendererImplementation.h"
#include "Shader.h"
#include "Picture.h"
#include "Unit.h"

namespace pr {
	class PIEROGI_API Renderer {
	public:
		Renderer();

		void Init();

		void Draw(int x, int y, Picture& picture);
		void Draw(Unit& unit);

		void Clear();
	private:
		std::unique_ptr<RendererImplementation> mImplementation;
	};
}