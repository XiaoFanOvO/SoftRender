#include "gpu.h"

GPU* GPU::mInstance = nullptr;
GPU* GPU::getInstance() {
	if (!mInstance) {
		mInstance = new GPU();
	}

	return mInstance;
}

GPU::GPU() {}

GPU::~GPU() {
	if (mFrameBuffer) {
		delete mFrameBuffer;
	}
}

void GPU::initSurface(const uint32_t& width, const uint32_t& height, void* buffer) {
	mFrameBuffer = new FrameBuffer(width, height, buffer);
}

void GPU::clear() {
	size_t pixelSize = mFrameBuffer->mWidth * mFrameBuffer->mHeight; // 总共的像素数
	std::fill_n(mFrameBuffer->mColorBuffer, pixelSize, RGBA(0, 0, 0, 0)); 
}

void GPU::drawPoint(const uint32_t& x, const uint32_t& y, const RGBA& color) {
	//从窗口左下角开始算起
	uint32_t pixelPos = y * mFrameBuffer->mWidth + x; // 在最后一行加上x的偏移量
	mFrameBuffer->mColorBuffer[pixelPos] = color;
}


