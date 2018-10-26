#define _USE_MATH_DEFINES

#include "Particle.h"
#include <math.h>

Particle::Particle(): m_x(0), m_y(0)
{
	init();
}

void Particle::init()
{
	m_x = 0;
	m_y = 0;

	m_direction = (2 * M_PI * rand()) / RAND_MAX;
	m_speed = (0.04 * rand()) / RAND_MAX;

	m_speed *= m_speed;
}

Particle::~Particle()
{
}


void Particle::update(int interval)
{
	m_direction += interval*0.0004;

	double xSpeed = m_speed * cos(m_direction);
	double ySpeed = m_speed * sin(m_direction);

	m_x += xSpeed * interval;
	m_y += ySpeed * interval;

	if (m_x < -1 || m_x > 1 || m_y < -1 || m_y > 1)
		init();

	if (rand() < RAND_MAX / 100)
		init();
}
