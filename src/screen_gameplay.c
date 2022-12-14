#include "common.h"
#include "screens.h"
#include "state.h"

#define DASH_SCORE 5

static void init()
{
	/// state init
	g.estars_count = 3; /// must be less than MAX_ESTAR
	g.mndistance = 150;
	g.score = 0;
	g.out = false;
	g.delta = 0;

	g.reduce_time = 0.0f;
	g.reduce_duration = 2.2f;

}

void init_gameplay_screen(void)
{
	init();

    /// Player
    player_init();

	/// Stars
	stars_init();

	/// Estars
	estars_init();
}

static bool check_collision(Vector2 apos, float aradius, Vector2 bpos, float bradius)
{
	float sum = aradius+bradius;
	if (Vector2DistanceSqr(apos, bpos) <= (sum)*(sum)) return true;
	return false;
}

static void update(void)
{
	/// player and estar collision
	for (int i = 0; i < g.estars_count; ++i) {
		if (g.estars[i].active) {
			if (check_collision(g.player.position, g.player.radius, g.estars[i].position, g.estars[i].radius)) {
				if (g.player.dashing) {
					g.score += DASH_SCORE;
					//make_particle(g.estars[i].position);
					estar_init(&g.estars[i]);
					PlaySound(star_destroy);
				} else {
					PlaySound(player_destroy);
					g.out = true;
				}
			}
		}
	}

	/// reduce distance between starange star and playe

	if (g.mndistance > 100 && g.reduce_time <= g.delta) {
		g.mndistance -= 10;
		g.reduce_time += g.reduce_duration;
	}
}

void update_gameplay_screen(void)
{
	/// Delta Time
	g.delta	= GetFrameTime();	

    /// Player
    player_update();

	/// Stars
	stars_update();

	/// Estars
	estars_update();

	update();
}

void draw_gameplay_screen(void)
{
	/// Stars
	stars_draw();

    /// Player
    player_draw();

	/// Estars
	estars_draw();
}

void unload_gameplay_screen(void)
{
	///
}

int finish_gameplay_screen(void)
{
	return g.out;
}

