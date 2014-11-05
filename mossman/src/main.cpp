/*
 * main.cpp
 *
 *  Created on: Nov 3, 2014
 *      Author: ville
 */

#include <chrono>
#include <thread>
#include "core/Application.h"
#include <X11/Xlib.h>

using namespace mossman;

void render(Application* app) {
	app->activateRenderContext();
	while(app->isRunning()) {
		app->render();
	}
}

int main()
{
	XInitThreads(); // http://stackoverflow.com/q/20979886
	using namespace std::chrono;

	mossman::Application app;
	app.init();

	app.deactivateRenderContext();

	std::thread tRender(render, &app);

	auto currentTime = high_resolution_clock::now();

	while(app.isRunning()) {
		auto newTime = high_resolution_clock::now();
		double dt = duration_cast<duration<double>>(currentTime - newTime).count();
		app.update(dt);
		currentTime = newTime;
	}

	tRender.join();
	app.quit();

	return 0;
}
