#pragma once
#include "TextureManager.h"

bool TextureManager::loadTexture(const char* fileName, std::string id, SDL_Renderer* renderer)
{
	SDL_Surface* tempSurface = IMG_Load(fileName);

	if (tempSurface == 0) {
		return false;
	}

	SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
	SDL_FreeSurface(tempSurface);

	if (tex != 0) {
		textureMap[id] = tex;
		return true;
	}

	return false;
	
}

void TextureManager::drawTexture(std::string id, int x, int y, int width, int height, SDL_Renderer* renderer, SDL_RendererFlip flip )
{
	
	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = srcRect.y = 0;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = y;
	destRect.y = x;

	SDL_RenderCopyEx(renderer, this->textureMap[id], &srcRect, &destRect, 0, 0, flip);

	SDL_QueryTexture(this->textureMap[id], NULL, NULL, &srcRect.w, &srcRect.h);
	
}

//void TextureManager::drawOneFrameFromTexture(std::string id, // id of texture to draw
//	int x, int y, // window x and y
//	int width, int height, // width and height of texture
//	int currentRow, int currentFrame, // row starts from 1
//	SDL_Renderer* renderer, SDL_RendererFlip flip )
//{
//	SDL_Rect srcRect;
//	SDL_Rect destRect;
//	srcRect.x = width * currentFrame;
//	srcRect.y = height * (currentRow - 1);
//	srcRect.w = destRect.w = width;
//	srcRect.h = destRect.h = height;
//	destRect.x = x + TextureManager::x;
//	destRect.y = y + TextureManager::y;
//
//	SDL_RenderCopyEx(renderer, this->textureMap[id], &srcRect, &destRect, 0, 0, flip);
//	//SDL_RenderCopyEx(renderer,this->textureMap[id], &srcRect, &destRect,0,0, SDL_FLIP_HORIZONTAL);
//}



TextureManager* TextureManager::instance = 0;