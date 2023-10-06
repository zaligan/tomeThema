# pragma once
# include <Siv3D.hpp>
#include"kait_siv3D.hpp"

bool RectButton(const Rect& rect, const Font& font, const String& text, bool enabled)
{
	if (enabled && rect.mouseOver())
	{
		Cursor::RequestStyle(CursorStyle::Hand);
	}
	if (enabled)
	{
		rect.draw(ColorF{ 0.3, 0.7, 1.0 });
		font(text).drawAt(40, (rect.x + rect.w / 2), (rect.y + rect.h / 2));
	}
	else
	{
		rect.draw(ColorF{ 0.5 });
		font(text).drawAt(40, (rect.x + rect.w / 2), (rect.y + rect.h / 2), ColorF{ 0.7 });
	}
	return (enabled && rect.leftClicked());
}

bool CircleButton(const Circle& circle, bool enabled)
{
	if (enabled && circle.mouseOver())
	{
		Cursor::RequestStyle(CursorStyle::Hand);
	}
	if (enabled)
	{
		circle.draw(ColorF{ 0.3, 0.7, 1.0 });
	}
	else
	{
		circle.draw(ColorF{ 0.5 });
	}
	return (enabled && circle.leftClicked());
}

// doubleのstartからendまで座標を加算
void MyTexture::move(double start_x, double start_y, double end_x, double end_y, double speed) {
	Vec2 start(start_x, start_y);
	Vec2 end(end_x, end_y);
	position += (end - start).normalized() * speed;
}

void MyTexture::move(Vec2 start, Vec2 end, double speed)
{
	position += (end - start).normalized() * speed;
}

Vec2 MyTexture::getPos()
{
	return position;
}



hito::hito()
{
	this->age = 100;
}

hito::hito(int age)
{
	this->age = age;
}
void hito::show_age()
{
	Print << U"{}"_fmt(this->age);
}

void hito::show_sinchou()
{
	Print << U"sinchou";
}
void hito::show_taiju()
{
	Print << U"taiju";
}
void hito::set_age(int age)
{
	this->age = age;
}
