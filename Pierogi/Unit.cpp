#include "pch.h"
#include "Unit.h"

namespace pr {
	Unit::Unit(const std::string& image, int x, int y): mImage(image), mXPos(x), mYPos(y)
	{
	}
	Unit::Unit(std::string&& image, int x, int y) : mImage(image), mXPos(x), mYPos(y)
	{
	}
	int Unit::GetWidth() const
	{
		return mImage.getWidth();
	}
	int Unit::GetHeight() const
	{
		return mImage.getHeight();
	}
	int Unit::GetXCoor() const
	{
		return mXPos;
	}
	int Unit::GetYCoor() const
	{
		return mYPos;
	}
	void Unit::SetCoor(int nX, int nY)
	{
		mXPos = nX;
		mYPos = nY;
	}
	void Unit::UpdateXCoor(int amount)
	{
		mXPos += amount;
	}
	void Unit::UpdateYCoor(int amount)
	{
		mYPos += amount;
	}
	void Unit::PicBind()
	{
		mImage.Bind();
	}
	bool UnitsOverlap(const Unit& a, const Unit& b)
	{
		int left_a{ a.mXPos };
		int right_a{ a.mXPos + a.GetWidth() };
		int left_b{ b.mXPos };
		int right_b{ b.mXPos + b.GetWidth() };

		bool x_intersect{ (left_a <= left_b and left_b <= right_a) or (left_b <= left_a and left_a <= right_b) };

		int bot_a{ a.mYPos };
		int top_a{ a.mYPos + a.GetHeight() };
		int bot_b{ b.mYPos };
		int top_b{ b.mYPos + b.GetHeight() };

		bool y_intersect{ (bot_a <= bot_b and bot_b <= top_a) or (bot_b <= bot_a and bot_a <= top_b) };

		return x_intersect and y_intersect;
	}
}