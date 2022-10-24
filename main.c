#include <GL/gl.h>
#include <GL/glu.h>
#include <GLFW/glfw3.h>

int main() {
    if (!glfwInit()) {
        return 1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 1);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    GLFWwindow* wnd = glfwCreateWindow(800, 600, "Early Days", NULL, NULL);
    if (!wnd) {
        return 1;
    }

    glfwMakeContextCurrent(wnd);

    glEnable(GL_DEPTH_TEST);

    float x = 0.0;
    float y = 0.0;

    while (!glfwWindowShouldClose(wnd)) {
        glfwPollEvents();

        // update
        if (glfwGetKey(wnd, GLFW_KEY_UP) == GLFW_PRESS) {
            y += 0.05;
        }
        if (glfwGetKey(wnd, GLFW_KEY_DOWN) == GLFW_PRESS) {
            y -= 0.05;
        }
        if (glfwGetKey(wnd, GLFW_KEY_LEFT) == GLFW_PRESS) {
            x += 0.05;
        }
        if (glfwGetKey(wnd, GLFW_KEY_RIGHT) == GLFW_PRESS) {
            x -= 0.05;
        }

        // draw
        int w, h;
        glfwGetFramebufferSize(wnd, &w, &h);

        // TODO : only do this on resize
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(45.0, (float) w / h, 0.5, 100.0);
        glMatrixMode(GL_MODELVIEW);

        glViewport(0, 0, w, h);

        glClearColor(0, 0, 0, 0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // position the camera
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glLoadIdentity();
        glTranslatef(0.0, 0.0,-5.0);
        glRotatef(45.0, 1.0, 0.0, 0.0);
        glRotatef(180.0, 0.0, 1.0, 0.0);

        // character
        glBegin(GL_TRIANGLES);
            glColor3f(0.1, 0.5, 0.8);

            glVertex3f( 0.0, 1.0, 0.0);
            glVertex3f( 0.2, 0.0, 0.2);
            glVertex3f( 0.2, 0.0,-0.2);

            glVertex3f( 0.0, 1.0, 0.0);
            glVertex3f(-0.2, 0.0, 0.2);
            glVertex3f(-0.2, 0.0,-0.2);

            glVertex3f( 0.0, 1.0, 0.0);
            glVertex3f( 0.2, 0.0, 0.2);
            glVertex3f(-0.2, 0.0, 0.2);

            glVertex3f( 0.0, 1.0, 0.0);
            glVertex3f( 0.2, 0.0,-0.2);
            glVertex3f(-0.2, 0.0,-0.2);
        glEnd();

        // camera transform
        glTranslatef(-x, 0, -y);

        glBegin(GL_TRIANGLES);
            // starting room
            glColor3f(0.9, 0.4, 0.3);
            glVertex3f(0.0, 0.0, 0.0);
            glColor3f(0.3, 0.3, 0.3);
            glVertex3f(1.0, 0.0, 1.0);
            glVertex3f(1.0, 0.0,-1.0);

            glColor3f(0.9, 0.4, 0.3);
            glVertex3f(0.0, 0.0, 0.0);
            glColor3f(0.3, 0.3, 0.3);
            glVertex3f(-1.0, 0.0, 1.0);
            glVertex3f(-1.0, 0.0,-1.0);

            glColor3f(0.9, 0.4, 0.3);
            glVertex3f(0.0, 0.0, 0.0);
            glColor3f(0.3, 0.3, 0.3);
            glVertex3f( 1.0, 0.0, 1.0);
            glVertex3f(-1.0, 0.0, 1.0);

            glColor3f(0.9, 0.4, 0.3);
            glVertex3f(0.0, 0.0, 0.0);
            glColor3f(0.3, 0.3, 0.3);
            glVertex3f( 1.0, 0.0,-1.0);
            glVertex3f(-1.0, 0.0,-1.0);

            // corridor
            glColor3f(0.1, 0.1, 0.1);
            glVertex3f( 0.5, 0.0, 2.0);
            glColor3f(0.3, 0.3, 0.3);
            glVertex3f( 0.5, 0.0, 1.0);
            glVertex3f(-0.5, 0.0, 1.0);

            glColor3f(0.1, 0.1, 0.1);
            glVertex3f( 0.5, 0.0, 2.0);
            glVertex3f(-0.5, 0.0, 2.0);
            glColor3f(0.3, 0.3, 0.3);
            glVertex3f(-0.5, 0.0, 1.0);

            glColor3f(0.1, 0.1, 0.1);
            glVertex3f( 0.5, 0.0, 2.0);
            glColor3f(0.3, 0.3, 0.3);
            glVertex3f( 0.5, 0.0, 3.0);
            glVertex3f(-0.5, 0.0, 3.0);

            glColor3f(0.1, 0.1, 0.1);
            glVertex3f( 0.5, 0.0, 2.0);
            glVertex3f(-0.5, 0.0, 2.0);
            glColor3f(0.3, 0.3, 0.3);
            glVertex3f(-0.5, 0.0, 3.0);

            // T-Junction
            glColor3f(0.9, 0.4, 0.3);
            glVertex3f(0.0, 0.0, 3.5);
            glColor3f(0.3, 0.3, 0.3);
            glVertex3f(0.5, 0.0, 3.0);
            glVertex3f(0.5, 0.0, 4.0);

            glColor3f(0.9, 0.4, 0.3);
            glVertex3f(0.0, 0.0, 3.5);
            glColor3f(0.3, 0.3, 0.3);
            glVertex3f(-0.5, 0.0, 3.0);
            glVertex3f(-0.5, 0.0, 4.0);

            glColor3f(0.9, 0.4, 0.3);
            glVertex3f(0.0, 0.0, 3.5);
            glColor3f(0.3, 0.3, 0.3);
            glVertex3f( 0.5, 0.0, 3.0);
            glVertex3f(-0.5, 0.0, 3.0);

            glColor3f(0.9, 0.4, 0.3);
            glVertex3f(0.0, 0.0, 3.5);
            glColor3f(0.3, 0.3, 0.3);
            glVertex3f( 0.5, 0.0, 4.0);
            glVertex3f(-0.5, 0.0, 4.0);

            // left
            glColor3f(0.1, 0.1, 0.1);
            glVertex3f( 2.0, 0.0, 3.0);
            glColor3f(0.3, 0.3, 0.3);
            glVertex3f( 0.5, 0.0, 3.0);
            glVertex3f( 0.5, 0.0, 4.0);

            glColor3f(0.1, 0.1, 0.1);
            glVertex3f( 2.0, 0.0, 3.0);
            glVertex3f( 2.0, 0.0, 4.0);
            glColor3f(0.3, 0.3, 0.3);
            glVertex3f( 0.5, 0.0, 4.0);

            // right
            glColor3f(0.1, 0.1, 0.1);
            glVertex3f(-2.0, 0.0, 3.0);
            glColor3f(0.3, 0.3, 0.3);
            glVertex3f(-0.5, 0.0, 3.0);
            glVertex3f(-0.5, 0.0, 4.0);

            glColor3f(0.1, 0.1, 0.1);
            glVertex3f(-2.0, 0.0, 3.0);
            glVertex3f(-2.0, 0.0, 4.0);
            glColor3f(0.3, 0.3, 0.3);
            glVertex3f(-0.5, 0.0, 4.0);
        glEnd();

        glPopMatrix();

        glfwSwapBuffers(wnd);
    }

    glfwDestroyWindow(wnd);
    glfwTerminate();
    return 0;
}