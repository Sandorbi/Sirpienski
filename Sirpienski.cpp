/*
 * File: Sierpinski.cpp
 
 */

#include <iostream>
#include "gwindow.h"
using namespace std;

void drawSierTriangle(int len, int ord, GWindow win, double xT, double yT);
void drawTriangles(int len, GWindow win, double x, double y);

int main() {
    GWindow win;
    int len, ord;
    cout << "Enter edge length: ";
    cin >> len;
    cout << "Enter order of Sierpinski triangle: ";
    cin >> ord;

    double topPointX = (win.getWidth() / 2);
    double topPointY = win.getHeight() / 2 - (len * sqrt(3)) / 3;

    drawSierTriangle(len, ord, win, topPointX, topPointY);

    return 0;
}

void drawTriangles(int len, GWindow win, double x, double y) {
    GPoint right = win.drawPolarLine(x, y, len, -60);
    GPoint mid = win.drawPolarLine(right, len, 180);
    win.drawPolarLine(mid, len, 60);


}

void drawSierTriangle(int len, int ord, GWindow win, double xT, double yT) {
    if (ord == 0) {
        drawTriangles(len, win, xT, yT);
        return;
    }
    else {
        drawSierTriangle(len / 2, ord - 1, win, xT, yT);
        drawSierTriangle(len / 2, ord - 1, win, xT + len / 4, yT + (len * sqrt(3)) / 4);
        drawSierTriangle(len / 2, ord - 1, win, xT - len / 4, yT + (len * sqrt(3)) / 4);
        return;
    }
}
