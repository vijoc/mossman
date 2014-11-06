/*
 * JuliaScene.cpp
 *
 *  Created on: Nov 3, 2014
 *      Author: ville
 */

#include "JuliaScene.h"
#include <iostream>
#include <mutex>

namespace mossman {
namespace scenes {

JuliaScene::JuliaScene() : mC(0.5, 0.5), mAngularVelocity(0.8) {


}

JuliaScene::~JuliaScene() {
	// TODO Auto-generated destructor stub
}

void JuliaScene::update(double dt) {
	float phase = std::arg(mC) + mAngularVelocity * dt;
	float magnitude = std::abs(mC);

	{
		std::lock_guard<std::mutex> lock(mCMutex);
		mC = std::polar(magnitude, phase);
	}
}

void JuliaScene::activated() {

}

void JuliaScene::deactivated() {

}

std::complex<float> JuliaScene::getC() const {
	std::lock_guard<std::mutex> lock(mCMutex);
	return mC;
}

} /* namespace scenes */
} /* namespace mossman */
