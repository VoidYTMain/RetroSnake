#ifndef GAME_CTRL_HPP
#define GAME_CTRL_HPP

#include "GameModel.hpp"
#include "GameTimer.hpp"

#include <string>
#include <math.h>

using std::string;

constexpr auto SPEED_DELTA = 100;
constexpr auto ACCELERATING_FACTOR = 0.995;

class DirectionCtrl
{
protected:
	E_Direction m_direction;
public:
	virtual void Process() = NULL;
	virtual bool IsAlive() const = NULL;
	virtual ~DirectionCtrl() {}
};

class PlayerCtrl : public virtual DirectionCtrl
{
	int m_kUp, m_kLeft, m_kDown, m_kRight;
	int m_speedLevel, m_score;
	string m_name;
	Map &m_map;
	bool &m_isUpdateUI;
	Snake m_snake;
	bool m_alive = true;
	PlayerCtrl *m_enemy = nullptr;
	void HandleFood(const Point& position);
	void HandleTerrain(const Point& position);
	TimerManager::handler &m_timer;

	class TickTock : public TimerManager::handler
	{
		PlayerCtrl &m_player;
	public:
		TickTock(clock_t tickTime, bool isLoop, PlayerCtrl &player) : TimerManager::handler(tickTime, isLoop), m_player(player) { }
		void Invoke() { m_player.Process(); }
	};
public:
	PlayerCtrl(string name, Map &map, bool &isUpdateUI, Color color, int kUp, int kLeft, int kDown, int kRight);
	~PlayerCtrl();

	void Reset(Point position);

	void UpdateDirection();
	bool MoveByPosition();
	bool MoveByPosition(const Point &position);
	void Process() override;

	int get_Speed() const { return int(SPEED_DELTA / pow(ACCELERATING_FACTOR, m_speedLevel)); }

	void IncreaseScore() { ++m_score; }
	int get_Score() const { return m_score; }

	Color get_Color() const { return m_snake.get_color(); }
	string get_Name() const { return m_name; }

	bool get_Alive() const { return m_alive; }
	void set_Alive(bool alive) { m_alive = alive; }
	bool IsAlive() const { return m_alive; }

	void SetEnemy(PlayerCtrl &enemy) { m_enemy = &enemy; }
};

#endif