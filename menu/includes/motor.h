/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** run
*/

#ifndef MAP_H_
    #define MAP_H_

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <time.h>
    #include <unistd.h>
    #include <math.h>
    #include <stddef.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <stdbool.h>
    #define HEIGHT 1080
    #define WIDTH 1920
    #include "../includes/menu.h"
    #include "procedural.h"
    #define LEN_MAP 219
    #define NB_MAPS 18

typedef struct {
    unsigned long timer_total;
    unsigned long timer;
}timer;

typedef struct boss_spawning_s {
    char *file_spawn;
    int delay;
    int actual;
    bool is_spawning;
} boss_spawning_t;

typedef struct boss_s {
    sfSprite *sp;
    sfVector2f pos;
    int pv;
    int speed;
    bool is_flying;
    int decal_texture;
    int max_decal;
    boss_spawning_t bospt;
    int total_life;
}boss_t;

typedef struct {
    int total_life;
    int red_hearth;
    int blue_hearth;
    sfSprite *h_sp;
}life;

typedef struct {
    int money;
    int bomb;
    int key;
}inventory;

typedef struct {
    int speed;
    int shot_speed;
    int damages;
    int freq_tears;
    int luck;
}stats;

typedef struct {
    bool key_q;
    bool key_z;
    bool key_s;
    bool key_d;
    bool key_left;
    bool key_up;
    bool key_right;
    bool key_down;
}event_key;

typedef struct player_s{
    event_key player_key;
    sfSprite *sp;
    sfTexture *tx;
    life lf;
    inventory invent;
    stats st;
    int x;
    int y;
    int as_moved;
    int speed;
    int actual_sp;
    int invulnerability;
    sfVector2f actual_speed;
    sfImage *collision_box;
    timer move_timer;
    timer anim_timer;
    timer tears_timer;
    sfClock *time;
}player;

typedef struct {
    sfSprite *sp;
    sfVector2f pos;
    int nb_stone;
}stone;

typedef struct {
    sfSprite *sp;
    sfIntRect pos_collision;
    int (*change)(player *py);
}collectible;

typedef struct {
    sfSprite *fo;
    sfSprite *ft;
    sfSprite *fl;
    int *actual_room;
    int len_stone;
    bool open;
    stone *st;
    sfImage *room_col;
    collectible *red_hearth;
    collectible *blue_hearth;
    collectible *piece;
    bool change_room;
}room;

typedef struct {
    sfSprite *sp;
    sfVector2f pos;
    bool is_shooting;
    bool is_flying;
    int pv;
    int speed;
}adv_t;

typedef struct boss_life_s {
    sfSprite *end_start;
    sfSprite *life_bar;
    sfUint8 *framebuffer;
    sfTexture *text_framebuffer;
    int active;
}boss_life_t;

typedef struct {
    timer ti;
    timer move_ti;
    sfClock *total_clock;
    adv_t *no_moving_adv;
    adv_t *big_adv;
    adv_t *flying_adv;
    adv_t *little_adv;
    boss_t *boss_adv;
    boss_life_t boss_life;
}enemies_t;

typedef struct {
    sfSprite *t_sp;
    sfTexture *t_tx;
    int x;
    int y;
    bool is_shot;
    bool move;
    float speed;
    int actual_sp;
    int direction;
}tears;

typedef struct {
    player *py;
    room *rm;
    tears *te;
    enemies_t *enem_t;
    rooms *ro;
}reduce;

//////// motor_s ////////

//// hud ////

// base_hud.c //
char *str_concat(char *str, char *concat);
void nb_time_hud(long time, sfRenderWindow *wd);
void nb_bomb_hud(int bomb, sfRenderWindow *wd);
void nb_key_hud(int key, sfRenderWindow *wd);
void nb_piece_hud(int piece, sfRenderWindow *wd);

// stat_hud.c //
void disp_speed(reduce *red, sfRenderWindow *wd);
void disp_freq_tears(reduce *red, sfRenderWindow *wd);
void disp_sp_tears(reduce *red, sfRenderWindow *wd);
void disp_damages(reduce *red, sfRenderWindow *wd);
void disp_luck(reduce *red, sfRenderWindow *wd);

//// moves ////

// basic_moves.c //
int check_move_right(player *py, room *rm);
int move_sp_top(player *py, int top, room *rm);

// move.c //
player *creation_player(void);
void draw_room(sfRenderWindow *wd, reduce *red, rooms *ro);
int move_sprite(player *py, int top, room *rm);
void key_action_pressed(sfEvent event, reduce *red);

// move2.c //
void move_player_check(reduce *red);
void move_event(sfEvent event, reduce *red);
room *create_room(void);

//// other ////

// int_str.c //
char *my_int_str(unsigned long long nb);
int str_len(char const *str);

