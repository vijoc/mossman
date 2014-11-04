/*
 * main.cpp
 *
 *  Created on: Nov 3, 2014
 *      Author: ville
 */

#include <chrono>
#include "Application.h"

int main()
{
	using namespace std::chrono;

	Mossman::Application app;
	app.init();

	auto currentTime = high_resolution_clock::now();

	while(app.isRunning()) {
		auto newTime = high_resolution_clock::now();
		double dt = duration_cast<duration<double>>(currentTime - newTime).count();
		app.update(dt);
		currentTime = newTime;
	}

	return 0;
}
