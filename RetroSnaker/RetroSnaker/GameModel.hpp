#pragma once
#include "GameLib.hpp"

enum class E_MapItem
{
	None = 0,
	Wall = 1,
	Food = 2,
	Head = 3,
	Body = 4,
};
struct Point
{
	int x, y;
};
struct Color
{
	/* 0-��ɫ, 1-��ɫ,   2-��ɫ,      3-ǳ��ɫ,     4-��ɫ,   5-��ɫ,   6-��ɫ,   7-��ɫ,
	 * 8-��ɫ, 9-����ɫ, 10-����ɫ,   11-��ǳ��ɫ   12-����ɫ 13-����ɫ 14-����ɫ 15-����ɫ*/
	int fore, back;
};

template <int Width, int Height>
class MapTemplate
{
	E_MapItem m_items[Width][Height];
	Color m_colors[Width][Height];
public:
	static const Color DefaultColor;
	MapTemplate()
	{
		for (int ci = 0; ci < Width; ++ci)
			for (int ri = 0; ri < Height; ++ri)
				m_colors[ci][ri] = DefaultColor;
	}
	//const E_MapItem * operator[](int x) const { return m_items[x]; }
	//E_MapItem * operator[](int x) { return m_items[x]; }
	const E_MapItem& operator[](Point position) const { return m_items[position.x][position.y]; }
	E_MapItem& operator[](Point position) { return m_items[position.x][position.y]; }
	const E_MapItem& Index(int x, int y) const { return m_items[x][y]; }
	E_MapItem& Index(int x, int y) { return m_items[x][y]; }

	const Color& ColorIndex(Point position) const { return m_colors[position.x][position.y]; }
	Color& ColorIndex(Point position) { return m_colors[position.x][position.y]; }
	const Color &ColorIndex(int x, int y) const { return m_colors[x][y]; }
	Color &ColorIndex(int x, int y) { return m_colors[x][y]; }
};
typedef MapTemplate<GAME_WIDTH, GAME_HEIGHT> Map;

enum class E_Direction
{
	None,
	Left,
	Right,
	Up,
	Down,
};

enum class E_MoveState
{
	Done,
	Eat,
	Over,
};

class Snake
{
	class SnakePart
	{
		Point m_position;
		SnakePart *m_last, *m_next;
	public:
		SnakePart(Point position) : m_position(position), m_last(nullptr), m_next(nullptr) { }
		friend class Snake;
	};
	SnakePart *m_head;
	E_Direction m_direction;
	Color m_color;
public:
	Snake(Point position, Color color) : m_head(new SnakePart(position)), m_color(color) { }
	Snake(Snake &&snake)
	{
		if (this == &snake) return;
		this->m_head = snake.m_head;
		snake.m_head = nullptr;
		this->m_direction = snake.m_direction;
		this->m_color = snake.m_color;
	}
	~Snake()
	{
		while (nullptr != m_head)
		{
			auto tmp = m_head;
			m_head = m_head->m_last;
			delete tmp;
		}
	}
	E_Direction get_direction() const { return m_direction; }
	void set_direction(E_Direction direction) { m_direction = direction; }
	E_MoveState MoveByDirection(Map &m_map);
};