// life_gestion.c //
life create_life(void);
void draw_life(player *py, sfRenderWindow *rd);
void init_player(player *py);

// reduce.c //
bool collision_stone_tears(reduce *red, int x, int y, int nb);
tears *create_tears(player *py);
void reduce_move_player_check(reduce *red);
void disp_stat_hud(reduce *red, sfRenderWindow *wd);
stats create_stats(void);

// stone_base.c //
stone *create_stone(char *str);
void place_stone(room *rm, player *py, char *str);
void draw_stone(room *rm, sfRenderWindow *wd);
bool collision_stone(room *rm, player *py, int x, int y);

//recharge_room.c //
void recharge_room(reduce *red, bool is_empty, bool is_boss);

//// tears ////

// check_tears_collision.c //
int check_collisions(int id, reduce *red, int nb);

// tears_shooting.c //
void shoot_tears(int id, reduce *red);
void move_tears(int id, reduce *red, sfRenderWindow *wd);
tears *init_st_array(tears *te, sfIntRect r, player *py);

// tears_state.c //
void disp_tears(reduce *red, sfRenderWindow *wd);
int verif_moving(reduce *red, int nb_tears);


//////// enemies ////////

// anim_enemies.c //
void anim_enemies(enemies_t *enem_t);
void reduce_init_big(int i, adv_t *adv);
void reduce_init_fly(int i, adv_t *adv);

// create_enemies.c //
enemies_t *create_enemies(void);

// enemies_room.c //
void place_enemies(char *str, enemies_t *enem_t);
void draw_enemies(enemies_t *enem_t, sfRenderWindow *wndw,
player *py, room *rm);

// mov_enemies.c //
void move_enemies(enemies_t *enem_t, player *py, room *rm);
void reduce_init_nomov(int i, adv_t *no_mov, sfVector2f scale,
sfIntRect place);

// player_enemies.c //
void touch_player_enemy(adv_t adv, sfVector2f player_pos, player *py);
void touch_player_boss(boss_t adv, sfVector2f player_pos, player *py);

// shoot_enemies.c //
bool touched_enemy(reduce *red, int i, char c);

// touch_enemy.c //7
bool touch_enemy(sfVector2f tears_pos, reduce *red);


//create_boss.c //

boss_t *create_boss(void);
void place_boss_level(enemies_t *enemy, bool final_boss);

//create_specific_boss.c //

void create_monstro_diggle(boss_t *boss);

//anim_boss //

void anim_boss_loop(enemies_t *enemy);
void draw_boss(boss_t *bst, sfRenderWindow *wd);
char *create_map_str(char *to_read);

//boss_bar.c//
void display_boss_life(enemies_t *enemy, int i, sfRenderWindow *wd);
boss_life_t create_boss_bar(void);


//////// collectibles ////////

// base_inventory.c //
collectible *create_piece(sfTexture *text);
inventory create_inventory(void);

// blue_hearth.c //
collectible *create_blue_hearth(sfTexture *text);
void got_blue_hearth(room *rm, int i, player *py);

// collectible_create.c //
void draw_bonus(room *rm, sfRenderWindow *wd, player *py);
void place_bonus(room *rm);

// red_hearth.c //
collectible *create_red_hearth(sfTexture *text);
void got_hearth(room *rm, int i, player *py);

void reduce_draw_tb(room *rm, rooms *ro, sfRenderWindow *wd, options *sprt);
void close_door(rooms *ro, options *sprt, int x, int y);
void trophy_colisions(options *sprt, room *rm, player *py);
void trap_colisions(options *sprt, room *ry, player *py);
void player_room(sfRenderWindow *wd, reduce *red, options *sprt);
void floor_pass(rooms *ro, reduce *red, options *sprt);
void doors_colisions(options *sprt, room *rm, player *py);
void init_rm_sprt(room *rm, options *sprt);
void draw_doors_topo(int lvl, options *sprt, sfRenderWindow *wd, char c);
void draw_doors_righto(int lvl, options *sprt, sfRenderWindow *wd, char c);
void draw_doors_lefto(int lvl, options *sprt, sfRenderWindow *wd, char c);
void draw_doors_boto(int lvl, options *sprt, sfRenderWindow *wd, char c);
void draw_doors_topc(int lvl, options *sprt, sfRenderWindow *wd, char c);
void draw_doors_rightc(int lvl, options *sprt, sfRenderWindow *wd, char c);
void draw_doors_leftc(int lvl, options *sprt, sfRenderWindow *wd, char c);
void draw_doors_botc(int lvl, options *sprt, sfRenderWindow *wd, char c);
void launch_piece(player *py, room *rm, int i);
int event_window(window *wndw, options *sprt, reduce *red);
void player_room(sfRenderWindow *wd, reduce *red, options *sprt);
void draw_doors(room *rm, rooms *ro, sfRenderWindow *wd, options *sprt);


#endif
