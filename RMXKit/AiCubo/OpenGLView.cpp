//
//  OpenGLView.cpp
//  RMXKit
//
//  Created by Max Bilbow on 29/07/2015.
//  Copyright © 2015 Rattle Media Ltd. All rights reserved.
//

#include <iostream>
#import <OpenGL/OpenGL.h>
#import <GLUT/glut.h>
#include "OpenGLView.hpp"

#define FULL_SCREEN 0

using namespace std;
void Display() {
    
    
}

void LoadView(void)
{
    //    int width, height;
    //    int nComponents;
    //    void* pTextureImage;
    
    
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    //glEnable(GL_LIGHT1);
    // Create texture for cube; load marble texture from file and bind it
    //pTextureImage = read_texture("marble.rgb", &width, &height, &nComponents);
//    glBindTexture(GL_TEXTURE_2D, TEXTURE_ID_CUBE);
    
    glGenerateMipmap(GL_MAP1_NORMAL);
    //    gluBuild2DMipmaps(GL_TEXTURE_2D,     // texture to specify
    //                      GL_RGBA,           // internal texture storage format
    //                      width,             // texture width
    //                      height,            // texture height
    //                      GL_RGBA,           // pixel format
    //                      GL_UNSIGNED_BYTE,	// color component format
    //                      pTextureImage);    // pointer to texture image
    glTexParameterf (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                     GL_LINEAR_MIPMAP_LINEAR);
    glTexEnvf (GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
//    DrawFog(true);
}



void reshape(int w, int h) {

}

void keyPressed (unsigned char key, int x, int y){
//    RMXkeyPressed(key, x, y);
}
void keyUp (unsigned char key, int x, int y){
//    RMXkeyUp(key, x, y);
}
void keySpecial (int key, int x, int y){
//    RMXkeySpecial(key, x, y);
}
void keySpecialUp (int key, int x, int y){
//    RMXkeySpecialUp(key, x, y);
}

void mouseButton(int button, int state, int x, int y){
//    MouseButton(button, state, x, y);
}
void mouseMotion(int x, int y){
//    MouseMotion(x, y);
}
void mouseFree(int x, int y){
//    MouseFree(x, y);
}

void idle(){
//    [RMXGLProxy animateScene];
}


//#ifdef RMX_USE_DEPRECIATED

int RMXGLRun(int argc, char * argv[])
{
    
//    RMXGlutInit(argc,argv);
//    initKeys();
    
    
    glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH );
    
    
    if (FULL_SCREEN){//&&glutGameModeGet(GLUT_GAME_MODE_POSSIBLE)){
        glutEnterGameMode();
    }else {
        cout << "Game Mode Not Possibe" << endl;
//        glutMakeWindow(100,100,1280,720,"AiCubo");
    }
    //Setup Display:
    glutDisplayFunc(Display);
    glutReshapeFunc(reshape);
    
    // Register callbacks:
    glutKeyboardFunc(keyPressed);
    glutKeyboardUpFunc(keyUp);
    glutSpecialFunc(keySpecial);
    glutSpecialUpFunc(keySpecialUp);
    
    glutMouseFunc(mouseButton);
    glutMotionFunc(mouseMotion);
    glutPassiveMotionFunc(mouseFree);
    
    //Animation
    glutIdleFunc(idle);
    
    LoadView();
    
    
    if (FULL_SCREEN) {
//        [RMXGLProxy performAction:@"toggleMouseLock"];

    }
    glutMainLoop();
    return 0;
}
