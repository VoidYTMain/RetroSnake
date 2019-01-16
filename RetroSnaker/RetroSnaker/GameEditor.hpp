#ifndef GAME_EDITOR_HPP
#define GAME_EDITOR_HPP

#include <map>
#include <vector>

enum class E_StaticCellType
{
	OpenSpace,
	JebelLand,
	GrassLand,
	MagmaLand,
	FrostLand,

	GermPoint,
	JumpPoint,
};

enum class E_ActiveCellType
{
	SnakeFood,
	SnakeHead,
	SnakeBody,
};

enum class E_FoodType
{
	/*������Ч��*/ NormalEffect	,
	/*ʹ�Է��䳤*/ AppendLength	,
	/*ʹ�Լ����*/ RemoveLength	,
	/*ʹ�Լ�����*/ Acceleration	,
	/*ʹ�Է�����*/ Deceleration	,
	/*ʹ�Է���ת*/ Reverse		,
	/*�Լ������*/ BuffStrong	,
	/*�Է���ʧ��*/ BuffControl	,
	/*�Լ�������*/ BuffGhost		,
};

struct Point
{
public:
	int x, y;
	bool operator==(const Point &rhs) const { return x == rhs.x && y == rhs.y; }
	bool operator!=(const Point &rhs) const { return x != rhs.x || y != rhs.y; }
	void Set(const Point& point) { x = point.x; y = point.y; }
};

struct CellModel
{
	E_StaticCellType type;
	int id = 0;
	CellModel& operator=(E_StaticCellType type) { this->type = type; return *this; }
};

class GameMapModel
{
private:
	size_t m_width, m_height;
	CellModel *m_cellModels;
	std::map<E_FoodType, size_t> m_foodWeights;
	size_t m_foodCount = 1;
public:
	GameMapModel(size_t width, size_t height) : m_width(width), m_height(height), m_cellModels(new CellModel[width*height])
	{
		m_foodWeights[E_FoodType::NormalEffect] = 20;
		m_foodWeights[E_FoodType::AppendLength] = 10;
		m_foodWeights[E_FoodType::RemoveLength] = 10;
		m_foodWeights[E_FoodType::Acceleration] = 10;
		m_foodWeights[E_FoodType::Deceleration] = 10;
		m_foodWeights[E_FoodType::Reverse] = 10;
		m_foodWeights[E_FoodType::BuffStrong] = 10;
		m_foodWeights[E_FoodType::BuffControl] = 10;
		m_foodWeights[E_FoodType::BuffGhost] = 10;
	}
	~GameMapModel() { delete[] m_cellModels; }
	//const CellModel& get_Index(size_t x, size_t y) const { return m_cellModels[x + y * m_width]; }
	//void set_Index(size_t x, size_t y, const CellModel &cell) { m_cellModels[x + y * m_width] = cell; }
	CellModel& Index(int x, int y) { return m_cellModels[x + y * m_width]; }
	const CellModel& Index(int x, int y) const { return m_cellModels[x + y * m_width]; }

	void SetHollowLand(size_t startPosX, size_t width, size_t startPosY, size_t height, E_StaticCellType staticType)
	{
		size_t endPosX = startPosX + width - 1, endPosY = startPosY + height - 1;
		for (size_t y = startPosY; y <= endPosY; ++y)
			for (size_t x = startPosX; x <= endPosX; ++x)
				if (x == startPosX || x == endPosX || y == startPosY || y == endPosY)
					m_cellModels[x + y * m_width] = staticType;
				else
					m_cellModels[x + y * m_width] = E_StaticCellType::OpenSpace;
	}

	void SetCloseyLand(size_t startPosX, size_t width, size_t startPosY, size_t height, E_StaticCellType staticType)
	{
		size_t endPosX = startPosX + width - 1, endPosY = startPosY + height - 1;
		for (size_t y = startPosY; y <= endPosY; ++y)
			for (size_t x = startPosX; x <= endPosX; ++x)
				m_cellModels[x + y * m_width] = staticType;
	}

	void SetCross(size_t x, size_t y)
	{
		Index(x - 1, y) = Index(x, y) = Index(x + 1, y)
			= Index(x, y - 1) = Index(x, y + 1) = E_StaticCellType::JebelLand;
	}

	size_t& FoodWeight(E_FoodType type) {  }
	size_t get_FoodCount() const { return m_foodCount; }
	void set_FoodCount(size_t foodCount) { m_foodCount = foodCount; }
};

#endif