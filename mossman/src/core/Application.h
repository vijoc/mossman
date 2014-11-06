/*
 * Application.h
 *
 *  Created on: Nov 3, 2014
 *      Author: ville
 */

#ifndef MOSSMAN_SRC_APPLICATION_H_
#define MOSSMAN_SRC_APPLICATION_H_

#include <SFML/Graphics.hpp>
#include <memory>

#include "SceneManager.h"
#include "util/FpsCounter.h"

namespace mossman {

class Application {
public:
	Application();
	virtual ~Application();

	/**
	 * Initialize the application, creating the window etc.
	 */
	void init();

	/**
	 * Update the application by dt seconds.
	 */
	void update(double dt);

	void render();

	void quit();

	void deactivateRenderContext();

	void activateRenderContext();

	bool isRunning() const;

private:
	std::unique_ptr<sf::RenderWindow> mWindow;
	SceneManager mSceneManager;
	bool mQuitSignaled;
	sf::Font mDefaultFont;
	sf::Text mFpsText;
	sf::Clock mFpsClock;
	FpsCounter mFpsCounter;
};

} /* namespace mossman */

#endif /* MOSSMAN_SRC_APPLICATION_H_ */
