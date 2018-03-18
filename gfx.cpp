#include "gfx.h"

#include <GL/glut.h>

#include "world.h"

void update();

double get_delta_time() {
    int tNow = glutGet(GLUT_ELAPSED_TIME);
    double time_step = (double)(tNow - tThen)/1000.0;
    tThen = tNow;
    return time_step;
}

void init_gfx(int argc, char * argv[], const char * name) {

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowSize(1600, 1600);

    glutInitWindowPosition(10, 10);

    glutCreateWindow(name);

    reshape(1600, 1600);
}

void run_gfx() {
    glutMainLoop();
}

void display() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    render_world();

    glutSwapBuffers();
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
    (void)x;
    (void)y;
    switch(key) {
        case 27:
        case 'q':
            exit(0);
            break;
    }
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

void init_callbacks() {

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);
    glutIdleFunc(update);

    glClearColor(0.0, 0.0, 0.0, 0.0);

    tThen = glutGet(GLUT_ELAPSED_TIME);
}

