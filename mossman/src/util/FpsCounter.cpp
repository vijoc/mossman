/*
 * FpsCounter.cpp
 *
 *  Created on: Nov 5, 2014
 *      Author: ville
 */

#include "FpsCounter.h"

namespace mossman {

FpsCounter::FpsCounter(int sampleCount) : mSampleCount(sampleCount), mSum(0), mSampleIndex(0) {
	mSamples = new float[sampleCount];
	for(int i = 0; i < sampleCount; i++) {
		mSamples[i] = 0.f;
	}
}

FpsCounter::~FpsCounter() {
	delete[] mSamples;
}

void FpsCounter::pushFrameTime(float time) {
	mSum -= mSamples[mSampleIndex];
	mSum += time;
	mSamples[mSampleIndex] = time;
	if(++mSampleIndex == mSampleCount) mSampleIndex = 0;
}

float FpsCounter::calcFps() {
	return 1.f / (mSum/mSampleCount);
}

} /* namespace mossman */
