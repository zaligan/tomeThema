# pragma once

bool RectButton(const Rect& rect, const Font& font, const String& text, bool enabled);
bool CircleButton(const Circle& circle, bool enabled);

class hito
{
public:
	
	int sinchou;
	int taiju;
	hito();
	hito(int age);
	void show_age();
	void show_sinchou();
	void show_taiju();
	void set_age(int age);
private:
	int age;
};

class MyTexture : public Texture
{
public:
	// int16_t 型の引数を受け取るメソッド
	void move(double start_x, double start_y, double end_x, double end_y, double speed);
	void move(Vec2 start,Vec2 end, double speed);
	Vec2 getPos();
private:
	Vec2 position = { 0,0 };
};




class ore :public hito
{
public:
	
};
