/*
 * MAZE Game Framework
 * Written by Dr. Dhanyu Amarasinghe Spring 2018
 */
#ifndef PLAYER_H
#define PLAYER_H

#include <CommonThings.h>
#include<string.h>
#include<gl/gl.h>
#include<GL/glut.h>
#include<SOIL.h>
#include<iostream>
#include <Timer.h>
#include <math.h>       /* ceil */
#include <vectorstuff.h>

using namespace std;

//struct GridLoc;

class Player
{
    public:
        Player();                          // Constructor
        virtual ~Player();                 // Deconstructor

        void drawplayer();                 // Draw Player image
        void drawArrow();                  // Draw Arrow
        void shootArrow();                 // Shoot arrow movement

        void initPlayer(int,int,char *);  // initialize the player with grid size, image, frames
        void placePlayer(int,int);         // place the player
        void movePlayer(char *);       // move Player left,right,up,down
        void loadArrowImage(char *);       // set an image for the Arrow

        GridLoc getPlayerLoc();            // player current location
        GridLoc getArrowLoc();             // arrow current location
        bool playerCollision(int,int);     //check if player collide with anything

        bool getIsObjectActing();
        void objectAction();
        void objectLogicAction(bool isBlockCollision);
        void setActionStatus(playerActions inpPlayAct, bool inpCanAct);

        int frames;                        // Number of frames for animation
        char *playerDir;                   // direction of player face

        bool arrowStatus;                  // arrow is active or not
        bool livePlayer;                   // Player live or dead

        GridLoc getObjCurrGridLoc();
        GridLoc getObjNewGridLoc();
        GridLoc getObjOldGridLoc();

        void setObjCurrGridLoc(GridLoc inpGridLoc);
        void setObjNewGridLoc(GridLoc inpGridLoc);
        void setObjOldGridLoc(GridLoc inpGridLoc);

        loc getObjCurrRealLoc();
        loc getObjNewRealLoc();
        loc getObjOldRealLoc();

        void setObjCurrRealLoc(loc inpRealLoc);
        void setObjNewRealLoc(loc inpRealLoc);
        void setObjOldRealLoc(loc inpRealLoc);

    protected:

        float t;                           // Ticker for animation
        void timer();                      // Timer for animation
        int gridSize;                      // Grid Size
        float unitWidth;                   // Unit width of the grid

    private:

    private:
        float xmax, xmin,ymax,ymin;        // animation texture map
        GLuint plyTex;                     // player image handler
        GLuint arrowTex;                   // arrow image handler
        int arrXdir;                       // arrow direction x;
        int arrYdir;                       // arrow direction y
        float arrAngle;                    // animation direction of the arrow
        loc arrowLoc;                      // viewport location of the arrow
        loc plyLoc;                        // viewport location of the player
        loc converter(int, int);           // convert Grid location to viewport
        int stepsPerMove;                  // animation steps

        Timer *objectTimer;
        int objectDirectionFaced;
        bool isObjectActing;
        bool canObjectAct;
        playerActions classPlayerActions;

        bool collision;

        GridLoc objCurrGridLoc;
        GridLoc objNewGridLoc;
        GridLoc objOldGridLoc;

        loc objOldRealLoc;
        loc objNewRealLoc;

};

#endif // PLAYER_H
