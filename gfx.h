#ifndef GFX_H_
#define GFX_H_

double get_delta_time();
void init_gfx(int argc, char * argv[], const char * name);
void run_gfx();
void display();
void keyboard(unsigned char key, int x, int y);
void reshape(int w, int h);
void init_callbacks();

extern int tThen;
#endif // GFX_H_

