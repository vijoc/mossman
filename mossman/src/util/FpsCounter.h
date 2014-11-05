/*
 * FpsCounter.h
 *
 *  Created on: Nov 5, 2014
 *      Author: ville
 */

#ifndef UTIL_FPSCOUNTER_H_
#define UTIL_FPSCOUNTER_H_

namespace mossman {

/*
 * Utility class for calculating the FPS using a simple moving average.
 */
class FpsCounter {
public:
	FpsCounter(int sampleCount);
	virtual ~FpsCounter();

	/*
	 * Push a new time elapsed between frames.
	 */
	void pushFrameTime(float time);

	/*
	 * Calculate and return the current average FPS.
	 */
	float calcFps();

private:
	int mSampleCount;
	float* mSamples;
	float mSum;
	int mSampleIndex;
};

} /* namespace mossman */

#endif /* UTIL_FPSCOUNTER_H_ */
