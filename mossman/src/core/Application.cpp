/*
 * Application.cpp
 *
 *  Created on: Nov 3, 2014
 *      Author: ville
 */

#include "Application.h"

#include <memory>

#include "scenes/julia/JuliaSceneSFMLRenderer.h"
#include "scenes/JuliaScene.h"

namespace mossman {

Application::Application() : mWindow(nullptr), mQuitSignaled(false), mFpsCounter(100) {
	// TODO Auto-generated constructor stub

}

Application::~Application() {
	// TODO Auto-generated destructor stub
}

void Application::init() {
	using namespace mossman::scenes;
	mWindow = std::make_shared<sf::RenderWindow>(sf::VideoMode(1280, 1024), "mossman");
	mWindow->setVerticalSyncEnabled(true);

	JuliaScene* juliaScene = new JuliaScene();

	julia::JuliaSceneSFMLRenderer* juliaSceneRenderer = new julia::JuliaSceneSFMLRenderer(mWindow, juliaScene);

	mSceneManager.addScene(juliaScene, juliaSceneRenderer);

	mDefaultFont.loadFromFile("res/fonts/Anonymous.ttf");
	mFpsText.setFont(mDefaultFont);
}

void Application::update(double dt) {
	sf::Event event;
	while (mWindow->pollEvent(event))
	{
		if (event.type == sf::Event::Closed) {
			mQuitSignaled = true;
			return;
		}
	}

	mSceneManager.updateActiveScene(dt);
}

void Application::render() {
	mWindow->clear();
	mSceneManager.renderActiveScene();
	mWindow->pushGLStates();
	float currentTime = mFpsClock.restart().asSeconds();
	mFpsCounter.pushFrameTime(currentTime);
	mFpsText.setString(std::to_string(mFpsCounter.calcFps()));
	mWindow->draw(mFpsText);
	mWindow->popGLStates();
	mWindow->display();
}

void Application::activateRenderContext() {
	mWindow->setActive(true);
}

void Application::deactivateRenderContext() {
	mWindow->setActive(false);
}

void Application::quit() {
	mWindow->close();
}

bool Application::isRunning() const {
	return !mQuitSignaled;
}

std::shared_ptr<sf::RenderWindow> Application::getRenderContext() const {
	return mWindow;
}

} /* namespace mossman */
