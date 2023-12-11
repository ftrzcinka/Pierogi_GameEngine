#pragma once

#include "Utilities.h"
#include "Picture.h"

namespace pr {
	class PIEROGI_API Unit {
	public:
		Unit(const std::string& image, int x, int y);
		Unit(std::string&& image, int x, int y);

		int GetWidth() const;
		int GetHeight() const;

		int GetXCoor() const;
		int GetYCoor() const;
		void SetCoor(int nX, int nY);
		void UpdateXCoor(int amount);
		void UpdateYCoor(int amount);

		void PicBind();

	private:
		Picture mImage;
		int mXPos;
		int mYPos;

		template<typename T> friend class PierogiApp;
		friend PIEROGI_API bool UnitsOverlap(const Unit& a, const Unit& b);
	};

	PIEROGI_API bool UnitsOverlap(const Unit& a, const Unit& b);
}