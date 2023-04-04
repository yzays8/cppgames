// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#include "AnimSpriteComponent.h"
#include "Math.h"

AnimSpriteComponent::AnimSpriteComponent(Actor* owner, int drawOrder)
	:SpriteComponent(owner, drawOrder)
	, mCurrFrame(0.0f)
	, mAnimFPS(24.0f)
	, mAnimIndex(kHumanAnimeIndex)
	, mAnimIsLoop(false)
{
}

void AnimSpriteComponent::Update(float deltaTime)
{
	SpriteComponent::Update(deltaTime);

	if (mAnimTextures.size() > 0)
	{
		// Update the current frame based on frame rate
		// and delta time
		mCurrFrame += mAnimFPS * deltaTime;
		
		// Wrap current frame if needed
		if (mCurrFrame + mAnimIndex.start >= mAnimIndex.end) {
			if (mAnimIsLoop) {
				while (mCurrFrame + mAnimIndex.start >= mAnimIndex.end) {
					mCurrFrame -= (mAnimIndex.end - mAnimIndex.start + 1);
				}
			} else {
				mCurrFrame = mAnimIndex.end - mAnimIndex.start;
			}
		}

		// Set the current texture
		SetTexture(mAnimTextures[static_cast<int>(mCurrFrame) + mAnimIndex.start]);
	}
}

void AnimSpriteComponent::SetAnimTextures(const std::vector<SDL_Texture*>& textures)
{
	mAnimTextures = textures;
	if (mAnimTextures.size() > 0)
	{
		// Set the active texture to first frame
		mCurrFrame = 0.0f;
		SetTexture(mAnimTextures[0]);
	}
}
