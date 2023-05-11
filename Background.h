#pragma once
#include "Object.h"

class Background : public Object
{
public:
    bool Pipe_Above1Update(int incY, int& points);
	bool Pipe_Below1Update(int incY);
	bool Pipe_Above2Update(int incY, int& points);
	bool Pipe_Below2Update(int incY);
	bool Pipe_Above3Update(int incY, int& points);
	bool Pipe_Below3Update(int incY);

	void Reset();

    void Render(SDL_Renderer* ren);
	void PipeRender(SDL_Renderer* ren);

private:
	int pipeDistance1 = 400;
	int pipeDistance2 = 650;
	int pipeDistance3 = 950;

	int incY1 = 0;
	int incY2 = 0;
	int incY3 = 0;

};


