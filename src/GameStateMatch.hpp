#ifndef GAMESTATE_MATCH_HPP
#define GAMESTATE_MATCH_HPP
#include "GameState.hpp"
#include <string>
#include <sstream>
#include <iomanip>
#include "LTexture.hpp"

class GameStateMatch : public GameState {
private:

	virtual void sync();
	virtual void handle();
	virtual void update(const float& delta);
	virtual void render();
	
public:

	virtual bool load();
	virtual void loop();
	
	GameStateMatch(Game* g) : GameState(g) {};
	virtual ~GameStateMatch();
	
	std::stringstream frameTimeText;
	TTF_Font* frameFont = NULL;
	LTexture frameFPSTextTexture;
	
};

#endif