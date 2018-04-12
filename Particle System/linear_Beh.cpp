#include "linear_Beh.h"

float Linear_Beh::action_at_time(float start_x, float dt, float lifetime,float final)
{
	result = start_x + (dt / lifetime)*final;
	return result;
}