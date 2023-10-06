# include <Siv3D.hpp>

class Bomb
{
public:
	bool isActive = true;
	Bomb(Vec2 position)
	{
		this->position = position;
		bombColi.setPos(position + bombOffset);
	}
	void fall_y(double deltaTime)
	{
		position.y += deltaTime * bombSpeed;
	}

	Circle getColi()
	{
		bombColi.setPos(position + bombOffset);
		return bombColi;
	}

	Vec2 getPos()
	{
		return position;
	}
	double get_x()
	{
		return position.x;
	}
	double get_y()
	{
		return position.y;
	}

private:
	Vec2 position;
	Circle bombColi{ position,40 };
	const  Vec2 bombOffset{ -9,15 };
	const double bombSpeed = 50.0;
};


void Main()
{
	const Texture hungry{ U"🤤"_emoji };
	const Texture closeMouth{ U"😁"_emoji };
	const Texture openMouth{ U"😄"_emoji };
	const Texture bombTex{ U"💣"_emoji };
	const Texture explosion{ U"💥"_emoji };

	
	

	double deltaTime = 0;
	double deltaDrop = 0;
	bool eatFlag = false;
	bool eatMode = false;
	Circle PlayerColi{ 300,300,50 };
	Vec2 playerPos{ 300,300 };
	const double timeHlz = 0.2;
	const double dropTime = 0.5;

	Array<Bomb> bombs;
	bombs << Bomb{ {300,0} };

	while (System::Update())
	{
		deltaTime += Scene::DeltaTime();
		deltaDrop += Scene::DeltaTime();
		playerPos = { Clamp(Cursor::PosF().x, 0.0, 800.0), Clamp(Cursor::PosF().y, 400.0, 600.0)};
		PlayerColi.setPos(playerPos);

		if (deltaTime > timeHlz)
		{
			deltaTime -= timeHlz;
			eatFlag = 1 - eatFlag;
		}
		if (MouseL.down())
			eatMode = 1 - eatMode;
		if (eatMode)
		{
			if (eatFlag)
				closeMouth.drawAt(playerPos);
			else
				openMouth.drawAt(playerPos);
		}
		else
			hungry.drawAt(playerPos);

		if (deltaDrop > dropTime)
		{
			bombs << Bomb{ {Random<double>(800),100}};
			deltaDrop -= dropTime;
		}

		for (auto& bomb : bombs)
		{
			if (!bomb.isActive)
				continue;
			bomb.fall_y(deltaTime);
			
			if ((Scene::Height() - 20) < bomb.get_y())
			{
				explosion.drawAt(bomb.get_x(), (Scene::Height() - 20));
			}
			else
				bombTex.drawAt(bomb.getPos());
			if (PlayerColi.intersects(bomb.getColi()) && eatMode)
			{
				bomb.isActive = false;
			}
			
			
		}

		Cursor::RequestStyle(CursorStyle::Hidden);
	}
}
