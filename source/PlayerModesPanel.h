/* PlayerModesPanel.h
Copyright (c) 2014 by Michael Zahniser

Endless Sky is free software: you can redistribute it and/or modify it under the
terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or (at your option) any later version.

Endless Sky is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.  See the GNU General Public License for more details.
*/

#ifndef PLAYER_MODES_PANEL_H_
#define PLAYER_MODES_PANEL_H_

#include "Panel.h"

#include "WrappedText.h"

#include <functional>
#include <memory>

class Interface;
class Planet;
class PlayerInfo;
class System;



// Dialog that pops up when you land on a planet. The shipyard and outfitter are
// shown in full-screen panels that pop up above this one, but the remaining views
// (trading, jobs, bank, port, and crew) are displayed within this dialog.
class PlayerModesPanel : public Panel {
public:
	PlayerModesPanel(PlayerInfo &player, std::function<void()> callback);
	
	virtual void Step() override;
	virtual void Draw() const override;
	
	
protected:
	// Only override the ones you need; the default action is to return false.
	virtual bool KeyDown(SDL_Keycode key, Uint16 mod, const Command &command) override;
	virtual bool Click(int x, int y) override;
	
	
private:
	void TakeOff();
	
	
private:
	PlayerInfo &player;
	std::function<void()> callback = nullptr;
	
	const Planet &planet;
	const System &system;
	const Interface &ui;
	
	std::shared_ptr<Panel> trading;
	std::shared_ptr<Panel> bank;
	std::shared_ptr<Panel> spaceport;
	std::shared_ptr<Panel> hiring;
	Panel *selectedPanel = nullptr;
	bool isDeparting = false;
	
	WrappedText text;
};



#endif
